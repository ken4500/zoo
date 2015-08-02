//
//  MultiplayResult.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/01.
//
//

#include "MultiplayResult.h"
#include "SoundManager.h"
#include "WorldManager.h"

MultiplayResult::MultiplayResult()
{
    
}

MultiplayResult::~MultiplayResult()
{
    
}

MultiplayResult* MultiplayResult::create()
{
    MultiplayResult* multiplayResult = new(std::nothrow) MultiplayResult();
    if (multiplayResult && multiplayResult->init())
    {
        multiplayResult->autorelease();
        return multiplayResult;
    }
    
    CC_SAFE_DELETE(multiplayResult);
    return nullptr;
}

bool MultiplayResult::init()
{
    // 評価
    int height = 450;

    if (!ModalLayer::initWithHeight(height)) {
        return false;
    }
    
    this->setCascadeOpacityEnabled(true);
    
    auto displaySize = Director::getInstance()->getVisibleSize();
    auto node = CSLoader::createNode("MultiplayResult.csb");
    node->setAnchorPoint(Vec2(0.5f, 0.5f));
    node->setPosition(Vec2::ZERO);
    node->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    node->setCascadeOpacityEnabled(true);
    node->setOpacity(255);
    addChild(node, 10);
    
    _playerName     = node->getChildByName<ui::Text*>("playerName");
    _opponentName   = node->getChildByName<ui::Text*>("opponentName");
    _playerWeight   = node->getChildByName<ui::TextBMFont*>("playerWeight");
    _opponentWeight = node->getChildByName<ui::TextBMFont*>("opponentWeight");
    _playerResult   = node->getChildByName<ui::TextBMFont*>("playerResult");
    _opponentResult = node->getChildByName<ui::TextBMFont*>("opponentResult");
    
    
    auto button = node->getChildByName<ui::Button*>("okButton");
    button->addTouchEventListener(CC_CALLBACK_2(MultiplayResult::_pushButton, this));
    
    return true;
}

void MultiplayResult::onEnter()
{
    Layer::onEnter();
}

void MultiplayResult::_pushButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        this->runAction(Sequence::create(
            FadeOut::create(0.3f),
            CallFunc::create([this]{
                if (closeResultCallback) {
                    closeResultCallback();
                }
            }),
            RemoveSelf::create(),
            NULL
        ));
        WorldManager::getInstance()->endResult();
    }
}

void MultiplayResult::setResult(GameResult result)
{
//    _playerName->setString(result.playerName);
//    _opponentName->setString(result.opponentName);

    _playerWeight->setString(StringUtils::format("%.02f %s", result.playerWeight.getWeight(), result.playerWeight.getUnitStr().c_str()));
    _opponentWeight->setString(StringUtils::format("%.02f %s", result.opponentWeight.getWeight(), result.opponentWeight.getUnitStr().c_str()));
    
    if (result.resultState == BattleState::Win) {
        _playerResult->setString("WIN");
        _opponentResult->setString("LOSE");
    } else {
        _playerResult->setString("LOSE");
        _opponentResult->setString("WIN");
    }
}

