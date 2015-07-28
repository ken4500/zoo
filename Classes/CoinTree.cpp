//
//  CoinTree.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/27.
//
//

#include "CoinTree.h"
#include "WorldManager.h"

bool CoinTree::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    _timeline = CSLoader::createTimeline("CoinTree.csb");
    // retain the character animation timeline so it doesn't get deallocated
    _timeline->retain();
    _preDropPos = -1;

    return true;
}

void CoinTree::onEnter()
{
    Node::onEnter();
    _image = getChildByName("image")->getChildByName<Sprite*>("top");

    _dropListNode = getChildByName("dropList");
    _dropPointList = std::vector<cocos2d::Node*>();
    for (auto point : _dropListNode->getChildren()) {
        _dropPointList.push_back(point);
    }

    if (_length) {
        float scale = WorldManager::getInstance()->getImageScale(_image, _length);
        setScale(scale);
    }
}

void CoinTree::setLength(Length* length)
{
    _length = length;
    _dropCoin = MAX(1, (int)length->getLength(UnitOfLength::cm));
    _hp = length->getMmLength() * 3;
    if (_image) {
        float scale = WorldManager::getInstance()->getImageScale(_image, _length);
        setScale(scale);
    }
}

void CoinTree::sprout()
{
    stopAllActions();
    runAction(_timeline);
    _timeline->play("sprout", false);
}

void CoinTree::sway()
{
    stopAllActions();
    runAction(_timeline);
    _timeline->play("sway", true);
}

void CoinTree::dropCoin()
{
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
}

void CoinTree::fellDown()
{
    stopAllActions();
    runAction(_timeline);
    _timeline->play("fall", false);
    
    for (int i = 0; i < 5; i++) {
        runAction(Sequence::create(
            DelayTime::create(0.1 * i),
            CallFunc::create([this]{
                dropCoin();
            }),
            NULL
        ));
    }
}

Rect CoinTree::getBodyRect()
{
    auto imageRect = _image->getBoundingBox();
    imageRect.origin *= getScale();
    imageRect.origin += getPosition();
    imageRect.size = imageRect.size * getScale();
    return imageRect;
}

bool CoinTree::addDamage(float damage)
{
    if (_hp == 0) {
        return false;
    }
    if (_hp > 0 && _hp - damage <= 0) {
        _hp = 0;
        fellDown();
        return true;
    }
    _hp -= damage;
    return false;
}

void CoinTree::disappear()
{
    if (_hp > 0) {
        stopAllActions();
        runAction(_timeline);
        _timeline->play("disappear", false);
        _timeline->setLastFrameCallFunc([this]{
            removeFromParent();
        });
    } else {
        removeFromParent();
    }
}


