//
//  Animal.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/29.
//
//

#include "Animal.h"
#include "AnimalReader.h"

bool Animal::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Ant.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();
    
    this->speed = 50.0f;
    this->size  = 10.0f;
    this->setScale(0.3);

    return true;
}

void Animal::onEnter()
{
    Node::onEnter();
    this->startWalk();
}


void Animal::startWalk()
{
    this->runAction(this->timeline);
    this->timeline->play("walk", true);
    this->moveNextPoint();
}

void Animal::moveNextPoint()
{
    auto image = getChildByName<Sprite*>("image");
    Vec2 targetP = ZUtil::getRadomPlace();
    Vec2 move = targetP - this->getPosition();
    float duration = move.length() / this->speed;
    if (move.x < 0) {
        image->setFlippedX(false);
    } else {
        image->setFlippedX(true);
    }
    this->runAction(Sequence::create(
        MoveBy::create(duration, move),
        CallFunc::create([this](){
            this->moveNextPoint();
        }),
        NULL
    ));

}

