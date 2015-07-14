//
//  AbstractSpecies.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/05.
//
//

#include "AbstractSpecies.h"

AbstractSpecies::AbstractSpecies()
{
}

Length* AbstractSpecies::getMaxHeight()
{
    return _maxHeight;
}

Length* AbstractSpecies::getMinHeight()
{
    return _minHeight;
}

Length* AbstractSpecies::getSpeed()
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
