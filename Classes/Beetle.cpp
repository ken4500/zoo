//
//  Ant.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#include "Beetle.h"

using namespace cocos2d;

Beetle::Beetle() {
    _minHeight = Length(UnitOfLength::cm, 2);
    _maxHeight = Length(UnitOfLength::cm, 5);
    _speed = Length(UnitOfLength::cm, 2);
    _imageName = "animal/beetle.png";
}