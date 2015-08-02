//
//  Species.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#include "Species.h"
#include "cocos2d.h"
USING_NS_CC;

rapidjson::Document Species::document;
bool Species::hasJson = false;

Species::Species(std::string name) :
_moveCsbName("AnimalMove1.csb"),
_maxHeight(0),
_minHeight(0),
_speed(0),
_dashSpeed(0)
{
    if (hasJson == false) {
        auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/animal.json");
        Species::document.Parse<0>(jsonStr.c_str());
        hasJson = true;
    }
    rapidjson::Value& speceisDoc = Species::document[name.c_str()];
    init(name, speceisDoc);
}

Species::Species(std::string name, rapidjson::Value& json) :
_moveCsbName("AnimalMove1.csb"),
_maxHeight(0),
_minHeight(0),
_speed(0),
_dashSpeed(0)
{
    init(name, json);
}

void Species::init(std::string name, rapidjson::Value& json)
{
    UnitOfLength unit = Length::toUnit(json["unit"].GetString());
    _name = name;
    _maxHeight = Length(unit, (float)json["maxHeight"].GetDouble());
    _minHeight = Length(unit, (float)json["minHeight"].GetDouble());
    _speed = Length(unit, (float)json["speed"].GetDouble());
    _imageName = json["image"].GetString();
    if (json["move"].IsNull() == false) {
        _move = json["move"].GetBool();
    }
    if (json["dash"].IsNull()) {
        _dashSpeed = Length(UnitOfLength::mm, _speed.getMmLength() * 2);
    } else {
        _dashSpeed = Length(unit, (float)json["dash"].GetDouble());
    }
}

std::string Species::getName()
{
    return _name;
}

Length Species::getMaxHeight()
{
    return _maxHeight;
}

Length Species::getMinHeight()
{
    return _minHeight;
}

Length Species::getAverageHeight()
{
    return Length(_minHeight.getMmLength() + _maxHeight.getMmLength() / 2);
}

Length Species::getSpeed()
{
    return _speed;
}

Length Species::getDashSpeed()
{
    return _dashSpeed;
}

std::string Species::getImageName()
{
    return StringUtils::format("animal/%s01.png", _imageName.c_str());
}

std::string Species::getBackImageName()
{
    return StringUtils::format("animal/%s02.png", _imageName.c_str());
}

std::string Species::getMoveCsbName()
{
    return _moveCsbName;
}

bool Species::isMove()
{
    return _move;
}

std::vector<Species*> Species::getAllSpecies()
{
    std::vector<Species*> rtnList;

    if (hasJson == false) {
        auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/animal.json");
        Species::document.Parse<0>(jsonStr.c_str());
        hasJson = true;
    }
    for (rapidjson::Value::ConstMemberIterator itr = Species::document.MemberonBegin();
        itr != Species::document.MemberonEnd(); ++itr)
    {
        auto name = itr->name.GetString();
        auto species = new Species(name, Species::document[name]);
        rtnList.push_back(species);
    }

    return rtnList;
}

