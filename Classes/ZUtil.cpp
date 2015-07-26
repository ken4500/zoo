//
//  ZUtil.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/30.
//
//

#include "ZUtil.h"
#include "ZMath.h"

void ZUtil::printVec(Vec2 vec)
{
    CCLOG("x = %.2f, y = %.2f", vec.x, vec.y);
}

void ZUtil::printVec(Vec2 vec, std::string message)
{
    CCLOG("%s (x = %.2f, y = %.2f)", message.c_str(), vec.x, vec.y);
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