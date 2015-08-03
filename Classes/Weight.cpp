//
//  Weight.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/31.
//
//

#include "Weight.h"
#include <math.h>

std::map<std::string, UnitOfWeight> Weight::toUnitMap = {
    {"mg", UnitOfWeight::mg},
    {"g" , UnitOfWeight::g},
    {"kg", UnitOfWeight::kg},
    {"t" , UnitOfWeight::t},
    {"Mt" , UnitOfWeight::Mt},
    {"Gt" , UnitOfWeight::Gt},
    {"Pt" , UnitOfWeight::Pt},
    {"Et" , UnitOfWeight::Et},
    {"Zt" , UnitOfWeight::Zt},
    {"Yt" , UnitOfWeight::Yt},
};

std::map<UnitOfWeight, std::string> Weight::toStringMap = {
    {UnitOfWeight::mg, "mg"},
    {UnitOfWeight::g,  "g"},
    {UnitOfWeight::kg, "kg"},
    {UnitOfWeight::t,  "t"},
    {UnitOfWeight::Mt, "Mt"},
    {UnitOfWeight::Gt, "Gt"},
    {UnitOfWeight::Pt, "Pt"},
    {UnitOfWeight::Et, "Et"},
    {UnitOfWeight::Zt, "Zt"},
    {UnitOfWeight::Yt, "Yt"},
};

std::map<UnitOfWeight, float> Weight::toValueMap = {
    {UnitOfWeight::mg, 1.0f},
    {UnitOfWeight::g,  1000.0f},
    {UnitOfWeight::kg, 1000000.0f},
    {UnitOfWeight::t,  1000000000.0f},
    {UnitOfWeight::Mt, 1000000000000.0f},
    {UnitOfWeight::Gt, 1000000000000000.0f},
    {UnitOfWeight::Pt, 1000000000000000000.0f},
    {UnitOfWeight::Et, 1000000000000000000000.0f},
    {UnitOfWeight::Zt, 1000000000000000000000000.0f},
    {UnitOfWeight::Yt, 1000000000000000000000000000.0f},
};

std::string Weight::toString(UnitOfWeight unit)
{
    return Weight::toStringMap[unit];
}

UnitOfWeight Weight::toUnit(std::string str)
{
    return Weight::toUnitMap[str];
}

#pragma - core

Weight::Weight(float Weight) :
_mg(Weight)
{
}


Weight::Weight(UnitOfWeight unit, float Weight) :
_mg(Weight * (float)unit)
{
}

Weight::Weight(Length length) :
_mg(powf(length.getMmLength(), 3) * 0.125)
{
}


#pragma - public

UnitOfWeight Weight::getUnit()
{
    if (_mg >= Weight::toValueMap[UnitOfWeight::Yt]) {
        return UnitOfWeight::Yt;
    } else if (_mg >= Weight::toValueMap[UnitOfWeight::Zt]) {
        return UnitOfWeight::Zt;
    } else if (_mg >= Weight::toValueMap[UnitOfWeight::Et]) {
        return UnitOfWeight::Et;
    } else if (_mg >= Weight::toValueMap[UnitOfWeight::Gt]) {
        return UnitOfWeight::Gt;
    } else if (_mg >= Weight::toValueMap[UnitOfWeight::Mt]) {
        return UnitOfWeight::Mt;
    } else if (_mg >= Weight::toValueMap[UnitOfWeight::t]) {
        return UnitOfWeight::t;
    } else if (_mg >= Weight::toValueMap[UnitOfWeight::kg]) {
        return UnitOfWeight::kg;
    } else if (_mg >= Weight::toValueMap[UnitOfWeight::g]) {
        return UnitOfWeight::g;
    } else if (_mg >= Weight::toValueMap[UnitOfWeight::mg]) {
        return UnitOfWeight::mg;
    }
    
    return UnitOfWeight::mg;
}

std::string Weight::getUnitStr()
{
    auto unit = getUnit();
    return Weight::toString(unit);
}

float Weight::getWeight()
{
    auto unit = getUnit();
    return _mg / Weight::toValueMap[unit];
}

float Weight::getMgWeight()
{
    return _mg;
}


float Weight::getWeight(UnitOfWeight unit)
{
    return _mg / (float)unit;
}
