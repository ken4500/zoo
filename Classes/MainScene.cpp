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

    auto rootNode = CSLoader::createNode("MainScene.csb");
    rootNode->setAnchorPoint(Vec2(0.5f, 0.5f));
    rootNode->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));

    _map = WorldManager::getInstance()->getMap();
    _map->setAnchorPoint(Vec2(0.5f, 0.5f));
    _map->setPosition(Vec2(displaySize.width / 2, displaySize.height / 2));
    _map->scaleupCallback = CC_CALLBACK_1(MainScene::levelup, this);
    rootNode->addChild(_map);

    _gacha = rootNode->getChildByName<Gacha*>("gacha");
    _gacha->retain();
    _gacha->removeFromParent();
    _map->setGacha(_gacha);
    _gacha->release();


    addChild(rootNode);

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


void MainScene::levelup(WorldMap* map)
{
   // WorldManager::getInstance()->levelup();
}

