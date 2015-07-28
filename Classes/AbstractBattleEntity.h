//
//  AbstractBattleEntity.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/28.
//
//

#ifndef Zoo_AbstractBattleEntity_h
#define Zoo_AbstractBattleEntity_h

#include "cocos2d.h"

class AbstractBattleEntity : public cocos2d::Node
{
public:
    virtual bool isDead() = 0;
    virtual bool addDamage(float damage) = 0;
    virtual Rect getBodyRect() = 0;
};


#endif
