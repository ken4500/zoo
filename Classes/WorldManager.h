//
//  WorldManager.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#ifndef __Zoo__WorldManager__
#define __Zoo__WorldManager__

#include "cocos2d.h"
#include "WorldMap.h"
#include "MainScene.h"
#include "CommonInclude.h"
#include "EnemyGenerater.h"
class Gacha;
class Animal;

enum class SceneState {
    Tutorial,
    TutorialBattle,
    TutorialShowResult,
    Normal,
    Battle,
    ShowResult,
    
};

class WorldManager
{
public:
    static WorldManager* getInstance();
    
    // getter, setter
    int getGachaId();
    WorldMap* getMap();
    WorldInfo* getWorldInfo();
    bool enableNextAction();
    void setEnableNextAction(bool enable);
    SceneState getSceneState();
    std::vector<Animal*> getAnimalList();
    std::vector<Animal*> getEnemyAnimalList();
    int getCoin();
    int getLife();

    // game logic
    void lotteryGacha();
    void releaseAnimal(Animal* animal, bool hit);
    WorldInfo* levelup();
    void startBattle();
    void startTutorialBattle();
    void winBattle();
    void loseBattle();
    void endResult();
    
    // util
    float getImageScale(Sprite* image, Length* width);
    float getDisplayLength(Length* length);
    Length* getLength(float displayLength);
    Vec2 getDisplayPoint(Length x, Length y);
    Vec2 getRadomPlace();
    Vec2 getOutRandomPlace();

private:
    int _level;
    bool _enableNextAction;
    int _coin;
    int _life;
    WorldInfo* _info;
    WorldMap* _map;
    Gacha* _gacha;
    SceneState _state;
    std::vector<Animal*> _animalList;
    std::vector<Animal*> _enemyAnimalList;
    EnemyGenerater* _enemyGenerater;
    
    WorldInfo* _loadWoldInfo(int level);
    MainScene* _getMainScene();
    void _endBattle();
    void _closeResult();
    void _addCoin(int addCoin);
    void _setCoin(int coin);

    WorldManager();
    ~WorldManager();

};

#endif /* defined(__Zoo__WorldManager__) */
