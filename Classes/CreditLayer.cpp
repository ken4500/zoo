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
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 200))) {
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

    auto title = node->getChildByName<ui::TextBMFont*>("KenWatanabe");
    title->setString(CCLS1("CREDIT_PAGE_KEN_WATANABE",title));
    auto namiKitanobo = node->getChildByName<ui::TextBMFont*>("NamiKitanobo");
    namiKitanobo->setString(CCLS1("CREDIT_PAGE_NAMI_KITANOBO",namiKitanobo));
    auto nameTranslate = node->getChildByName<ui::TextBMFont*>("NameTranslate");
    nameTranslate->setString(CCLS1("CREDIT_PAGE_NAME_TRANSLATE",nameTranslate));
    
    auto RoleKen = node->getChildByName<ui::TextBMFont*>("RoleKen");
    RoleKen->setString(CCLS1("CREDIT_PAGE_ROLE_KEN",RoleKen));
    auto roleNami = node->getChildByName<ui::TextBMFont*>("RoleNami");
    roleNami->setString(CCLS1("CREDIT_PAGE_ROLE_NAMI",roleNami));
    
    auto roleFan = node->getChildByName<ui::TextBMFont*>("RoleFan");
    roleFan->setString(CCLS1("CREDIT_PAGE_ROLE_FAN",roleFan));
    auto nameFan = node->getChildByName<ui::TextBMFont*>("LiangFan");
    nameFan->setString(CCLS1("CREDIT_PAGE_NAME_FAN",nameFan));
    
    auto roleTranslate = node->getChildByName<ui::TextBMFont*>("RoleTranslate");
    roleTranslate->setString(CCLS1("CREDIT_PAGE_ROLE_TRANSLATE",roleTranslate));
    
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
