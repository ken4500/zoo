//
//  EnemyGenerater.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/19.
//
//

#ifndef __Zoo__EnemyGenerater__
#define __Zoo__EnemyGenerater__

#include "CommonInclude.h"
class Animal;

class EnemyGenerater {
public:
    EnemyGenerater(WorldInfo* info);
    ~EnemyGenerater();
    
    Animal* generate();
    
private:
    WorldInfo* _info;
    std::vector<Species*> _speciesList;
    std::default_random_engine randomGenerator;

};

#endif /* defined(__Zoo__EnemyGenerater__) */
