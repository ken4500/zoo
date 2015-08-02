//
//  JSONPacker.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/28.
//
//

#include "JSONPacker.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include <stdio.h>
using namespace cocos2d;

namespace JSONPacker 
{
    std::string packCommandData(CommandData command)
    {
        std::vector<CommandData> commandList;
        commandList.push_back(command);
        return packCommandData(commandList);
    }

    std::string packCommandData(std::vector<CommandData> commandList)
    {
        rapidjson::Document document;
        document.SetArray();
        
        for (auto command : commandList) {
            rapidjson::Value commandDoc(rapidjson::kObjectType);

            auto commandName = new std::string(command.commandName);
            commandDoc.AddMember("c",  commandName->c_str(), document.GetAllocator());
            commandDoc.AddMember("t",  command.time, document.GetAllocator());
            
            rapidjson::Value numList(rapidjson::kArrayType);
            for (float number : command.numberDataList) {
                numList.PushBack(number, document.GetAllocator());
            }
            
            rapidjson::Value stringList(rapidjson::kArrayType);
            for (std::string str : command.stringDataList) {
                auto copy = new std::string(str);
                stringList.PushBack(copy->c_str(), document.GetAllocator());
            }

            rapidjson::Value intList(rapidjson::kArrayType);
            for (int i : command.intDataList) {
                intList.PushBack(i, document.GetAllocator());
            }
            
            commandDoc.AddMember("nl", numList, document.GetAllocator());
            commandDoc.AddMember("sl", stringList, document.GetAllocator());
            commandDoc.AddMember("il", intList, document.GetAllocator());

            document.PushBack(commandDoc, document.GetAllocator());
        }

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);
        
        return std::string(buffer.GetString(), buffer.Size());
    }

    
    std::vector<CommandData> unpackCommandDataJSON(std::string json)
    {
        std::vector<CommandData> commandList;
    
        rapidjson::Document document;
        document.Parse<0>(json.c_str());

        for (int i = 0; i < document.Size(); i++) {
            rapidjson::Value& commandDoc = document[i];
            CommandData command;
            
            command.commandName  = commandDoc["c"].GetString();
            command.time         = commandDoc["t"].GetDouble();

            command.numberDataList = std::vector<float>();
            rapidjson::Value& listDoc = commandDoc["nl"];
            for (int i = 0; i < listDoc.Size(); i++) {
                command.numberDataList.push_back(listDoc[i].GetDouble());
            }

            command.stringDataList = std::vector<std::string>();
            listDoc = commandDoc["sl"];
            for (int i = 0; i < listDoc.Size(); i++) {
                command.stringDataList.push_back(listDoc[i].GetString());
            }

            command.intDataList = std::vector<int>();
            listDoc = commandDoc["il"];
            for (int i = 0; i < listDoc.Size(); i++) {
                command.intDataList.push_back(listDoc[i].GetInt());
            }

            commandList.push_back(command);
        }

        return commandList;
    }

}
