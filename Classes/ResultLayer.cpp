//
//  ResultLayer.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/18.
//
//

#include "ResultLayer.h"
#include "SoundManager.h"
#include "WorldManager.h"

ResultLayer::ResultLayer()
{
    
}

ResultLayer::~ResultLayer()
{
    
}

ResultLayer* ResultLayer::createWithResult(GameResult* result)
{
    ResultLayer* resultLayer = new(std::nothrow) ResultLayer();
    if (resultLayer && resultLayer->initWithResult(result))
    {
        resultLayer->autorelease();
        return resultLayer;
    }
    
    CC_SAFE_DELETE(resultLayer);
    return nullptr;
}

bool ResultLayer::initWithResult(GameResult* result)
{
    // 評価
    _result = result;
    int height = 450;

    if (!ModalLayer::initWithHeight(height)) {
        return false;
    }
    
    this->setCascadeOpacityEnabled(true);
    
    auto displaySize = Director::getInstance()->getVisibleSize();
    auto node = CSLoader::createNode("Result.csb");
    node->setAnchorPoint(Vec2(0.5f, 0.5f));
    node->setPosition(Vec2::ZERO);
    node->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    node->setCascadeOpacityEnabled(true);
    node->setOpacity(255);
    addChild(node, 10);

    
    
    auto title = node->getChildByName<ui::TextBMFont*>("title");
    if (result->resultState == BattleState::Win) {
        title->setString("WIN");
    } else {
        title->setString("LOSE");
    }
    
    auto timeLabel = node->getChildByName<ui::TextBMFont*>("timeLabel");
    timeLabel->setString(StringUtils::format("%d:%d", int(result->playTime / 60), int(result->playTime) % 60));
    auto coinLabel = node->getChildByName<ui::TextBMFont*>("coinLabel");
    coinLabel->setString(StringUtils::format("x %d", result->getCoin));

    auto button = node->getChildByName<ui::Button*>("okButton");
    button->addTouchEventListener(CC_CALLBACK_2(ResultLayer::_pushButton, this));

    
    return true;
}

void ResultLayer::onEnter()
{
    Layer::onEnter();
}

void ResultLayer::_pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    this->runAction(Sequence::create(FadeOut::create(0.3f), RemoveSelf::create() , NULL));
    WorldManager::getInstance()->endResult();
}
