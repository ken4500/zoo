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

    return true;
}

void CoinTree::onEnter()
{
    Node::onEnter();
    
    _image = getChildByName<Sprite*>("image");
}

void CoinTree::setLength(Length* length)
{
    float scale = WorldManager::getInstance()->getImageScale(_image, length);
    setScale(scale);
}

