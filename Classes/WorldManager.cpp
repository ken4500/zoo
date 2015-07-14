//
//  WorldManager.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#include "WorldManager.h"

USING_NS_CC;

static WorldManager* sharedWorldManager;
WorldManager* WorldManager::getInstance()
{
    if (!sharedWorldManager) {
        sharedWorldManager = new WorldManager();
    }

    return sharedWorldManager;
}

#pragma mark - Constructor and Destructor

WorldManager::WorldManager()
{
    _level = 1;
    _info = _loadWoldInfo(_level);
    _map = nullptr;
    
}

WorldManager::~WorldManager()
{
}


#pragma - getter / setter

int WorldManager::getGachaId()
{
    return _info->gachaId;
}

WorldInfo* WorldManager::getWorldInfo()
{
    return _info;
}

WorldMap* WorldManager::getMap()
{
    if (_map == nullptr) {
        _map = dynamic_cast<WorldMap*>(CSLoader::createNode(_info->mapName));
        _map->initSize(_info->maxWidth, _info->width);
    }
    return _map;
}

float WorldManager::getImageScale(Sprite* image, Length* heightLength)
{
    auto worldSize = getWorldInfo()->width;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto contentSize = image->getContentSize();
    float scale = (heightLength->getLength(UnitOfLength::mm) * visibleSize.width) / (worldSize->getLength(UnitOfLength::mm) * contentSize.width);
    return scale;

}

float WorldManager::getDisplayLength(Length* length)
{
    auto worldSize = getWorldInfo()->width;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    return (length->getLength(UnitOfLength::mm) * visibleSize.width) / worldSize->getLength(UnitOfLength::mm);
}

Length* WorldManager::getLength(float displayLength)
{
    auto worldSize = getWorldInfo()->width;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float mm = worldSize->getLength(UnitOfLength::mm) * displayLength / visibleSize.width;
    return new Length(UnitOfLength::mm, mm);
}

#pragma - public method

WorldInfo* WorldManager::levelup()
{
    _level++;
    auto newWorldInfo = _loadWoldInfo(_level);
    if (newWorldInfo->mapName == _info->mapName) {
        _map->setCurrentWidth(newWorldInfo->width);
    } else {
        
        
    }
    
    _info = newWorldInfo;
    return _info;
}

#pragma - private method

WorldInfo* WorldManager::_loadWoldInfo(int level)
{
    WorldInfo* info = new WorldInfo();
    auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/world.json");
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    rapidjson::Value& worldDoc = document[std::to_string(_level).c_str()];
    std::string unit = worldDoc["unit"].GetString();
    float value = (float)worldDoc["value"].GetDouble();
    float maxValue = (float)worldDoc["maxValue"].GetDouble();
    info->width = new Length(Length::toUnit(unit), value);
    info->maxWidth = new Length(Length::toUnit(unit), maxValue);
    info->mapName = worldDoc["map"].GetString();
    info->gachaId = worldDoc["gacha"].GetInt();
    
    return info;
}

