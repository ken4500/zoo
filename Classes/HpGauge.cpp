//
//  HpGauge.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/04.
//
//

#include "HpGauge.h"
#include "ColorConstants.h"

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
    _charaAnimationAction = NULL;
    
    setCascadeOpacityEnabled(true);
}


void HpGauge::setInitHp(float maxHp, float hp)
{
    _maxHp = maxHp;
    _hp = hp;
    
    _gaugeImage->setScale(hp / maxHp, 1.0f);
    auto status = _calcHpStatus();
    _startAnimation(status);
    _setGaugeColor(hp / maxHp);
    _preStatus = status;
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
        _preStatus = status;
        _startAnimation(status);
        _setGaugeColor(_hp / _maxHp);
    }
}

HpStatus HpGauge::_calcHpStatus()
{
    float rate = _hp / _maxHp;
    HpStatus rtn;
    if (rate > 0.6f) {
        rtn = HpStatus::Good;
    } else if (rate > 0.3f) {
        rtn = HpStatus::Poor;
    } else {
        rtn = HpStatus::Bad;
    }
    
    return rtn;
}

void HpGauge::_startAnimation(HpStatus status)
{
    if (_charaAnimationAction) {
        stopAction(_charaAnimationAction);
        _charaAnimationAction = NULL;
    }

    std::string fileName1;
    std::string fileName2;

    if (status == HpStatus::Good) {
        fileName1 = "gauge/image01.png";
        fileName2 = "gauge/image02.png";
    } else if (status == HpStatus::Poor) {
        fileName1 = "gauge/image03.png";
        fileName2 = "gauge/image04.png";
    } else if (status == HpStatus::Bad) {
        fileName1 = "gauge/image05.png";
        fileName2 = "gauge/image05.png";
    }

    float interval = 0.6f;
    _charaAnimationAction = RepeatForever::create(Sequence::create(
        CallFunc::create([this, fileName1]{
            _heroImage->setTexture(fileName1);
        }),
        DelayTime::create(interval),
        CallFunc::create([this, fileName2]{
            _heroImage->setTexture(fileName2);
        }),
        DelayTime::create(interval),
        NULL
    ));
    
    runAction(_charaAnimationAction);
}

void HpGauge::_setGaugeColor(float rate)
{
    if (rate > 0.5f) {
        _gaugeImage->setColor(Color3B(COLOR_PINK));
    } else {
        _gaugeImage->setColor(Color3B(COLOR_YELLOW));
    }
}
