//
//  HpGauge.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/04.
//
//

#ifndef __Zoo__HpGauge__
#define __Zoo__HpGauge__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

enum class HpStatus{
    Great = 1,
    Good  = 2,
    Poor  = 3,
    Bad   = 4,
};

class HpGauge : public cocos2d::Node {
public:
    CREATE_FUNC(HpGauge);
    bool init() override;
    void setInitHp(float maxHp, float hp);
    void setHp(float hp);

protected:
    Sprite* _heroImage;
    Sprite* _gaugeImage;
    Action* _decreaseAction;
    
    float _maxHp;
    float _hp;
    HpStatus _preStatus;

    void onEnter() override;
    HpStatus _calcHpStatus();
};

#endif /* defined(__Zoo__HpGauge__) */
