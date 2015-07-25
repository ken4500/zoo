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
    
    
    auto startButton = rootNode->getChildByName<ui::Button*>("Start");
    startButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::_pushStartButton, this));

    auto languageButton = rootNode->getChildByName<ui::Button*>("Language");
    languageButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::_pushLanguageButton, this));

    auto creditButton = rootNode->getChildByName<ui::Button*>("Credit");
    creditButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::_pushCreditButton, this));
    
    addChild(rootNode);

    return true;
}

#pragma mark - View lifecycle

void TitleScene::onEnter()
{
    Layer::onEnter();
}

void TitleScene::onExit()
{
    Layer::onExit();
}

void TitleScene::_pushStartButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        Director::getInstance()->replaceScene(
            MainScene::createScene()
        );
    }
}

void TitleScene::_pushLanguageButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        auto layer = SelectLanguageLayer::create();
        this->addChild(layer);
    }
}

void TitleScene::_pushCreditButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
    }
}
