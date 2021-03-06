//
//  Length.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#include "Length.h"
#include "WorldManager.h"

#pragma - static

std::map<std::string, UnitOfLength> Length::toUnitMap = {
    {"mm", UnitOfLength::mm},
    {"cm", UnitOfLength::cm},
    {"m" , UnitOfLength::m},
    {"km", UnitOfLength::km},
};

std::map<UnitOfLength, std::string> Length::toStringMap = {
    {UnitOfLength::mm, "mm"},
    {UnitOfLength::cm, "cm"},
    {UnitOfLength::m , "m"},
    {UnitOfLength::km, "km"},
};

std::string Length::toString(UnitOfLength unit)
{
    return Length::toStringMap[unit];
}

UnitOfLength Length::toUnit(std::string str)
{
    return Length::toUnitMap[str];
}

Length Length::createWithDisplayLength(float displayLength)
{
    return *WorldManager::getInstance()->getLength(displayLength);
}

#pragma - core

Length::Length(float length) :
_mm(length)
{
}


Length::Length(UnitOfLength unit, float length) :
_mm(length * (float)unit)
{
}

#pragma - public

UnitOfLength Length::getUnit()
{
    if (_mm >= (int)UnitOfLength::km) {
        return UnitOfLength::km;
    } else if (_mm >= (int)UnitOfLength::m) {
        return UnitOfLength::m;
    } else if (_mm >= (int)UnitOfLength::cm) {
        return UnitOfLength::cm;
    }
    
    return UnitOfLength::mm;
}

std::string Length::getUnitStr()
{
    auto unit = getUnit();
    return Length::toString(unit);
}

float Length::getLength()
{
    auto unit = getUnit();
    return _mm / (float)unit;
}

float Length::getMmLength()
{
    return _mm;
}


float Length::getLength(UnitOfLength unit)
{
    return _mm / (float)unit;
}

float Length::getDisplayLength()
{
    return WorldManager::getInstance()->getDisplayLength(this);
}

#pragma - calculate

Length Length::add(Length l)
{
    _mm += l.getMmLength();
    return Length(_mm);
}

Length Length::scale(float scale)
{
    _mm *= scale;
    return Length(_mm);
}

Length Length::add(Length l1, Length l2)
{
    return Length(l1.getMmLength() + l2.getMmLength());
}

Length Length::scale(Length l, float scale)
{
    return Length(l.getMmLength() * scale);
}
