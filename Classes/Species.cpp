//
//  Species.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#include "Species.h"
#include "cocos2d.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
USING_NS_CC;

Species::Species(std::string name) :
_moveCsbName("AnimalMove1.csb")
{
    auto jsonStr = FileUtils::getInstance()->getStringFromFile("data/animal.json");
    rapidjson::Document document;
    document.Parse<0>(jsonStr.c_str());
    rapidjson::Value& speceisDoc = document[name.c_str()];
    UnitOfLength unit = Length::toUnit(speceisDoc["unit"].GetString());
    _maxHeight = new Length(unit, (float)speceisDoc["maxHeight"].GetDouble());
    _minHeight = new Length(unit, (float)speceisDoc["minHeight"].GetDouble());
    _speed = new Length(unit, (float)speceisDoc["speed"].GetDouble());
    _imageName = speceisDoc["image"].GetString();
    if (speceisDoc["move"].IsNull() == false) {
        _move = speceisDoc["move"].GetBool();
    }
}

Length* Species::getMaxHeight()
{
    return _maxHeight;
}

Length* Species::getMinHeight()
{
    return _minHeight;
}

Length* Species::getSpeed()
{
    return _speed;
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
