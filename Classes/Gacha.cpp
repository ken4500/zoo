//
//  Gacha.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#include "Gacha.h"

bool Gacha::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Gacha.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    return true;
}

void Gacha::onEnter()
{
    Node::onEnter();
    this->setupTouchHandling();
}


void Gacha::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        auto image = this->getChildByName<Sprite*>("image");
        Rect targetBox = image->getBoundingBox();
        targetBox.origin = image->convertToWorldSpaceAR(targetBox.origin);
     
        Point location = touch->getLocationInView();
        auto touchLocation = Director::getInstance()->convertToGL(location);
        
     
        //touchPointがtargetBoxの中に含まれているか判定
        if (targetBox.containsPoint(touchLocation))
        {
            this->finishGachaCallback();
        }
        return true;
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}
