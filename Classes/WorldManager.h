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
#include "CocosGUI.h"
#include "CommonInclude.h"
#include "EnemyGenerater.h"
class Gacha;
class Animal;
class WorldMap;
class CoinTree;
class AbstractBattleEntity;

enum class SceneState {
    Tutorial,
    TutorialBattle,
    TutorialGacha,
    Normal,
    Battle,
    ShowResult,
    MultiBattle,
    MultiBattleResult,
};

class WorldManager : cocos2d::Ref
{
public:
    static WorldManager* getInstance();
    
    // getter, setter
    WorldMap* getMap();
    WorldInfo* getWorldInfo();
    bool enableNextAction();
    SceneState getSceneState();
    std::vector<Animal*> getAnimalList();
    std::vector<Animal*> getEnemyAnimalList();
    std::vector<Animal*> getOpponentAnimalList();
    std::vector<CoinTree*> getCoinTreeList();
    Animal* getOpponentAnimal(int id);
    CoinTree* getCoinTree(int id);
    long int getGachaPrice();
    long int getCoin();
    void addCoin(long int addCoin);
    Gacha* getGacha();
    Gacha* getOpponentGacha();
    Length getDashSpeed();
    Weight getTotalWeight();
    float getMaxHp();
    float getHp();
    int getAliveEnemy();
    int getLeftTimeOnBattle();
    int getDiamondNumInTransmigration();

    // game logic
    void lotteryGacha();
    void releaseAnimal(Animal* animal, bool hit);
    void levelup();
    void startTutorial();
    void startBattle();
    void startTutorialBattle();
    void endBattle(bool win, float showResultViewDelay);
    void endBattle(bool win);
    void endResult();
    void resetData();
    BattleState checkBattleState();
    void appearCrown(SizeRank rank);
    void transmigration();
    void updateShopdata();
    
    // network game logic
    void startMultiplayBattle();
    void startMultiplayTest();
    void showResultMultiplayBattle();
    void endMultiplayBattle();
    void releaseAnimalByNetwork(Animal* animal);
    void createTreeByNetwork(CoinTree* tree);
    void deadTreeByNetwork(int treeId);
    void removeAnimalByNetwork(int animalId);
    void levelupOpponent(int level);
    void recieveResult(Weight opponentWeight);
    void disconnectSession();
    
    // util
    float getImageScale(Sprite* image, Length width);
    float getDisplayLength(Length* length);
    Length* getLength(float displayLength);
    Vec2 getRealPosition(Vec2 displayPosition);
    Vec2 getDisplayPosition(Vec2 readlPosition);
    Vec2 getRadomPlace();
    Vec2 getOutRandomPlace();

private:
    bool _isNetwork;
    bool _enableNextAction;
    int _leftTime;
    long int _multiBattleCoin;
    long int _beforeBattleCoin;
    Weight _totalWeight;
    WorldInfo* _info;
    WorldInfo* _opponentInfo;
    WorldMap* _map;
    Gacha* _gacha;
    Gacha* _opponentGacha;
    SceneState _state;
    EnemyGenerater* _enemyGenerater;
    Weight* _opponentResultWeight;
    bool _enableBattle;
    
    void _hpGaugeUpdate();
    void _leftTimeUpdate(float dt);
    void _closeResult();
    void _setGameActive(bool active);
    void _setLeftTime(int leftTime);
    void _repairAllAnimalHp();
    void _transitionMap(WorldInfo* preWorldInfo, WorldInfo* newWorldInfo);
    void _checkAndRemoveAnimal();
    void _createMap();
    void _createMultiBattlwMap();
    void _makeCoinTree();
    void _finishGachaCallback();
    void _finishLevelupCallback();
    void _setTotalWeight(Weight weight);

    // network
    void _sendAnimalStatus(float dt);
    void _makeCoinTreePerTime(float dt);
    void _deadCoinTreeCallback(AbstractBattleEntity* deadTree);
    bool _gachaIsFrontZOrder(bool isOpponent);
    GameResult _decideMultiplayResult();

    // tutorial
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
