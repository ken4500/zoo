//
//  LackLife.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/11.
//
//

#include "LackLife.h"
#include "SoundManager.h"

bool LackLife::init() {
    if (!Layer::init()) {
        return false;
    }

    auto back = LayerColor::create(Color4B(0, 0, 0, 100));
    addChild(back, -1);

    return true;
}

void LackLife::onEnter()
{
    Layer::onEnter();
    _updateLanguage();

    Size size = Director::getInstance()->getVisibleSize();
    setContentSize(size);
    ui::Helper::doLayout(this);
    
    auto menu = getChildByName("menu");
    auto yes = menu->getChildByName<ui::Button*>("yesButton");
    yes->addTouchEventListener(CC_CALLBACK_2(LackLife::_pushYesButton, this));
    auto no = menu->getChildByName<ui::Button*>("noButton");
    no->addTouchEventListener(CC_CALLBACK_2(LackLife::_pushNoButton, this));
}

void LackLife::_updateLanguage()
{
    auto menu = getChildByName("menu");
    auto title = menu->getChildByName<ui::TextBMFont*>("title");
    title->setString(CCLS1("NOTICE_LACL_LIFE_TITLE",title));
    auto noticeMessage1 = menu->getChildByName<ui::Text*>("noticeMessage1");
    noticeMessage1->setString(CCLS1("NOTICE_LACK_LIFE1",noticeMessage1));
    auto noticeMessage2 = menu->getChildByName<ui::Text*>("noticeMessage2");
    noticeMessage2->setString(CCLS1("NOTICE_LACK_LIFE2",noticeMessage2));
}

void LackLife::_pushYesButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
        this->runAction(Sequence::create(
            FadeOut::create(0.3f),
            CallFunc::create([this]{
                if (pushedYesCallback) {
                    pushedYesCallback();
                }
            }),
            RemoveSelf::create(),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void LackLife::_pushNoButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
        this->runAction(Sequence::create(
            FadeOut::create(0.3f),
            CallFunc::create([this]{
                if (pushedNoCallback) {
                    pushedNoCallback();
                }
            }),
            RemoveSelf::create(),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}
