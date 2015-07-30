//
//  CoinTree.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#ifndef __Zoo__CoinTree__
#define __Zoo__CoinTree__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"
#include "CommonInclude.h"
#include "AbstractBattleEntity.h"

class CoinTree : public AbstractBattleEntity {
public:
    CREATE_FUNC(CoinTree);
    bool init() override;
    void setLength(Length* length);
    Length* getLength();
    void sprout();
    void sway();
    void dropCoin();
    void fellDown();
    Rect getBodyRect();
    bool addDamage(float damage);
    void disappear();
    bool isDead();
    int getId();
    void setId(int id);
    Vec2 getRealPosition();
    void setRealPosition(Vec2 position);

protected:
    cocostudio::timeline::ActionTimeline* _timeline;
    cocos2d::Sprite* _image;
    cocos2d::Node* _dropListNode;
    std::vector<cocos2d::Node*> _dropPointList;
    int _id;
    int _dropCoin;
    int _dropCount;
    int _preDropPos;
    float _maxHp;
    float _hp;
    Length* _length;
    bool _isSwaying;
    
    void onEnter() override;

};

#endif /* defined(__Zoo__CoinTree__) */
