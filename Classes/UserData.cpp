//
//  UserData.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/14.
//
//

#include "UserData.h"

bool UserData::init()
{
    _data = ValueMap();
    return save();
}

bool UserData::save()
{   //保存箇所のフルパスを取得
    std::string path = UserData::getFilePath();
    
    // 保存
    if(FileUtils::getInstance()->writeToFile(_data, path)){
        CCLOG("save Success:%s", path.c_str());
        return true;
    }else{
        CCLOG("save Failed:%s", path.c_str());
        return false;
    }
}

UserData* UserData::load()
{
    UserData* result = new UserData();
    auto path = UserData::getFilePath();
    if (FileUtils::getInstance()->isFileExist(path) == false) {
        result->init();
    }
    result->_data = FileUtils::getInstance()->getValueMapFromFile(path);
    return result;
}

#pragma - getter

int UserData::getWorldLevel()
{
    if (_data.find("world_level") == _data.end()) {
        return INIT_WORLD_LEVEL;
    } else {
        return _data["world_level"].asInt();
    }
}

int UserData::getCoin()
{
    if (_data.find("coin") == _data.end()) {
        return INIT_COIN;
    } else {
        return _data["coin"].asInt();
    }
}

ValueMap UserData::getLifeData()
{
    if (_data.find("life_data") == _data.end()) {
        auto initData = ValueMap();
        initData["current_life"] = INIT_LIFE;
        initData["max_life"] = INIT_LIFE;
        initData["last_time"] = (int)time(NULL);
        _data["life_data"] = initData;
        save();
        return initData;
    } else {
        ValueMap lifeData = _data["life_data"].asValueMap();
        return lifeData;
    }
}

ValueVector UserData::getAnimalList()
{
}

#pragma - setter

void UserData::setWorldLevel(int level)
{
    _data["world_level"] = level;
}

void UserData::setCoin(int coin)
{
    _data["coin"] = coin;
}

void UserData::setLifeData(ValueMap lifeData)
{
    _data["life_data"] = lifeData;
}

void UserData::setAnimalList(ValueVector animal)
{
}

std::string UserData::getFilePath()
{
    return FileUtils::getInstance()->getWritablePath() + "user_data";
}

