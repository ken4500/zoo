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
#include "NoticeLayer.h"
#include "WorldManager.h"
#include "SceneManager.h"
#include "MainScene.h"

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

    _updateLanguage();

    _shopData = ShopData::getInstance();

    auto allType = ShopData::getAllType();
    auto menu = getChildByName("menu");
    for (auto type : allType) {
        auto name = ShopData::toString(type);
        auto node = menu->getChildByName(name);
        _buttonScale = node->getChildByName("button")->getScale();
        node->setTag((int)type);
        _setData(node);
    }

    _hasDiamondNum = menu->getChildByName<ui::TextBMFont*>("hasDiamondNum");
    _hasDiamondNum->setString(StringUtils::format("x %04d", UserDataManager::getInstance()->getDiamondNum()));
    
    auto ok = menu->getChildByName<ui::Button*>("okButton");
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
            CallFunc::create([this]{
                WorldManager::getInstance()->updateShopdata();
            }),
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
        button->runAction(ScaleTo::create(0.1f, _buttonScale * 0.9f));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->setEnabled(false);
        button->runAction(Sequence::create(
            ScaleTo::create(0.1f, _buttonScale),
            CallFunc::create([this, type, button]{
                _purchase(type);
                button->setEnabled(true);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleTo::create(0.1f, _buttonScale));
    }
}



void Shop::_setData(Node* node)
{
    ShopLineup type = (ShopLineup)node->getTag();
    auto desc = node->getChildByName<ui::TextBMFont*>("description");
    auto button = node->getChildByName<ui::Button*>("button");
    auto nextValue = node->getChildByName<ui::TextBMFont*>("nextValue");
    auto requreNum = button->getChildByName<ui::TextBMFont*>("requreNum");
    auto diamondImage = button->getChildByName<ui::TextBMFont*>("diamond");
    
    desc->setString(CCLS(StringUtils::format("SHOP_DESC_%s", ShopData::toString(type).c_str()).c_str()));
    
    int level     = UserDataManager::getInstance()->getShopDataLevel(type);
    int nextLevel = level + 1;
    float value   = _shopData->getValue(type, level);
    button->setEnabled(true);
    diamondImage->setVisible(true);
    int price     = _shopData->getPrice(type, nextLevel);
    
    auto lang = UserDataManager::getInstance()->getLanguage();
    switch (type) {
        case ShopLineup::OFFESE_UP:
        case ShopLineup::GET_COIN:
        case ShopLineup::EMERGE_ENEMY:
            if (lang == LanguageType::JAPANESE) {
                nextValue->setString(StringUtils::format("%.01f倍", value));
            } else {
                nextValue->setString(StringUtils::format("x %.01f", value));
            }
            break;
        case ShopLineup::SPAWN_NUM:
        case ShopLineup::ANIMAL_NUM:
            if (lang == LanguageType::JAPANESE) {
                nextValue->setString(StringUtils::format("%d匹", (int)value));
            } else {
                nextValue->setString(StringUtils::format("%d", (int)value));
            }
            break;
        case ShopLineup::MAX_LIFE:
            if (lang == LanguageType::JAPANESE) {
                nextValue->setString(StringUtils::format("%d個", (int)value));
            } else {
                nextValue->setString(StringUtils::format("%d", (int)value));
            }
            break;
        default:
            break;
    }
    
    button->addTouchEventListener(CC_CALLBACK_2(Shop::_pushShopButton, this));
    button->setTag((int)type);
    
    if (_shopData->getMaxLevel(type) <= level) {
        button->setBright(false);
        button->setTouchEnabled(false);
        diamondImage->setVisible(false);
        requreNum->setString("MAX");
        requreNum->setColor(Color3B(COLOR_BROWN_2));
        requreNum->setPosition(Vec2(150, requreNum->getPositionY()));
    } else {
        requreNum->setString(StringUtils::format("x %d", price));
    }

}

void Shop::_purchase(ShopLineup type)
{
    int price = _shopData->getPrice(type, UserDataManager::getInstance()->getShopDataLevel(type) + 1);
    int diamondNum = UserDataManager::getInstance()->getDiamondNum();
    if (price > diamondNum) {
        auto layer = NoticeLayer::createWithMessage("ダイヤが足りません");
        addChild(layer);
        return;
    }
    
    UserDataManager::getInstance()->addDiamondNum(-price);
    UserDataManager::getInstance()->levelupShopData(type);
    
    _hasDiamondNum->setString(StringUtils::format("x %04d", UserDataManager::getInstance()->getDiamondNum()));
    
    auto scene = SceneManager::getInstance()->getMainScene();
    if (scene) {
        scene->updateDiamondLabel();
    }
    
    auto name = ShopData::toString(type);
    auto node = getChildByName("menu")->getChildByName(name);
    _setData(node);
}

void Shop::_updateLanguage()
{
    auto menu = getChildByName("menu");
    menu->getChildByName<ui::TextBMFont*>("title")->setString(CCLS("SHOP_TITLE"));
    menu->getChildByName<ui::TextBMFont*>("lineup")->setString(CCLS("SHOP_LINEUP"));
}
