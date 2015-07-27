//
//  WorldInfo.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#include "WorldInfo.h"
#include "cocos2d.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

USING_NS_CC;

WorldInfo::WorldInfo(int level)
{
    lotteryGachaCount = 0;
    totalLotteryGachaCount = 0;
    this->level = level;
    network = false;
    _loadLevel();
}

WorldInfo::~WorldInfo()
{
}

WorldInfo* WorldInfo::copy()
{
    auto copy = new WorldInfo(this->level);
    copy->lotteryGachaCount = this->lotteryGachaCount;
    copy->totalLotteryGachaCount = this->totalLotteryGachaCount;
    copy->network = this->network;
    return copy;
}

void WorldInfo::levelUp()
{
    this->level++;
    this->lotteryGachaCount = 0;
    _loadLevel();
}

void WorldInfo::addLotteryGachaCount()
{
    lotteryGachaCount++;
    totalLotteryGachaCount++;
}

void WorldInfo::_loadLevel()
{
    auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/world.json");
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    rapidjson::Value& worldDoc = document[std::to_string(level).c_str()];
    std::string unit = worldDoc["unit"].GetString();
    float value = (float)worldDoc["value"].GetDouble();
    float maxValue = (float)worldDoc["maxValue"].GetDouble();
    this->width = new Length(Length::toUnit(unit), value);
    this->maxWidth = new Length(Length::toUnit(unit), maxValue);
    this->mapName = worldDoc["map"].GetString();
    this->gachaId = worldDoc["gacha"].GetInt();
    this->imageWidth = worldDoc["imageWidth"].GetInt();
}
