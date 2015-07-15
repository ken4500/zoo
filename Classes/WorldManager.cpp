//
//  WorldManager.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/02.
//
//

#include "WorldManager.h"
#include "Gacha.h"

USING_NS_CC;

static WorldManager* sharedWorldManager;
WorldManager* WorldManager::getInstance()
{
    if (!sharedWorldManager) {
        sharedWorldManager = new WorldManager();
    }

    return sharedWorldManager;
}

#pragma mark - Constructor and Destructor

WorldManager::WorldManager()
{
    _level = 3;
    _info = _loadWoldInfo(_level);
    _map = nullptr;
    _enableNextAction = true;
}

WorldManager::~WorldManager()
{
}


#pragma - getter / setter

int WorldManager::getGachaId()
{
    return _info->gachaId;
}

WorldInfo* WorldManager::getWorldInfo()
{
    return _info;
}

WorldMap* WorldManager::getMap()
{
    if (_map == nullptr) {
        _map = dynamic_cast<WorldMap*>(CSLoader::createNode(_info->mapName));
        _map->initSize(_info->maxWidth, _info->width);
    
        _gacha = dynamic_cast<Gacha*>(CSLoader::createNode("Gacha.csb"));
        auto gachaImage = _gacha->getChildByName<Sprite*>("image");
        auto gachaLength = Length::scale(_info->width, 0.2);
        float gachaScale = getImageScale(gachaImage, gachaLength);
        _gacha->setScale(gachaScale);
        _map->setGacha(_gacha);
    }
    return _map;
}

float WorldManager::getImageScale(Sprite* image, Length* width)
{
    auto contentSize = image->getContentSize();
    float scale = (width->getLength(UnitOfLength::mm) * _info->imageWidth) / (_info->maxWidth->getLength(UnitOfLength::mm) * contentSize.width);
    return scale;
}

float WorldManager::getDisplayLength(Length* length)
{
    auto worldSize = getWorldInfo()->width;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    return (length->getLength(UnitOfLength::mm) * visibleSize.width) / worldSize->getLength(UnitOfLength::mm);
}

Length* WorldManager::getLength(float displayLength)
{
    auto worldSize = getWorldInfo()->width;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float mm = worldSize->getLength(UnitOfLength::mm) * displayLength / visibleSize.width;
    return new Length(UnitOfLength::mm, mm);
}

bool WorldManager::enableNextAction()
{
    return _enableNextAction;
}

void WorldManager::setEnableNextAction(bool enable)
{
    _enableNextAction = enable;
}

#pragma - public method

void WorldManager::releaseAnimal(Animal* animal, bool hit)
{
    if (hit) {
        _map->releaseAnimal(animal, [this] { levelup(); });
    } else {
        _map->releaseAnimal(animal, nullptr);
    }
}

WorldInfo* WorldManager::levelup()
{
    _level++;
    auto newWorldInfo = _loadWoldInfo(_level);
    if (newWorldInfo->mapName == _info->mapName) {
        _map->setCurrentWidth(newWorldInfo->width);
    } else {
        
        
    }
    
    auto mainScene = _getMainScene();
    if (mainScene) {
        mainScene->levelUpEffect();
    }
    
    auto gachaImage = _gacha->getChildByName<Sprite*>("image");
    auto gachaLength = Length::scale(newWorldInfo->width, 0.2);
    float gachaScale = getImageScale(gachaImage, gachaLength);
    _gacha->runAction(EaseInOut::create(ScaleTo::create(1.0f, gachaScale), 2));

    
    _info = newWorldInfo;
    return _info;
}

Vec2 WorldManager::getRadomPlace()
{
    auto back = _map->getChildByName<Sprite*>("background");
    auto imageSize = back->getContentSize();
    auto displaySize = Director::getInstance()->getVisibleSize();
    float w = imageSize.width * _info->width->getMmLength() / _info->maxWidth->getMmLength();
    float h = w * displaySize.height / displaySize.width;
    float x = w * rand_0_1() - w / 2;
    float y = h * rand_0_1() - h / 2;
    return Vec2(x, y);

}


#pragma - private method

WorldInfo* WorldManager::_loadWoldInfo(int level)
{
    WorldInfo* info = new WorldInfo(level);
    return info;
}

MainScene* WorldManager::_getMainScene()
{
    auto scene = Director::getInstance()->getRunningScene();
    return scene->getChildByName<MainScene*>("main scene");
}

