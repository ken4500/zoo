#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Gacha.h"
#include "GachaReader.h"
#include "ScaleBar.h"
#include "ScaleBarReader.h"
#include "Animal.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
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

    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("GachaReader", (ObjectFactory::Instance) GachaReader::getInstance);
    instance->registReaderObject("ScaleBarReader", (ObjectFactory::Instance) ScaleBarReader::getInstance);

    auto rootNode = CSLoader::createNode("MainScene.csb");
    this->gacha = rootNode->getChildByName<Gacha*>("gacha");
    this->gacha->finishGachaCallback = CC_CALLBACK_1(MainScene::releaseAnimal, this);

    addChild(rootNode);

    return true;
}

void MainScene::onEnter()
{
    Layer::onEnter();
    this->setupTouchHandling();
    this->scheduleUpdate();
}

void MainScene::update(float dt)
{
    Layer::update(dt);
    
    for(auto node : this->getChildren()) {
        if (node->getTag() == (int)MainSceneTag::Animal) {
            node->setLocalZOrder(1000 - (int)node->getPosition().y);
        }
    }
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

void MainScene::releaseAnimal(Animal* animal)
{
    animal->setPosition(this->gacha->getPosition());
    animal->runAction(JumpTo::create(1, ZUtil::getRadomPlace(), 100, 1));
    this->addChild(animal);
}

void MainScene::levelup()
{
    cocostudio::timeline::ActionTimeline* titleTimeline = CSLoader::createTimeline("MainScene.csb");
    this->stopAllActions();
    this->runAction(titleTimeline);
    titleTimeline->play("goToStage2", false);
    titleTimeline->setLastFrameCallFunc([this](){
    });
    
//    for (auto animal : this->animals) {
//        this->scaleDown(animal, 0.4f);
//    }
}

void MainScene::scaleDown(Node* node, float scale)
{
    Vec2 newPos = node->getPosition() * 0.4;

    node->runAction(Sequence::create(
        DelayTime::create(1.3f),
        Spawn::create(
            EaseSineInOut::create(ScaleBy::create(1.18f, scale)),
            EaseSineInOut::create(MoveTo::create(1.18f, newPos)),
            NULL
        ),
        NULL
    ));
}

