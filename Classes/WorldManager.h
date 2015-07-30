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
#include "CommonInclude.h"
#include "EnemyGenerater.h"
class Gacha;
class Animal;
class WorldMap;
class CoinTree;

enum class SceneState {
    Tutorial,
    TutorialBattle,
    TutorialGacha,
    Normal,
    Battle,
    MultiBattle,
    ShowResult,
};

class WorldManager : cocos2d::Ref
{
public:
    static WorldManager* getInstance();
    
    // getter, setter
    WorldMap* getMap();
    WorldInfo* getWorldInfo();
    bool enableNextAction();
    void setEnableNextAction(bool enable);
    SceneState getSceneState();
    std::vector<Animal*> getAnimalList();
    std::vector<Animal*> getEnemyAnimalList();
    std::vector<Animal*> getOpponentAnimalList();
    std::vector<CoinTree*> getCoinTreeList();
    int getGachaPrice();
    int getCoin();
    void addCoin(int addCoin);
    Gacha* getGacha();
    Gacha* getOpponentGacha();

    // game logic
    void lotteryGacha();
    void releaseAnimal(Animal* animal, bool hit);
    WorldInfo* levelup();
    void startTutorial();
    void startBattle();
    void startMultiplayBattle();
    void startMultiplayTest();
    void startTutorialBattle();
    void endBattle(bool win, float showResultViewDelay);
    void endBattle(bool win);
    void endResult();
    void resetData();
    
    // network game logic
    void releaseAnimalByNetwork(Animal* animal);
    void createTreeByNetwork(CoinTree* tree);
    
    // util
    float getImageScale(Sprite* image, Length* width);
    float getDisplayLength(Length* length);
    Length* getLength(float displayLength);
    Vec2 getRadomPlace();
    Vec2 getOutRandomPlace();

private:
    bool _isNetwork;
    bool _enableNextAction;
    int _leftTime;
    int _multiBattleCoin;
    int _beforeBattleCoin;
    WorldInfo* _info;
    WorldMap* _map;
    Gacha* _gacha;
    Gacha* _opponentGacha;
    SceneState _state;
    std::vector<Animal*> _animalList;
    std::vector<Animal*> _enemyAnimalList;
    std::vector<Animal*> _opponentAnimalList;
    std::vector<CoinTree*> _coinTreeList;
    EnemyGenerater* _enemyGenerater;
    
    
    void _leftTimeUpdate(float dt);
    void _endBattle();
    void _closeResult();
    void _setGameActive(bool active);
    void _setLeftTime(int leftTime);
    void _repairAllAnimalHp();
    bool _checkAllEnemyDead();
    int _getAliveEnemy();
    void _transitionMap(WorldInfo* preWorldInfo, WorldInfo* newWorldInfo);
    void _checkAndRemoveAnimal();
    void _createMap();
    void _createMultiBattlwMap();
    void _makeCoinTree();

    void _startTutrialBattleScene1();
    void _startTutrialBattleScene2();
    void _startTutrialBattleScene3();
    void _startTutrialGachScene1();
    void _startTutrialGachScene2();
    void _startTutrialLevelupScene1();
    void _startTutrialLevelupScene2();

    WorldManager();
    ~WorldManager();

};

#endif /* defined(__Zoo__WorldManager__) */
