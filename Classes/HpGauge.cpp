//
//  HpGauge.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/04.
//
//

#include "HpGauge.h"

bool HpGauge::init() {
    if (!Node::init()) {
        return false;
    }

    return true;
}

void HpGauge::onEnter()
{
    Node::onEnter();

    _heroImage  = getChildByName<Sprite*>("image");
    _gaugeImage = getChildByName<Sprite*>("gauge");
    
    _decreaseAction = NULL;
    
    setCascadeOpacityEnabled(true);
}


void HpGauge::setInitHp(float maxHp, float hp)
{
    _maxHp = maxHp;
    _hp = hp;
    
    _gaugeImage->setScale(hp / maxHp, 1.0f);
}

void HpGauge::setHp(float hp)
{
    _hp = hp;
    
    if (_decreaseAction && _decreaseAction->isDone() == false) {
        _decreaseAction->stop();
    }
    
    if (_decreaseAction) {
        _decreaseAction->release();
        _decreaseAction = NULL;
    }

    _decreaseAction = _gaugeImage->runAction(ScaleTo::create(0.4f, _hp / _maxHp, 1.0f));
    _decreaseAction->retain();
    
    auto status = _calcHpStatus();
    if (status != _preStatus) {
        _heroImage->setTexture(StringUtils::format("gauge/image%02d.png", (int)status));
        _preStatus = status;
    }
}

HpStatus HpGauge::_calcHpStatus()
{
    float rate = _hp / _maxHp;
    HpStatus rtn;
    if (rate > 0.75f) {
        rtn = HpStatus::Great;
    } else if (rate > 0.5f) {
        rtn = HpStatus::Good;
    } else if (rate > 0.25f) {
        rtn = HpStatus::Poor;
    } else {
        rtn = HpStatus::Bad;
    }
    
    return rtn;
}
