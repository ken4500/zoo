//
//  ModalLayer.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#include "ModalLayer.h"
#include "Constants.h"

ModalLayer::ModalLayer()
{
    
}

ModalLayer::~ModalLayer()
{
    
}

bool ModalLayer::init()
{
    if (!Layer::create()) {
        return false;
    }

    // タッチイベントの設定
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(ModalLayer::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

// タイトル画像のセット
void ModalLayer::setTitleImage(string imageName)
{
    auto displaySize = Director::getInstance()->getVisibleSize();
    auto titleImage = Sprite::createWithSpriteFrameName(imageName);
    titleImage->setAnchorPoint(Vec2(0.5f, 0.5f));
    titleImage->setPosition(Vec2(displaySize.width / 2, _topPos.y - 55));
    addChild(titleImage, 1);
}

// タッチイベント(モーダルの下のイベントを通さないために)
bool ModalLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}
