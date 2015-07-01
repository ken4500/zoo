//
//  Ant.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#include "Ant.h"

using namespace cocos2d;

bool Ant::init() {
    if (!Animal::init()) {
        return false;
    }

    return true;
}
