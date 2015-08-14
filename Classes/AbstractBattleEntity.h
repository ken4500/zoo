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
class Animal;

class AbstractBattleEntity : public cocos2d::Node
{
public:
    virtual bool isDead() = 0;
    virtual bool addDamage(float damage, Animal* animal) = 0;
    virtual cocos2d::Rect getBodyRect() = 0;
    virtual int getId() = 0;
    virtual void setId(int id) = 0;

    virtual Vec2 getRealPosition() = 0;
    virtual void setRealPosition(Vec2 position) = 0;

    std::function<void (AbstractBattleEntity* entity)> deadCallback;

};


#endif
