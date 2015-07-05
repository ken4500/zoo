//
//  AbstractSpecies.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#include "AbstractSpecies.h"

AbstractSpecies::AbstractSpecies() :
_minHeight(Length(UnitOfLength::mm, 1)),
_maxHeight(Length(UnitOfLength::mm, 1)),
_speed(Length(UnitOfLength::mm, 1)),
_imageName("ant.png"),
_moveCsbName("AnimalMove1.csb")
{
}

Length AbstractSpecies::getMaxHeight()
{
    return _maxHeight;
}

Length AbstractSpecies::getMinHeight()
{
    return _minHeight;
}

Length AbstractSpecies::getSpeed()
{
    return _speed;
}

std::string AbstractSpecies::getImageName()
{
    return _imageName;
}

std::string AbstractSpecies::getMoveCsbName()
{
    return _moveCsbName;
}
