#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Gacha.h"
#include "GachaReader.h"
#include "ScaleBar.h"
#include "ScaleBarReader.h"
#include "WorldMap.h"
#include "WorldMapReader.h"
#include "WorldManager.h"
#include "Animal.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    // "scene" is an autorelease object
    auto scene = Scene::create();
    
    // "layer" is an autorelease object
    auto layer = MainScene::create();
    layer->setName("main scene");

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto displaySize = Director::getInstance()->getVisibleSize();

    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("GachaReader", (ObjectFactory::Instance) GachaReader::getInstance);
    instance->registReaderObject("ScaleBarReader", (ObjectFactory::Instance) ScaleBarReader::getInstance);
    instance->registReaderObject("WorldMapReader", (ObjectFactory::Instance) WorldMapReader::getInstance);

    _rootNode = CSLoader::createNode("MainScene.csb");
    _rootNode->setAnchorPoint(Vec2(0.5f, 0.5f));
    _rootNode->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));

    _map = WorldManager::getInstance()->getMap();
    _map->setAnchorPoint(Vec2(0.5f, 0.5f));
    _map->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    _map->setLocalZOrder(-1);
    _rootNode->addChild(_map);

    // load the character animation timeline
    _timeline = CSLoader::createTimeline("MainScene.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();

    addChild(_rootNode);

    return true;
}

void MainScene::onEnter()
{
    Layer::onEnter();
    this->setupTouchHandling();
}

void MainScene::update(float dt)
{
    Layer::update(dt);
}

void MainScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        return true;
    };

    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void MainScene::levelUpEffect()
{
    this->stopAllActions();
    this->runAction(_timeline);
    _timeline->play("zoomout1", false);
    _timeline->setLastFrameCallFunc([](){ WorldManager::getInstance()->setEnableNextAction(true); });
}

void MainScene::transitionMap(WorldMap* newMap)
{
    auto displaySize = Director::getInstance()->getVisibleSize();
    newMap->setAnchorPoint(Vec2(0.5f, 0.5f));
    newMap->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    newMap->setLocalZOrder(-2);
    _rootNode->addChild(newMap);
    newMap->runAction(Sequence::create(
        DelayTime::create(1.0f),
        CallFunc::create([newMap]{
            newMap->setLocalZOrder(-1);
        }),
        NULL
    ));
    _map->runAction(Sequence::create(
        FadeOut::create(1.0f),
        RemoveSelf::create(),
        NULL
    ));
    _map = newMap;
}

