//
//  Length.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#include "Length.h"

Length::Length(UnitOfLength unit, float length) :
_mm(length * (float)unit)
{
}

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
