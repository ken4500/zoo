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
using namespace cocos2d;

namespace JSONPacker 
{
    std::string packCommandData(CommandData command)
    {
        rapidjson::Document document;
        document.SetObject();

        document.AddMember("c",  command.commandName.c_str(), document.GetAllocator());
        document.AddMember("t",  command.time, document.GetAllocator());
        
        rapidjson::Value numList(rapidjson::kArrayType);
        for (float number : command.numberDataList) {
            numList.PushBack(number, document.GetAllocator());
        }
        
        rapidjson::Value stringList(rapidjson::kArrayType);
        for (std::string str : command.stringDataList) {
            stringList.PushBack(str.c_str(), document.GetAllocator());
        }

        rapidjson::Value intList(rapidjson::kArrayType);
        for (int i : command.intDataList) {
            intList.PushBack(i, document.GetAllocator());
        }
        
        document.AddMember("nl", numList, document.GetAllocator());
        document.AddMember("sl", stringList, document.GetAllocator());
        document.AddMember("il", intList, document.GetAllocator());
        
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);
        
        return std::string(buffer.GetString(), buffer.Size());
    }
    
    CommandData unpackCommandDataJSON(std::string json)
    {
        rapidjson::Document document;
        document.Parse<0>(json.c_str());

        CommandData result;
        result.commandName  = document["c"].GetString();
        result.time         = document["t"].GetDouble();

        result.numberDataList = std::vector<float>();
        rapidjson::Value& listDoc = document["nl"];
        for (int i = 0; i < listDoc.Size(); i++) {
            result.numberDataList.push_back(listDoc[i].GetDouble());
        }

        result.stringDataList = std::vector<std::string>();
        listDoc = document["sl"];
        CCLOG("#####json = %s", json.c_str());
        CCLOG("#####command = %s", result.commandName.c_str());
        CCLOG("#####size = %d", listDoc.Size());
        for (int i = 0; i < listDoc.Size(); i++) {
            result.stringDataList.push_back(listDoc[i].GetString());
        }

        result.intDataList = std::vector<int>();
        listDoc = document["il"];
        for (int i = 0; i < listDoc.Size(); i++) {
            result.intDataList.push_back(listDoc[i].GetInt());
        }
        
        return result;
    }

}
