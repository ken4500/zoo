//
//  AnimalFactory.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#include "AnimalFactory.h"
#include "Ant.h"
#include "Beetle.h"
#include "Dog.h"


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
    AbstractSpecies* species = nullptr;
    switch (type) {
    case AnimalType::Ant:
        species = new Ant();
        break;
    case AnimalType::Beetle:
        species = new Beetle();
    default:
        break;
    }
    return Animal::CreateWithSpeceis(species);
}

Animal* AnimalFactory::createAnimal(std::string classStr)
{
    AbstractSpecies* species = nullptr;
    if (classStr == "Ant") {
        species = new Ant();
    } else if (classStr == "Beetle") {
        species = new Beetle();
    } else if (classStr == "Dog") {
        species = new Dog();
    }
    return Animal::CreateWithSpeceis(species);
}