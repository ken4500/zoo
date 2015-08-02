//
//  YesNoLayer.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/31.
//
//

#include "YesNoLayer.h"
#include "SoundManager.h"
#include "WorldManager.h"

YesNoLayer::YesNoLayer()
{
    
}

YesNoLayer::~YesNoLayer()
{
    
}

YesNoLayer* YesNoLayer::createWithMessage(std::string message)
{
    YesNoLayer* layer = new(std::nothrow) YesNoLayer();
    if (layer && layer->initWithMessage(message))
    {
        layer->autorelease();
        return layer;
    }
    
    CC_SAFE_DELETE(layer);
    return nullptr;
}

bool YesNoLayer::initWithMessage(std::string message)
{
    int height = 400;

    if (!ModalLayer::initWithHeight(height)) {
        return false;
    }
    
    this->setCascadeOpacityEnabled(true);
    
    auto displaySize = Director::getInstance()->getVisibleSize();
    auto node = CSLoader::createNode("YesNo.csb");
    node->setAnchorPoint(Vec2(0.5f, 0.5f));
    node->setPosition(Vec2::ZERO);
    node->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    node->setCascadeOpacityEnabled(true);
    node->setOpacity(255);
    addChild(node, 10);
    
    auto messageLabel = dynamic_cast<ui::Text*>(node->getChildByName("noticeMessage"));
    messageLabel->setString(message);

    ZUtil::printNode(node);

    auto yes = node->getChildByName<ui::Button*>("yesButton");
    yes->addTouchEventListener(CC_CALLBACK_2(YesNoLayer::_pushYesButton, this));
    auto no = node->getChildByName<ui::Button*>("noButton");
    no->addTouchEventListener(CC_CALLBACK_2(YesNoLayer::_pushNoButton, this));

    return true;
}

void YesNoLayer::onEnter()
{
    Layer::onEnter();
}

void YesNoLayer::_pushYesButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
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
}

void YesNoLayer::_pushNoButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
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
}