//
//  Transmigration.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/09.
//
//

#include "Transmigration.h"
#include "WorldManager.h"
#include "SoundManager.h"
#include "UserDataManager.h"

bool Transmigration::init() {
    if (!Layer::init()) {
        return false;
    }

    auto back = LayerColor::create(Color4B(0, 0, 0, 100));
    addChild(back, -1);

    return true;
}

void Transmigration::onEnter()
{
    Layer::onEnter();
    
    Size size = Director::getInstance()->getVisibleSize();
    setContentSize(size);
    ui::Helper::doLayout(this);
    
    _updateLocalization();

    auto menu = getChildByName("menu");
    auto yes = menu->getChildByName<ui::Button*>("yesButton");
    yes->addTouchEventListener(CC_CALLBACK_2(Transmigration::_pushYesButton, this));
    auto no = menu->getChildByName<ui::Button*>("noButton");
    no->addTouchEventListener(CC_CALLBACK_2(Transmigration::_pushNoButton, this));

    _getDiamondNum = menu->getChildByName<ui::TextBMFont*>("getDiamondNum");
    _getDiamondNum->setString(StringUtils::format("x %d", WorldManager::getInstance()->getDiamondNumInTransmigration()));
    
    // タッチイベントの設定
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(Transmigration::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

// タッチイベント(モーダルの下のイベントを通さないために)
bool Transmigration::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}

void Transmigration::_pushYesButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->setEnabled(false);
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
        this->runAction(Sequence::create(
            FadeOut::create(0.3f),
            CallFunc::create([this]{

                // 転生する
                WorldManager::getInstance()->transmigration();

            }),
            RemoveSelf::create(),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void Transmigration::_pushNoButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
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
            RemoveSelf::create(),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void Transmigration::_updateLocalization()
{
    auto menu = getChildByName("menu");
    menu->getChildByName<ui::Text*>("noticeMessage")->setString(CCLS("TRANSMIGRATION_NOTICEMESSAGE"));
    menu->getChildByName<ui::TextBMFont*>("takeOver")->setString(CCLS("TRANSMIGRATION_TAKEOVER"));
    menu->getChildByName<ui::Text*>("takeOverFactor")->setString(CCLS("TRANSMIGRATION_TAKEOVERFACTOR"));
    menu->getChildByName<ui::TextBMFont*>("getDiamond")->setString(CCLS("TRANSMIGRATION_GETDIAMOND"));
    
    auto title = menu->getChildByName<ui::TextBMFont*>("title");
    title->setString(CCLS("TRANSMIGRATION_TITLE"));
    auto yes = menu->getChildByName("yesButton")->getChildByName<ui::TextBMFont*>("label");
    
    if (UserDataManager::getInstance()->getLanguage() == LanguageType::JAPANESE) {
        title->setScale(0.9f);
    } else {
        title->setScale(0.6f);
    }
}