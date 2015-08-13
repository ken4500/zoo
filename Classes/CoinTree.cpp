//
//  CoinTree.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#include "CoinTree.h"
#include "WorldManager.h"
#include "Animal.h"
#include "SoundManager.h"
#include "UserDataManager.h"

bool CoinTree::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    _timeline = CSLoader::createTimeline("CoinTree.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    _preDropPos = -1;
    _dropCount = 8;
    _isSwaying = false;
    _id = rand() % 1000000;
    _isDead = false;
    _isCreatedByOpponent = false;

    return true;
}

void CoinTree::onEnter()
{
    Node::onEnter();
    _image = getChildByName<Sprite*>("image");

    _dropListNode = getChildByName("dropList");
    _dropPointList = std::vector<cocos2d::Node*>();
    for (auto point : _dropListNode->getChildren()) {
        _dropPointList.push_back(point);
    }

    if (_length) {
        float scale = WorldManager::getInstance()->getImageScale(_image, *_length);
        setScale(scale);
    }
    
    setTag((int)EntityTag::CoinTree);
    runAction(_timeline);
    _timeline->play("default", false);
}

void CoinTree::setLength(Length length)
{
    _length = new Length(length.getMmLength());
    _dropCoin = (int)(length.getLength(UnitOfLength::cm) * UserDataManager::getInstance()->getCoinRate());
    _dropCoin = MAX(1, _dropCoin);

    _maxHp = powf(length.getMmLength() * 4, 1.2f);
    _hp = _maxHp;
    if (_image) {
        float scale = WorldManager::getInstance()->getImageScale(_image, *_length);
        setScale(scale);
    }
}

Length CoinTree::getLength()
{
    return *_length;
}

void CoinTree::sprout()
{
    _timeline->play("sprout", false);
}

void CoinTree::sway()
{
    _isSwaying = true;
    _timeline->play("sway", false);
    _timeline->setLastFrameCallFunc([this]{
        _isSwaying = false;
    });
}

void CoinTree::dropCoin()
{
    WorldManager::getInstance()->addCoin(_dropCoin);
    SoundManager::getInstance()->playGetCoinEffect();

    auto dropCoin = CSLoader::createNode("DropCoin.csb");
    int rnd;
    do {
        rnd = rand() % _dropPointList.size();
    } while (_preDropPos == rnd);
    
    _preDropPos = rnd;
    auto dropPoint = _dropPointList[rnd];
    auto position = dropPoint->getPosition() + _dropListNode->getPosition();
    position *= getScale();
    position += getPosition();
    dropCoin->setScale(getScale() * 0.6f);
    dropCoin->setPosition(position);
    getParent()->addChild(dropCoin, 10000);
    dropCoin->getChildByName<ui::TextBMFont*>("text")->setString(StringUtils::format("+%d", _dropCoin));
    
    auto timeline = CSLoader::createTimeline("DropCoin.csb");
    dropCoin->runAction(timeline);
    timeline->play("drop", false);
    timeline->setLastFrameCallFunc([this, dropCoin]{
        dropCoin->removeFromParent();
    });
}

void CoinTree::fellDown(bool drop)
{
    if (isDead()) {
        return;
    }
    
    _hp = 0;
    _timeline->play("fall", false);
    _isDead = true;
    if (deadCallback) {
        deadCallback(this);
    }
    
    if (drop) {
        for (int i = 0; i < 8; i++) {
            runAction(Sequence::create(
                DelayTime::create(0.1 * i),
                CallFunc::create([this]{
                    dropCoin();
                }),
                NULL
            ));
        }
    }
    
    runAction(Sequence::create(DelayTime::create(5.0f), RemoveSelf::create(), NULL));
}

Rect CoinTree::getBodyRect()
{
    auto imageRect = _image->getBoundingBox();
    imageRect.origin *= getScale();
    imageRect.origin += getPosition();
    imageRect.size = imageRect.size * getScale();
    
    return imageRect;
}

bool CoinTree::addDamage(float damage, Animal* animal)
{
    if (_hp == 0 || isDead()) {
        return false;
    }
    
    if (animal->isOpponent() == false) {
        for (int i = 1; i < _dropCount; i++) {
            int threshold = int(i * _maxHp / _dropCount);
            if (threshold < _hp && _hp <= threshold + damage) {
                dropCoin();
            }
        }
    }
    
    if (0 < _hp && _hp <= damage) {
        _hp = 0;
        fellDown(true);
        return true;
    }
    if (_isSwaying == false) {
        sway();
    }
    _hp -= damage;
    return false;
}

void CoinTree::disappear()
{
    if (_hp > 0) {
        _timeline->play("disappear", false);
        _timeline->setLastFrameCallFunc([this]{
            removeFromParent();
        });
    } else {
        removeFromParent();
    }
}

bool CoinTree::isDead()
{
    return _isDead;
}

int CoinTree::getId()
{
    return _id;
}

void CoinTree::setId(int id)
{
    _id = id;
}

Vec2 CoinTree::getRealPosition()
{
    auto info = WorldManager::getInstance()->getWorldInfo();
    auto pos = getPosition();
    float x = pos.x * info->maxWidth.getMmLength() / info->imageWidth;
    float y = pos.y * info->maxWidth.getMmLength() / info->imageWidth;
    return Vec2(x, y);
}

void CoinTree::setRealPosition(Vec2 position)
{
    auto info = WorldManager::getInstance()->getWorldInfo();
    float x = position.x * info->imageWidth / info->maxWidth.getMmLength();
    float y = position.y * info->imageWidth / info->maxWidth.getMmLength();
    setPosition(Vec2(x, y));
}

bool CoinTree::isCreatedByOpponent()
{
    return _isCreatedByOpponent;
}

void CoinTree::setIsCreatedByOpponent(bool opponent)
{
    _isCreatedByOpponent = opponent;
}
