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
    void initSize(Length* maxWidth, Length* currentWidth);

    Length* getCurrentWidth();
    Length* getMaxWidth();
    void setCurrentWidth(Length* length);
    void setGacha(Gacha* gacha);
    bool isMaxScale();

    void releaseAnimal(Animal* animal);

    std::function<void(WorldMap* self)> scaleupCallback;

protected:
    Length* _maxWidth;
    Length* _currentWidth;
    Gacha* _gacha;
    std::vector<Animal*> _animalList;
    
    int _calcObjectZOrder(Node* node);

};

#endif /* defined(__Zoo__WorldMap__) */
