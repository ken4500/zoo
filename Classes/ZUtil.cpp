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

float ZUtil::calcDurationTime(cocostudio::timeline::ActionTimeline* timeline, std::string animationName)
{
    auto animationInfo = timeline->getAnimationInfo(animationName);
    float durationTime = (animationInfo.endIndex - animationInfo.startIndex) / (timeline->getTimeSpeed() * GAME_FPS);
    return durationTime;
}
