//
//  UserData.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/14.
//
//

#include "UserData.h"

static int COIN_INT_MAX = 1000000000;

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
        CCLOG("Save Success");
        return true;
    }else{
        CCLOG("Save Failed");
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

bool UserData::isEndTutorial()
{
    if (_data.find("end_tutorial") == _data.end()) {
        return false;
    } else {
        return _data["end_tutorial"].asBool();
    }
}

ValueMap UserData::getWorldInfo()
{
    if (_data.find("world_info") == _data.end()) {
        auto initData = ValueMap();
        initData["level"] = INIT_WORLD_LEVEL;
        initData["gacha_count"] = 0;
        initData["total_gacha_count"] = 0;
        _data["world_info"] = initData;
        return initData;
    } else {
        return _data["world_info"].asValueMap();
    }
}

long int UserData::getCoin()
{
    if (_data.find("coin") == _data.end()) {
        return INIT_COIN;
    } else {
        auto coin = (long int)_data["coin_top"].asInt() * COIN_INT_MAX +  _data["coin"].asInt();
        return coin;
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
    if (_data.find("animal_data") == _data.end()) {
        return ValueVector();
    } else {
        return _data["animal_data"].asValueVector();
    }
}

LanguageType UserData::getLanguage()
{
    if (_data.find("language") == _data.end()) {
        return CCApplication::getInstance()->getCurrentLanguage();
    } else {
        return (LanguageType)_data["language"].asInt();
    }
}

#pragma - setter

void UserData::setEndTutorial(bool endTutorial)
{
    _data["end_tutorial"] = endTutorial;
}

void UserData::setWorldInfo(ValueMap info)
{
    _data["world_info"] = info;
}

void UserData::setCoin(long int coin)
{
    _data["coin"] = (int)(coin % COIN_INT_MAX);
    _data["coin_top"] = (int)(coin / COIN_INT_MAX);
}

void UserData::setLifeData(ValueMap lifeData)
{
    _data["life_data"] = lifeData;
}

void UserData::setAnimalList(ValueVector animal)
{
    _data["animal_data"] = animal;
}

void UserData::setLanguage(LanguageType language)
{
    _data["language"] = (int)language;
}


std::string UserData::getFilePath()
{
    return FileUtils::getInstance()->getWritablePath() + "user_data";
}
