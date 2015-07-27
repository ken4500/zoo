//
//  SceneManager.cpp
//  Tetrominos
//
//  Created by Ken Watanabe on 2015/07/01.
//
//

#include "SceneManager.h"
#include "MainScene.h"
#include "TitleScene.h"
#include "MultiBattleScene.h"
#include "SoundManager.h"
using namespace cocos2d;

#pragma mark -
#pragma mark Lifecycle

static SceneManager* _instance = nullptr;
SceneManager* SceneManager::getInstance()
{
    if (_instance == nullptr) {
        _instance = new (std::nothrow)SceneManager();
    }
    return _instance;
}

SceneManager::SceneManager()
{
    _mainScene = NULL;
    _isNetwork = false;
}

SceneManager::~SceneManager()
{
}

#pragma mark -
#pragma mark Public Methods

void SceneManager::enterMainScene()
{
    _mainScene = MainScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(1.0f, _mainScene, Color3B::BLACK)
    );
}

void SceneManager::resetMainScene()
{
    _mainScene = MainScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(1.0f, _mainScene, Color3B::BLACK)
    );
}

MainScene* SceneManager::getMainScene()
{
    if (_mainScene) {
        return _mainScene->getChildByName<MainScene*>("main scene");
    } else {
        return NULL;
    }
}

void SceneManager::enterMultiBattleScene()
{
    _isNetwork = true;
    _mainScene = MultiBattleScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(1.0f, _mainScene, Color3B::BLACK)
    );
}

void SceneManager::backMainScene()
{
    _isNetwork = false;
    _mainScene = MainScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(1.0f, _mainScene, Color3B::BLACK)
    );
}


bool SceneManager::isNetwork()
{
    return _isNetwork;
}

