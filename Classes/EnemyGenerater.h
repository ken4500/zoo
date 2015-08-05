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
    EnemyGenerater(WorldInfo* info, std::function<void (Animal*)> generateCallback);
    ~EnemyGenerater();
    void start();
    void end();
    bool isEnd();
    
    
private:
    WorldInfo* _info;
    std::function<void(Animal*)> _generateEnemyCallback;
    std::vector<std::vector<Species*>> _waveSpeciesList;
    std::default_random_engine randomGenerator;
    bool _isEnd;
    int _wave;

    void update(float dt);
    Animal* _generate();
    void _nextWave();
    bool _isLastWave();
    std::vector<Species*> getSpeciesList(std::vector<Species*> allSpecies, int minSizeId, int maxSizeId);
};

#endif /* defined(__Zoo__EnemyGenerater__) */
