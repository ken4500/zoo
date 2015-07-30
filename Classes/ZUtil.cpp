//
//  ZUtil.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/30.
//
//

#include "ZUtil.h"
#include "ZMath.h"
#include <sys/time.h>

void ZUtil::printVec(Vec2 vec)
{
    CCLOG("x = %.2f, y = %.2f", vec.x, vec.y);
}

void ZUtil::printVec(Vec2 vec, std::string message)
{
    CCLOG("%s (x = %.2f, y = %.2f)", message.c_str(), vec.x, vec.y);
}

void ZUtil::printNode(Node* node)
{
    _printNodeRecursive(node, 0, NULL);
}

void ZUtil::printNode(Node* node, std::function<void (Node* node)> func)
{
    _printNodeRecursive(node, 0, func);
}


void ZUtil::_printNodeRecursive(Node* node, int count, std::function<void (Node*)> func)
{
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
    if (count != 0) {
        printf("┣");
    }
    printf("name = %s, class = %s, ", node->getName().c_str(), typeid(*node).name());
    if (func) {
        func(node);
    }
    printf("\n");
    
    for (auto child : node->getChildren()) {
        _printNodeRecursive(child, count + 1, func);
    }
}

double ZUtil::getTime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec / 1000000.0;
}

void ZUtil::setGlobalZOrderRecursive(Node* node, float zorder)
{
    node->setGlobalZOrder(zorder);
    for (auto child : node->getChildren()) {
        setGlobalZOrderRecursive(child, zorder);
    }
}


float ZUtil::calcDurationTime(cocostudio::timeline::ActionTimeline* timeline, std::string animationName)
{
    auto animationInfo = timeline->getAnimationInfo(animationName);
    float durationTime = (animationInfo.endIndex - animationInfo.startIndex) / (timeline->getTimeSpeed() * GAME_FPS);
    return durationTime;
}


/**
 * FNV Constants
 */
static const uint32_t FNV_OFFSET_BASIS_32 = 2166136261U;
static const uint32_t FNV_PRIME_32 = 16777619U;
/**
 * FNV Hash Algorithm
 */
uint32_t ZUtil::toHash32(uint8_t *bytes, size_t length)
{
    uint32_t hash;
    size_t i;

    hash = FNV_OFFSET_BASIS_32;
    for( i = 0 ; i < length ; ++i) {
        hash = (FNV_PRIME_32 * hash) ^ (bytes[i]);
    }

    return hash;
}