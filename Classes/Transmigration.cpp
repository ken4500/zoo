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
    auto noticeMessage = menu->getChildByName<ui::Text*>("noticeMessage");
    noticeMessage->setString(CCLS1("TRANSMIGRATION_NOTICEMESSAGE",noticeMessage));
    auto takeOver = menu->getChildByName<ui::TextBMFont*>("takeOver");
    takeOver->setString(CCLS1("TRANSMIGRATION_TAKEOVER",takeOver));
    auto takeOverFactor = menu->getChildByName<ui::Text*>("takeOverFactor");
    takeOverFactor->setString(CCLS1("TRANSMIGRATION_TAKEOVERFACTOR",takeOverFactor));
    auto getDiamond = menu->getChildByName<ui::TextBMFont*>("getDiamond");
    getDiamond->setString(CCLS1("TRANSMIGRATION_GETDIAMOND",getDiamond));
    
    auto title = menu->getChildByName<ui::TextBMFont*>("title");
    title->setString(CCLS1("TRANSMIGRATION_TITLE",title));
    
    if (UserDataManager::getInstance()->getLanguage() == LanguageType::JAPANESE) {
        title->setScale(0.9f);
    } else {
        title->setScale(0.6f);
    }
}