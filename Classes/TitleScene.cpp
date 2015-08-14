//
//  TitleScene.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/24.
//
//

#include "TitleScene.h"
#include "MainScene.h"
#include "SelectLanguageLayer.h"
#include "CreditLayer.h"
#include "SoundManager.h"
#include "SceneManager.h"
#include "UserDataManager.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
    // "scene" is an autorelease object
    auto scene = Scene::create();
    
    // "layer" is an autorelease object
    auto layer = TitleScene::create();
    layer->setName("title scene");

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool TitleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto displaySize = Director::getInstance()->getVisibleSize();

    auto rootNode = CSLoader::createNode("TitleScene.csb");
    rootNode->setAnchorPoint(Vec2(0.5f, 0.5f));
    rootNode->setPosition(Vec2::ZERO);
    rootNode->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    
    auto glove = rootNode->getChildByName("glove");
    glove->runAction(RepeatForever::create(RotateBy::create(60.0, 360)));
    
    auto startButton = rootNode->getChildByName<ui::Button*>("Start");
    startButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::_pushStartButton, this));
    _startLabel = startButton->getChildByName<ui::TextBMFont*>("label");

    auto languageButton = rootNode->getChildByName<ui::Button*>("Language");
    languageButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::_pushLanguageButton, this));
    _languageLabel = languageButton->getChildByName<ui::TextBMFont*>("label");

    auto creditButton = rootNode->getChildByName<ui::Button*>("Credit");
    creditButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::_pushCreditButton, this));
    _creditLabel = creditButton->getChildByName<ui::TextBMFont*>("label");
    
    _updateLanguage();
    
    addChild(rootNode);

    return true;
}

#pragma mark - View lifecycle

void TitleScene::onEnter()
{
    Layer::onEnter();
    SoundManager::getInstance()->playTitleBgm();
}

void TitleScene::onExit()
{
    Layer::onExit();
}

void TitleScene::_pushStartButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        SoundManager::getInstance()->fadeOutBgm(1.0f);
        button->setEnabled(false);
        button->runAction(Sequence::create(
            ScaleBy::create(0.1f, 1 / 0.9f),
            CallFunc::create([button]{
                button->setEnabled(true);
                SceneManager::getInstance()->enterMainScene();
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void TitleScene::_pushLanguageButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleTo::create(0.1f, 0.8f * 0.9f));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->setEnabled(false);
        button->runAction(Sequence::create(
            ScaleTo::create(0.1f, 0.8f),
            CallFunc::create([this, button]{
                button->setEnabled(true);
                auto layer = SelectLanguageLayer::create();
                layer->closedCallback = [this]() {
                    _updateLanguage();
                };
                this->addChild(layer);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleTo::create(0.1f, 0.8f));
    }
}

void TitleScene::_pushCreditButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleTo::create(0.1f, 0.8f * 0.9f));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->setEnabled(false);
        button->runAction(Sequence::create(
            ScaleTo::create(0.1f, 0.8f),
            CallFunc::create([this, button]{
                button->setEnabled(true);
                auto layer = CreditLayer::create();
                this->addChild(layer);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleTo::create(0.1f,  0.8f));
    }
}

void TitleScene::_updateLanguage()
{
    PurgeCCLocalizedStringCached();
    _startLabel->setString(CCLS1("TITLE_SCENE_START",_startLabel));
    _languageLabel->setString(CCLS1("TITLE_SCENE_LANGUAGE",_languageLabel));
    _creditLabel->setString(CCLS1("TITLE_SCENE_CREDIT",_creditLabel));
    
    LanguageType curLanguage = UserDataManager::getInstance()->getLanguage();
    if (curLanguage == LanguageType::CHINESE) {
        _startLabel->setAnchorPoint(Vec2(0.5,0.65));
    } else {
        _startLabel->setAnchorPoint(Vec2(0.5,0.5));
    }
}
