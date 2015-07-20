//
//  EnemyGenerater.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/19.
//
//

#include "EnemyGenerater.h"
#include "Animal.h"

EnemyGenerater::EnemyGenerater(WorldInfo* info)
{
    _info = info;
    std::vector<Species*> allSpecies = Species::getAllSpecies();
    _speciesList = std::vector<Species*>();
    float min = _info->width->getMmLength() / 10;
    float max = _info->width->getMmLength() / 2;
    for (Species* species : allSpecies) {
        float height = species->getAverageHeight()->getMmLength();
        if (min <= height && height <= max) {
            _speciesList.push_back(species);
        }
    }
}

EnemyGenerater::~EnemyGenerater()
{
}


Animal* EnemyGenerater::generate()
{
    std::shuffle(_speciesList.begin(), _speciesList.end(), this->randomGenerator);
    Species* target = _speciesList.back();
    return Animal::CreateWithSpeceis(target);
}
