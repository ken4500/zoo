//
//  Dog.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/06.
//
//

#include "Dog.h"

Dog::Dog() {
    _minHeight = Length(UnitOfLength::m, 0.3);
    _maxHeight = Length(UnitOfLength::m, 1.2);
    _speed = Length(UnitOfLength::m, 0.5);
    _imageName = "beetle.png";
}