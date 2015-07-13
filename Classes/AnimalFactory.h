//
//  AnimalFactory.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#ifndef __Zoo__AnimalFactory__
#define __Zoo__AnimalFactory__

#include "Cocos2d.h"
#include "CommonInclude.h"
#include "Animal.h"

class AnimalFactory {
public:
    static AnimalFactory* getInstance();
    Animal* createAnimal(AnimalType type);
    Animal* createAnimal(std::string classStr);

protected:

};



#endif /* defined(__Zoo__AnimalFactory__) */
