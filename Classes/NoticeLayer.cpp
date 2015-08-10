//
//  NoticeLayer.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#include "NoticeLayer.h"
#include "SoundManager.h"
#include "WorldManager.h"

NoticeLayer::NoticeLayer()
{
    
}

NoticeLayer::~NoticeLayer()
{
    
}

NoticeLayer* NoticeLayer::createWithMessage(std::string message)
{
    NoticeLayer* noticeLayer = new(std::nothrow) NoticeLayer();
    if (noticeLayer && noticeLayer->initWithMessage(message))
    {
        noticeLayer->autorelease();
        return noticeLayer;
    }
    
    CC_SAFE_DELETE(noticeLayer);
    return nullptr;
}

bool NoticeLayer::initWithMessage(std::string message)
{
    if (!ModalLayer::init()) {
        return false;
    }
    
    auto back = LayerColor::create(Color4B(0, 0, 0, 100));
    addChild(back, -1);
    
    this->setCascadeOpacityEnabled(true);
    
    auto displaySize = Director::getInstance()->getVisibleSize();
    auto node = CSLoader::createNode("Notice.csb");
    node->setAnchorPoint(Vec2(0.5f, 0.5f));
    node->setPosition(Vec2::ZERO);
    node->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    node->setCascadeOpacityEnabled(true);
    node->setOpacity(255);
    addChild(node, 10);
    
    _messageLabel = dynamic_cast<ui::Text*>(node->getChildByName("noticeMessage"));
    _messageLabel->setString(message);

    auto button = node->getChildByName<ui::Button*>("okButton");
    button->addTouchEventListener(CC_CALLBACK_2(NoticeLayer::_pushButton, this));

    return true;
}

void NoticeLayer::onEnter()
{
    Layer::onEnter();
}

void NoticeLayer::setFontSize(int fontsize)
{
    _messageLabel->setFontSize(fontsize);
}

void NoticeLayer::_pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
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
                if (closeNoticeCallback) {
                    closeNoticeCallback();
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
