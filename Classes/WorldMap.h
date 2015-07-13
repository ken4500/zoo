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
class Gacha;
class Animal;

class WorldMap : public cocos2d::Node {
public:
    CREATE_FUNC(WorldMap);
    bool init() override;
    void onEnter() override;
    void update(float dt);

    void setGacha(Gacha* gacha);
    void releaseAnimal(Animal* animal);

protected:
    Gacha* _gacha;
    std::vector<Animal*> _animalList;
    
    int _calcObjectZOrder(Node* node);

};

#endif /* defined(__Zoo__WorldMap__) */
