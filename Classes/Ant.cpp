//
//  Ant.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#include "Ant.h"

Ant::Ant() {
    _minHeight = new Length(UnitOfLength::mm, 5);
    _maxHeight = new Length(UnitOfLength::mm, 15);
    _speed = new Length(UnitOfLength::cm, 1);
    _imageName = "animal/ant.png";
}