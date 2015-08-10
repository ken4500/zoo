//
//  Species.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#include "Species.h"
#include "cocos2d.h"
#include "ZUtil.h"

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
    CCLOG("%s", name.c_str());
    UnitOfLength unit = Length::toUnit(json["unit"].GetString());
    _name      = name;
    _sizeId    = json["sizeId"].GetInt();
    _maxHeight = Length(unit, (float)json["maxHeight"].GetDouble());
    _minHeight = Length(unit, (float)json["minHeight"].GetDouble());
    _speed     = Length(unit, (float)json["speed"].GetDouble());
    _density   = (float)json["density"].GetDouble();
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

int Species::getSizeId()
{
    return _sizeId;
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
    return Length((_minHeight.getMmLength() + _maxHeight.getMmLength()) / 2);
}

Weight Species::getMaxWeight()
{
    return Weight(getMaxHeight(), getDensity());
}

Weight Species::getAverageWeight()
{
    return Weight(getAverageHeight(), getDensity());
}

Weight Species::getMinWeight()
{
    return Weight(getMinHeight(), getDensity());
}

SizeRank Species::getMaxHeightRank(Length maxHeight)
{
    auto x    = maxHeight.getMmLength();
    auto sd   = _getStandardDeviation();
    auto mean = getAverageHeight().getMmLength();
    
    // 出現率0.13% (R :1 - pnorm(3, 0, 1) = 0.0013
    float goldThreshold   = mean + sd * 3.0;
    // 出現率0.4% (R :1 - pnorm(2.65, 0, 1) = 0.0040
    float silverThreshold = mean + sd * 2.65;

//    // 出現率0.13% (R :1 - pnorm(3, 0, 1) = 0.0013
//    float goldThreshold   = mean + sd * 0.1;
//    // 出現率0.4% (R :1 - pnorm(2.65, 0, 1) = 0.0040
//    float silverThreshold = mean + sd * 1.00;


    if (x > goldThreshold) {
        return SizeRank::Gold;
    } else if (x > silverThreshold) {
        return SizeRank::Silver;
    } else {
        return SizeRank::None;
    }
}

SizeRank Species::getMinHeightRank(Length minHeight)
{
    auto x    = minHeight.getMmLength();
    auto sd   = _getStandardDeviation();
    auto mean = getAverageHeight().getMmLength();
    
    // 出現率0.13% (R :1 - pnorm(3, 0, 1) = 0.0013
    float goldThreshold   = mean - sd * 3.0;
    // 出現率0.4% (R :1 - pnorm(2.65, 0, 1) = 0.0040
    float silverThreshold = mean - sd * 2.65;

//    // 出現率0.13% (R :1 - pnorm(3, 0, 1) = 0.0013
//    float goldThreshold   = mean - sd * 1.0;
//    // 出現率0.4% (R :1 - pnorm(2.65, 0, 1) = 0.0040
//    float silverThreshold = mean - sd * 0.1;


    if (x < goldThreshold) {
        return SizeRank::Gold;
    } else if (x < silverThreshold) {
        return SizeRank::Silver;
    } else {
        return SizeRank::None;
    }
}

Length Species::getSpeed()
{
    return _speed;
}

Length Species::getDashSpeed()
{
    return _dashSpeed;
}

float Species::getDensity()
{
    return _density;
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

Length Species::getRandomHeight()
{
    float mean = getAverageHeight().getMmLength();
    float sd   = _getStandardDeviation();
    
    float rnd = ZUtil::boxrnd(mean, sd);
//    rnd = MIN(rnd, _maxHeight.getMmLength());
//    rnd = MAX(rnd, _minHeight.getMmLength());
    return Length(rnd);
}

double Species::_getStandardDeviation()
{
    return (getMaxHeight().getMmLength() - getMinHeight().getMmLength()) / 6.0;
}

