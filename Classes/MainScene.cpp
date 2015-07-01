#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Gacha.h"
#include "GachaReader.h"
#include "AnimalReader.h"
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
    instance->registReaderObject("AnimalReader", (ObjectFactory::Instance) AnimalReader::getInstance);

    auto rootNode = CSLoader::createNode("MainScene.csb");
    this->gacha = rootNode->getChildByName<Gacha*>("gacha");
    this->gacha->finishGachaCallback = CC_CALLBACK_0(MainScene::releaseAnimal, this);


    this->debugLabel = Label::createWithSystemFont("0", "HiraMinProN-W6", 36);
    this->debugLabel->setColor(Color3B::BLACK);
    this->debugLabel->setPosition(Vec2(500, 50));
    rootNode->addChild(this->debugLabel);
    std::srand((int)time(NULL));

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

void MainScene::releaseAnimal()
{
    if (_enableGacha == false) {
        return;
    }
    float rnd = rand_0_1();
    std::string name;
    float jump;
    float scale;
    if (_level == 1) {
        if (rnd > 0.05) {
            name = "Ant.csb";
            scale = 0.3f;
            jump = 100;
        } else {
            name = "Beetle.csb";
            scale = 0.8f;
            jump = 400;
            _enableGacha = false;
            runAction(Sequence::create(
                DelayTime::create(1.0f),
                CallFunc::create([this](){this->levelup();}),
                NULL
            ));
        }
    } else {
        if (rnd > 0.05) {
            name = "Beetle.csb";
            scale = 0.32f;
            jump = 100;
        } else {
            name = "Dog.csb";
            scale = 0.8f;
            jump = 400;
        }
    }

    auto animal = dynamic_cast<Animal*>(CSLoader::createNode(name));
    animal->setPosition(this->gacha->getPosition());
    animal->runAction(JumpTo::create(1, ZUtil::getRadomPlace(), jump, 1));
    animal->setScale(scale);
    animal->setTag((int)MainSceneTag::Animal);
    this->animals.pushBack(animal);
    this->addChild(animal);
    
    this->debugLabel->setString(std::to_string(this->animals.size()).c_str());
}

void MainScene::levelup()
{
    _level++;
    cocostudio::timeline::ActionTimeline* titleTimeline = CSLoader::createTimeline("MainScene.csb");
    this->stopAllActions();
    this->runAction(titleTimeline);
    titleTimeline->play("goToStage2", false);
    titleTimeline->setLastFrameCallFunc([this](){
        _enableGacha = true;
    });
    
    for (auto animal : this->animals) {
        this->scaleDown(animal, 0.4f);
    }
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

