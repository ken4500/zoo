//
//  WorldMap.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/13.
//
//

#ifndef __Zoo__WorldMap__
#define __Zoo__WorldMap__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CommonInclude.h"
#include "WorldManager.h"
class Gacha;
class Animal;
class CoinTree;

class WorldMap : public cocos2d::Node {
public:
    CREATE_FUNC(WorldMap);
    bool init() override;
    void onEnter() override;
    void updateDash(float dt);
    void update(float dt);
    void initSize(Length* maxWidth, Length* currentWidth);

    Length* getCurrentWidth();
    Length* getMaxWidth();
    void setCurrentWidth(Length* length, std::function<void ()> callback);
    void setGacha(Gacha* gacha);
    bool isMaxScale();
    void setCoinTree(CoinTree* tree);

    void releaseAnimal(Animal* animal, std::function<void ()> callback);
    void releaseOpponentAnimal(Animal* animal, std::function<void ()> callback);
    void addAnimalAtRandomPoint(Animal* animal);
    void addAnimal(Animal* animal, Vec2 targetPoint);
    void addEnemyAnimalAtOutRandomPoint(Animal* animal);
    void addEnemyAnimal(Animal* animal, Vec2 targetPoint);
    
    void hideGacha();
    void showGacha();
    
protected:
    Length* _maxWidth;
    Length* _currentWidth;
    Vec2 _targetPoint;
    
    int _calcObjectZOrder(Node* node);
    void setupTouchHandling();
    BattleState _checkBattleEnd();

};

#endif /* defined(__Zoo__WorldMap__) */
