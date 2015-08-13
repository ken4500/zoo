//
//  ShopData.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/10.
//
//

#include "ShopData.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

std::map<std::string, ShopLineup> ShopData::toTypeMap = {
    {"offenseUp"  , ShopLineup::OFFESE_UP},
    {"animalNum"  , ShopLineup::ANIMAL_NUM},
    {"getCoin"    , ShopLineup::GET_COIN},
    {"spawnNum"   , ShopLineup::SPAWN_NUM},
    {"emergeEnemy", ShopLineup::EMERGE_ENEMY},
    {"maxLife"    , ShopLineup::MAX_LIFE},
};

std::map<ShopLineup, std::string> ShopData::toStringMap = {
    {ShopLineup::OFFESE_UP    , "offenseUp"},
    {ShopLineup::ANIMAL_NUM   , "animalNum"},
    {ShopLineup::GET_COIN     , "getCoin"},
    {ShopLineup::SPAWN_NUM    , "spawnNum"},
    {ShopLineup::EMERGE_ENEMY , "emergeEnemy"},
    {ShopLineup::MAX_LIFE     , "maxLife"},
};

std::string ShopData::toString(ShopLineup lineup)
{
    return ShopData::toStringMap[lineup];
}

ShopLineup ShopData::toType(std::string str)
{
    return ShopData::toTypeMap[str];
}

std::vector<ShopLineup> ShopData::getAllType()
{
    std::vector<ShopLineup> rtn;
    for (ShopLineup type = ShopLineup::OFFESE_UP; type != ShopLineup::COUNT; type = (ShopLineup)((int)type + 1)) {
        rtn.push_back(type);
    }
    return rtn;
}


static ShopData* sharedInstance;
ShopData* ShopData::getInstance()
{
    if (!sharedInstance) {
        sharedInstance = new ShopData();
    }

    return sharedInstance;
}

ShopData::ShopData()
{
    std::string fileName = "data/shop.json";
    auto jsonStr = FileUtils::getInstance()->getStringFromFile(fileName);
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    
    for (int i = 0; i < (int)ShopLineup::COUNT; i++) {
        _maxLevelList[i] = 0;
    }
    
    for (rapidjson::Value::ConstMemberIterator itr = document.MemberonBegin();
        itr != document.MemberonEnd(); ++itr)
    {
        auto typeStr = itr->name.GetString();
        int type = (int)toType(typeStr);
        rapidjson::Value& dataListDocument = document[typeStr];
        for (rapidjson::Value::ConstMemberIterator itr2 = dataListDocument.MemberonBegin();
            itr2 != dataListDocument.MemberonEnd(); ++itr2)
        {
            int level = std::stoi(itr2->name.GetString());
            _maxLevelList[type] = MAX(_maxLevelList[type], level);
            _priceList[type].push_back(itr2->value["price"].GetInt());
            _valueList[type].push_back(itr2->value["value"].GetDouble());
        }
    }    
}

ShopData::~ShopData()
{
}

int ShopData::getMaxLevel(ShopLineup lineup)
{
    return _maxLevelList[(int)lineup];
}

int ShopData::getPrice(ShopLineup lineup, int level)
{
    return _priceList[(int)lineup][level];
}

float ShopData::getValue(ShopLineup lineup, int level)
{
    return _valueList[(int)lineup][level];
}
