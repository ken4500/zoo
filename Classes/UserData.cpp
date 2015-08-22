//
//  UserData.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/14.
//
//

#include "UserData.h"
#include "ShopData.h"

static int COIN_INT_MAX = 1000000000;

bool UserData::init()
{
    _data = ValueMap();
    save();
    return  true;
}

void UserData::save()
{
    Director::getInstance()->getScheduler()->unschedule("save_user_data", this);
    Director::getInstance()->getScheduler()->schedule(CC_CALLBACK_1(UserData::_save, this), this, 1.0f, false, "save_user_data");
}

UserData* UserData::load()
{
    UserData* result = new UserData();
    auto path = UserData::_getFilePath();
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

ValueMap UserData::getStoryData()
{
    if (_data.find("story_data") == _data.end()) {
        auto initData = ValueMap();
        return initData;
    } else {
        return _data["story_data"].asValueMap();
    }
}

ValueMap UserData::getWorldInfo()
{
    if (_data.find("world_info") == _data.end()) {
        auto initData = ValueMap();

        initData["level"]             = INIT_WORLD_LEVEL;
        initData["gacha_count"]       = 0;
        initData["total_gacha_count"] = 0;

        _data["world_info"] = initData;
        return initData;
    } else {
        return _data["world_info"].asValueMap();
    }
}

long long int UserData::getCoin()
{
    if (_data.find("coin") == _data.end()) {
        return INIT_COIN;
    } else {
        auto coin = (long long int)_data["coin_top"].asInt() * COIN_INT_MAX +  _data["coin"].asInt();
        return coin;
    }
}

ValueMap UserData::getLifeData()
{
    if (_data.find("life_data") == _data.end()) {
        auto initData = ValueMap();

        initData["current_life"] = INIT_LIFE;
        initData["last_time"]    = (int)time(NULL);

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
    LanguageType lang;
    if (_data.find("language") == _data.end()) {
        lang = CCApplication::getInstance()->getCurrentLanguage();
    } else {
       lang = (LanguageType)_data["language"].asInt();
    }

    return lang;
}

ValueMap UserData::getAnimalDataList()
{
    if (_data.find("animal_get_data") == _data.end()) {
        auto initData = ValueMap();
        _data["animal_get_data"] = initData;
        return initData;
    } else {
        return _data["animal_get_data"].asValueMap();
    }
}

int UserData::getDiamondNum()
{
    if (_data.find("diamond_num") == _data.end()) {
        return 0;
    } else {
        return _data["diamond_num"].asInt();
    }
}

ValueMap UserData::getShopData()
{
    if (_data.find("shop_data") == _data.end()) {
        auto initData = ValueMap();
        auto allType = ShopData::getAllType();
        for (auto type : allType) {
            auto key = ShopData::toString(type);
            initData[key] = 0;
        }
        _data["shop_data"] = initData;
        return initData;
    } else {
        return _data["shop_data"].asValueMap();
    }
}

bool UserData::isReviewed()
{
    if (_data.find("is_reviewed") == _data.end()) {
        return false;
    } else {
        return _data["is_reviewed"].asBool();
    }
}

#pragma - setter

void UserData::setEndTutorial(bool endTutorial)
{
    _data["end_tutorial"] = endTutorial;
}

void UserData::setStroyData(ValueMap storyData)
{
    _data["story_data"] = storyData;
}

void UserData::setWorldInfo(ValueMap info)
{
    _data["world_info"] = info;
}

void UserData::setCoin(long long int coin)
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

void UserData::setAnimalDataList(ValueMap getAnimalData)
{
    _data["animal_get_data"] = getAnimalData;
}

void UserData::setDiamondNum(int diamondNum)
{
    _data["diamond_num"] = diamondNum;
}

void UserData::setShopData(ValueMap shopData)
{
    _data["shop_data"] = shopData;
}

void UserData::setIsReviewed(bool reviewed)
{
    _data["is_reviewed"] = reviewed;
}

#pragma - private method

std::string UserData::_getFilePath()
{
    return FileUtils::getInstance()->getWritablePath() + "user_data_0808";
}

void UserData::_save(float dt)
{
    Director::getInstance()->getScheduler()->unschedule("save_user_data", this);

    //保存箇所のフルパスを取得
    std::string path = UserData::_getFilePath();
    
    // 保存
    if(FileUtils::getInstance()->writeToFile(_data, path)){
        CCLOG("Save Success");
    }else{
        CCLOG("Save Failed");
    }
}
