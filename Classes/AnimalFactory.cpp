//
//  AnimalFactory.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#include "AnimalFactory.h"


static AnimalFactory* instance = nullptr;

AnimalFactory* AnimalFactory::getInstance()
{
    if (! instance)
    {
        instance = new AnimalFactory();
    }

    return instance;
}

Animal* AnimalFactory::createAnimal(AnimalType type)
{
}

Animal* AnimalFactory::createAnimal(std::string classStr)
{
}