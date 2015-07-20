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

Species::Species(std::string name) :
_moveCsbName("AnimalMove1.csb")
{
    auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/animal.json");
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    rapidjson::Value& speceisDoc = document[name.c_str()];
    init(name, speceisDoc);
}

Species::Species(std::string name, rapidjson::Value& json) :
_moveCsbName("AnimalMove1.csb")
{
    init(name, json);
}

void Species::init(std::string name, rapidjson::Value& json)
{
    UnitOfLength unit = Length::toUnit(json["unit"].GetString());
    _name = name;
    _maxHeight = new Length(unit, (float)json["maxHeight"].GetDouble());
    _minHeight = new Length(unit, (float)json["minHeight"].GetDouble());
    _speed = new Length(unit, (float)json["speed"].GetDouble());
    _imageName = json["image"].GetString();
    if (json["move"].IsNull() == false) {
        _move = json["move"].GetBool();
    }
    if (json["dash"].IsNull()) {
        _dashSpeed = new Length(unit, _speed->getMmLength() * 2);
    } else {
        _dashSpeed = new Length(unit, (float)json["dash"].GetDouble());
    }
}

std::string Species::getName()
{
    return _name;
}

Length* Species::getMaxHeight()
{
    return _maxHeight;
}

Length* Species::getMinHeight()
{
    return _minHeight;
}

Length* Species::getAverageHeight()
{
    return new Length(_minHeight->getMmLength() + _maxHeight->getMmLength() / 2);
}

Length* Species::getSpeed()
{
    return _speed;
}

Length* Species::getDashSpeed()
{
    return _dashSpeed;
}

std::string Species::getImageName()
{
    return _imageName;
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

    auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/animal.json");
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    for (rapidjson::Value::ConstMemberIterator itr = document.MemberonBegin();
        itr != document.MemberonEnd(); ++itr)
    {
        auto name = itr->name.GetString();
        auto species = new Species(name, document[name]);
        rtnList.push_back(species);
    }

    return rtnList;
}

