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

bool ModalLayer::initWithHeight(int height)
{
    if (!Layer::create()) {
        return false;
    }
//    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 160))) {
//        return false;
//    }
    
    _height = height;
    auto displaySize = Director::getInstance()->getVisibleSize();
    
    // 枠
    auto top    = Sprite::create("ui/pop_01.png");
    auto middle = Sprite::create("ui/pop_02.png");
    auto bottom = Sprite::create("ui/pop_03.png");
    top->setAnchorPoint(Vec2(0.5f, 1));
    middle->setAnchorPoint(Vec2(0.5f, 1));
    bottom->setAnchorPoint(Vec2(0.5f, 1));
    _topPos = Vec2(displaySize.width / 2, (displaySize.height + height) / 2);
    top->setPosition(_topPos);
    Vec2 middlePos = Vec2(displaySize.width / 2, top->getPosition().y - top->getContentSize().height);
    middle->setPosition(middlePos);
    float middleScale = (height - top->getContentSize().height - bottom->getContentSize().height) / middle->getContentSize().height;
    middle->setScale(1, middleScale);
    Vec2 bottomPos = Vec2(displaySize.width / 2, middle->getPosition().y - middle->getContentSize().height * middle->getScaleY());
    bottom->setPosition(bottomPos);
    addChild(top, 1);
    addChild(middle, 1);
    addChild(bottom, 1);
    
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
