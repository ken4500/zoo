//
//  ZUtil.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/06/30.
//
//

#ifndef __Zoo__ZUtil__
#define __Zoo__ZUtil__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "CommonInclude.h"
using namespace cocos2d;

class ZUtil{
public:    
    static void printVec(Vec2 vec);
    
    static float calcDurationTime(cocostudio::timeline::ActionTimeline* timeline, std::string animationName);
};


#endif /* defined(__Zoo__ZUtil__) */
