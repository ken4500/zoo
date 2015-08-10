//
//  Shop.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/09.
//
//

#include "Shop.h"
#include "SoundManager.h"
#include "UserDataManager.h"
#include "YesNoLayer.h"

bool Shop::init() {
    if (!Layer::init()) {
        return false;
    }
    
    auto back = LayerColor::create(Color4B(0, 0, 0, 100));
    addChild(back, -1);

    return true;
}

void Shop::onEnter()
{
    Layer::onEnter();
    
    Size size = Director::getInstance()->getVisibleSize();
    setContentSize(size);
    ui::Helper::doLayout(this);

    _offenseUp   = getChildByName("offenseUp");
    _spawnNum    = getChildByName("spawnNum");
    _animalNum   = getChildByName("animalNum");
    _getCoin     = getChildByName("getCoin");
    _emergeEnemy = getChildByName("emergeEnemy");

    _offenseUp->setTag((int)ShopLineup::OFFESE_UP);
    _spawnNum->setTag((int)ShopLineup::SPAWN_NUM);
    _animalNum->setTag((int)ShopLineup::ANIMAL_NUM);
    _getCoin->setTag((int)ShopLineup::GET_COIN);
    _emergeEnemy->setTag((int)ShopLineup::EMERGE_ENEMY);

    _shopData = new ShopData();
    
    _setData(_offenseUp);
    _setData(_spawnNum);
    _setData(_animalNum);
    _setData(_getCoin);
    _setData(_emergeEnemy);

    _hasDiamondNum = getChildByName<ui::TextBMFont*>("hasDiamondNum");
    _hasDiamondNum->setString(StringUtils::format("x %04d", UserDataManager::getInstance()->getDiamondNum()));
    
    auto ok = getChildByName<ui::Button*>("okButton");
    ok->addTouchEventListener(CC_CALLBACK_2(Shop::_pushOkButton, this));
    
    // タッチイベントの設定
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(Shop::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}


bool Shop::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}

void Shop::_pushOkButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
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

void Shop::_pushShopButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    ShopLineup type = (ShopLineup)button->getTag();

    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(Sequence::create(
            ScaleBy::create(0.1f, 1 / 0.9f),
            CallFunc::create([this, type]{
                _purchase(type);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}



void Shop::_setData(Node* node)
{
    ShopLineup type = (ShopLineup)node->getTag();
    auto desc = node->getChildByName<ui::TextBMFont*>("description");
    auto button = node->getChildByName<ui::Button*>("button");
    auto nextValue = node->getChildByName<ui::TextBMFont*>("nextValue");
    auto requreNum = button->getChildByName<ui::TextBMFont*>("requreNum");
    
    desc->setString(CCLS(StringUtils::format("SHOP_DESC_%s", ShopData::toString(type).c_str()).c_str()));
    
    int price   = _shopData->getPrice(type, 1);
    float value = _shopData->getValue(type, 1);
    
    requreNum->setString(StringUtils::format("x %d", price));
    switch (type) {
        case ShopLineup::OFFESE_UP:
        case ShopLineup::GET_COIN:
        case ShopLineup::EMERGE_ENEMY:
            nextValue->setString(StringUtils::format("%.01f倍", value));
            break;
        case ShopLineup::SPAWN_NUM:
        case ShopLineup::ANIMAL_NUM:
            nextValue->setString(StringUtils::format("%d匹", (int)value));
            break;
        default:
            break;
    }
    
    button->addTouchEventListener(CC_CALLBACK_2(Shop::_pushShopButton, this));
    button->setTag((int)type);
}

void Shop::_purchase(ShopLineup lineup)
{
    
}
