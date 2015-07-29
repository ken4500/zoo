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
        
        document.AddMember("nl", numList, document.GetAllocator());
        document.AddMember("sl", stringList, document.GetAllocator());
        
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

        auto numberList = std::vector<float>();
        rapidjson::Value& listDoc = document["nl"];
        for (int i = 0; i < listDoc.Size(); i++) {
            numberList.push_back(listDoc[i].GetDouble());
        }
        result.numberDataList = numberList;

        auto stringList = std::vector<std::string>();
        listDoc = document["sl"];
        for (int i = 0; i < listDoc.Size(); i++) {
            stringList.push_back(listDoc[i].GetString());
        }
        result.stringDataList = stringList;
        
        return result;
    }

}
