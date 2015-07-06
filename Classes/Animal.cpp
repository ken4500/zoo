//
//  Animal.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#include "Animal.h"
#include "WorldManager.h"

Animal::Animal() :
_height(Length(UnitOfLength::mm, 1))
{
}

Animal* Animal::CreateWithSpeceis(AbstractSpecies* species)
{
    Animal* animal = new(std::nothrow) Animal();
    if (animal && animal->initWithSpeceis(species))
    {
        animal->autorelease();
        return animal;
    }
    
    CC_SAFE_DELETE(animal);
    return nullptr;

}

bool Animal::initWithSpeceis(AbstractSpecies* species)
{
    if (!Node::init()) {
        return false;
    }
    
    _species = species;
    float rnd = CCRANDOM_0_1();
    float mm = (species->getMaxHeight().getMmLength() - species->getMinHeight().getMmLength()) * rnd + species->getMinHeight().getMmLength();
    _height = Length(UnitOfLength::mm, mm);

    _rootNode = CSLoader::createNode(_species->getMoveCsbName());
    this->addChild(_rootNode);

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline(species->getMoveCsbName());
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();
    
    _image = _rootNode->getChildByName<Sprite*>("image");
    _changeAnimalImage();

    return true;
}

void Animal::onEnter()
{
    Node::onEnter();
    updateWorldScale();
    _startWalk();
}

Length Animal::getHeight()
{
    return _height;
}

Length Animal::getSpeed()
{
    return _species->getSpeed();
}

std::string Animal::getName()
{
    return _name;
}

void Animal::updateWorldScale()
{
    float scale = this->getWorldScale();
    this->setScale(scale);
}

float Animal::getWorldScale()
{
    float scale = WorldManager::getInstance()->getImageScale(_image, _height);
    return scale;
}


void Animal::_startWalk()
{
    this->runAction(this->timeline);
    this->timeline->play("walk", true);
    _moveNextPoint();
}

void Animal::_moveNextPoint()
{
    Vec2 targetP = ZUtil::getRadomPlace();
    Vec2 move = targetP - this->getPosition();
    float speed = WorldManager::getInstance()->getDisplayLength(getSpeed());
    float duration = move.length() / speed;
    if (move.x < 0) {
        _image->setFlippedX(false);
    } else {
        _image->setFlippedX(true);
    }
    this->runAction(Sequence::create(
        MoveBy::create(duration, move),
        CallFunc::create([this](){
            _moveNextPoint();
        }),
        NULL
    ));
}

void Animal::_changeAnimalImage()
{
    _image->setTexture(_species->getImageName());
}

