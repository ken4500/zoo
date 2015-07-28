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
    _scene = NULL;
    _isNetwork = false;
}

SceneManager::~SceneManager()
{
}

#pragma mark -
#pragma mark Public Methods

void SceneManager::enterMainScene()
{
    _scene = MainScene::createScene();
    Director::getInstance()->replaceScene(_scene);

//    Director::getInstance()->replaceScene(
//        TransitionFade::create(1.0f, _scene, Color3B::BLACK)
//    );
}

void SceneManager::resetMainScene()
{
    _scene = MainScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(1.0f, _scene, Color3B::BLACK)
    );
}

MainScene* SceneManager::getMainScene()
{
    if (_scene) {
        return dynamic_cast<MainScene*>(_scene->getChildByName("world scene"));
    } else {
        return NULL;
    }
}

MultiBattleScene* SceneManager::getMultiBattleScene()
{
    if (_scene) {
        return dynamic_cast<MultiBattleScene*>(_scene->getChildByName("world scene"));
    } else {
        return NULL;
    }
}

WorldSceneInterface* SceneManager::getWorldScene()
{
    if (_scene) {
        return dynamic_cast<WorldSceneInterface*>(_scene->getChildByName("world scene"));
    } else {
        return NULL;
    }
}

void SceneManager::enterMultiBattleScene()
{
    _isNetwork = true;
    _scene = MultiBattleScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(1.0f, _scene, Color3B::BLACK)
    );
}

void SceneManager::backMainScene()
{
    _isNetwork = false;
    _scene = MainScene::createScene();
    Director::getInstance()->replaceScene(
        TransitionFade::create(1.0f, _scene, Color3B::BLACK)
    );
}


bool SceneManager::isNetwork()
{
    return _isNetwork;
}

