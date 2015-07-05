//
//  Ant.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#include "Ant.h"

Ant::Ant() {
    _minHeight = Length(UnitOfLength::mm, 3);
    _maxHeight = Length(UnitOfLength::mm, 15);
    _speed = Length(UnitOfLength::cm, 1);
    _imageName = "ant.png";
}