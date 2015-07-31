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
};

std::map<UnitOfWeight, std::string> Weight::toStringMap = {
    {UnitOfWeight::mg, "mg"},
    {UnitOfWeight::g,  "g"},
    {UnitOfWeight::kg, "kg"},
    {UnitOfWeight::t,  "t"},
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
    if (_mg >= (int)UnitOfWeight::t) {
        return UnitOfWeight::t;
    } else if (_mg >= (int)UnitOfWeight::kg) {
        return UnitOfWeight::kg;
    } else if (_mg >= (int)UnitOfWeight::g) {
        return UnitOfWeight::g;
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
    return _mg / (float)unit;
}

float Weight::getMgWeight()
{
    return _mg;
}


float Weight::getWeight(UnitOfWeight unit)
{
    return _mg / (float)unit;
}
