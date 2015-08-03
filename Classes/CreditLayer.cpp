//
//  CreditLayer.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#include "CreditLayer.h"
#include "SoundManager.h"
#include "UserDataManager.h"

bool CreditLayer::init()
{
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 160))) {
        return false;
    }
 
    this->setCascadeOpacityEnabled(false);
    
    auto displaySize = Director::getInstance()->getVisibleSize();
    auto node = CSLoader::createNode("Credit.csb");
    node->setAnchorPoint(Vec2(0.5f, 0.5f));
    node->setPosition(Vec2::ZERO);
    node->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    node->setCascadeOpacityEnabled(true);
    node->setOpacity(255);
    addChild(node, 10);
    _rootNode = node;

    node->getChildByName<ui::TextBMFont*>("title")->setString(CCLS("CREDIT_PAGE_TITLE"));
    node->getChildByName<ui::TextBMFont*>("KenWatanabe")->setString(CCLS("CREDIT_PAGE_KEN_WATANABE"));
    node->getChildByName<ui::TextBMFont*>("NamiKitanobo")->setString(CCLS("CREDIT_PAGE_NAMI_KITANOBO"));
    node->getChildByName<ui::TextBMFont*>("RoleKen")->setString(CCLS("CREDIT_PAGE_ROLE_KEN"));
    node->getChildByName<ui::TextBMFont*>("RoleNami")->setString(CCLS("CREDIT_PAGE_ROLE_NAMI"));
    
    
    auto button = node->getChildByName<ui::Button*>("okButton");
    button->addTouchEventListener(CC_CALLBACK_2(CreditLayer::_pushButton, this));
    
    return true;
}

void CreditLayer::onEnter()
{
    LayerColor::onEnter();

    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(CreditLayer::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void CreditLayer::_pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
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
            CallFunc::create([this](){
                if (closedCallback) {
                    closedCallback();
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

// タッチイベント(モーダルの下のイベントを通さないために)
bool CreditLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}
