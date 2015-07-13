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
    float x = visibleSize.width * rand_0_1() - visibleSize.width / 2;
    float y = visibleSize.height * rand_0_1() - visibleSize.height / 2;
    return Vec2(x, y);
        
//    float radius = rand_0_1() * visibleSize.height * 0.4f;
//    float angle = ZMath::degToRad(rand_0_1() * 360);
//    
//    float x = radius * sinf(angle);
//    float y = radius * cosf(angle);
//    return Vec2(x, y);
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

void ZUtil::printVec(Vec2 vec)
{
    CCLOG("x = %.2f, y = %.2f", vec.x, vec.y);
}
