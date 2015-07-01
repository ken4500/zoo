//
//  ZUtil.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/30.
//
//

#include "ZUtil.h"
#include "ZMath.h"

Vec2 ZUtil::getRadomPlace()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    float radius = rand_0_1() * visibleSize.width * 0.4f;
    float angle = ZMath::degToRad(rand_0_1() * 360);
    Vec2 centerP = Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.45f);
    
    float x = radius * sinf(angle);
    float y = radius * cosf(angle);
    return Vec2(x + centerP.x, y + centerP.y);
}


Vec2 ZUtil::convertRootWorldSpace(Vec2 vec, Node* node)
{
    Node* parent = node->getParent();
    while(parent) {
        vec = parent->convertToWorldSpaceAR(vec);
        node = parent;
        parent = parent->getParent();
    }
    return vec;
}

Rect ZUtil::convertRootWorldSpace(Rect rect, Node* node)
{
    Vec2 pos = ZUtil::convertRootWorldSpace(rect.origin, node);
    return Rect(pos.x, pos.y, rect.size.width, rect.size.height);
}
