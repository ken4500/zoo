//
//  EnemyGenerater.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/19.
//
//

#include "EnemyGenerater.h"
#include "Animal.h"
#include "WorldManager.h"
#include "UserDataManager.h"

const int WAVE_COUNT = 3;
const int ENEMY_COUNT_PER_WAVE = 8;

EnemyGenerater::EnemyGenerater(WorldInfo* info, std::function<void (Animal*)> generateCallback)
{
    _info = info;
    _generateEnemyCallback = generateCallback;
    _isEnd = true;

    std::vector<Species*> allSpecies = Species::getAllSpecies();
    _waveSpeciesList = std::vector<std::vector<Species*>>();
    int minSizeId = MAX(1, _info->level - 1);
    int maxSizeId = MAX(1, _info->level);
    
    if (_info->level != MAX_SIZE_ID) {
        for (int wave = 0; wave < WAVE_COUNT; wave++) {
            if (wave == WAVE_COUNT - 1) {
                _waveSpeciesList.push_back(getSpeciesList(allSpecies, maxSizeId, maxSizeId));
            } else {
                _waveSpeciesList.push_back(getSpeciesList(allSpecies, minSizeId, maxSizeId));
            }

            if (minSizeId == maxSizeId) {
                maxSizeId = MIN(maxSizeId + 1, MAX_SIZE_ID - 1);
            } else {
                minSizeId = MIN(minSizeId + 1, MAX_SIZE_ID - 1);
                maxSizeId = MIN(maxSizeId + 1, MAX_SIZE_ID - 1);
            }
        }
    } else {
        for (int wave = 0; wave < WAVE_COUNT; wave++) {
            _waveSpeciesList.push_back(getSpeciesList(allSpecies, _info->level, _info->level));
        }
    }
}

EnemyGenerater::~EnemyGenerater()
{
}

void EnemyGenerater::start()
{
    _wave = 0;
    _isEnd = false;
    Director::getInstance()->getScheduler()->schedule(CC_CALLBACK_1(EnemyGenerater::update, this), this, 1.0f, false, "update_enemy_generater");
}

void EnemyGenerater::end()
{
    _isEnd = true;
    Director::getInstance()->getScheduler()->unschedule("update_enemy_generater", this);
}

bool EnemyGenerater::isEnd()
{
    return _isEnd;
}

void EnemyGenerater::update(float dt)
{
    int aliveEnemy = WorldManager::getInstance()->getAliveEnemy();
    if (aliveEnemy <= ENEMY_COUNT_PER_WAVE * 0.4f) {
        _nextWave();
        if (_isLastWave()) {
            end();
        }
    }
}


Animal* EnemyGenerater::_generate()
{
    std::shuffle(_waveSpeciesList[_wave - 1].begin(), _waveSpeciesList[_wave - 1].end(), this->randomGenerator);
    Species* target = _waveSpeciesList[_wave - 1].back();
    return Animal::CreateWithSpeceis(target);
}

void EnemyGenerater::_nextWave()
{
    _wave++;
    
    int enemyCount = (int)(ENEMY_COUNT_PER_WAVE * UserDataManager::getInstance()->getEnemyNumRate());
    if (_wave == WAVE_COUNT) {
        enemyCount = 1;
    }
    
    for (int i = 0; i < enemyCount; i++) {
        Animal* enemy = _generate();
        _generateEnemyCallback(enemy);
    }
}

bool EnemyGenerater::_isLastWave()
{
    return _wave == WAVE_COUNT;
}

std::vector<Species*> EnemyGenerater::getSpeciesList(std::vector<Species*> allSpecies, int minSizeId, int maxSizeId)
{
    std::vector<Species*> rtn;
    for (Species* species : allSpecies) {
        if (minSizeId <= species->getSizeId() && species->getSizeId() <= maxSizeId) {
            rtn.push_back(species);
        }
    }
    return rtn;
}
