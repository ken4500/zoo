//
//  WorldInfo.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#include "WorldInfo.h"


WorldInfo::WorldInfo() :
_size(Length(UnitOfLength::cm, 16.0f)),
_level(1)
{
}

WorldInfo::~WorldInfo()
{
}

Length WorldInfo::getSize()
{
    return _size;
}

int WorldInfo::getLevel()
{
    return _level;
}
