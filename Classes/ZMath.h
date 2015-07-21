//
//  ZMath.h
//  zoo
//
//  Created by Ken Watanabe on 2015/06/21.
//
//

#ifndef __zoo__ZMath__
#define __zoo__ZMath__

#include "cocos2d.h"

class ZMath{
public:
    static float min(float a, float b);
    static float max(float a, float b);
    // 弧度法からラジアンに
    static float degToRad(float degree);
    // ラジアンから弧度法に
    static float radToDeg(float rad);
    
    // 乱数
    static int random(int min, int max);
    static cocos2d::Vec2 divideInternally(cocos2d::Vec2 p1, cocos2d::Vec2 p2, float n, float m);

};

#endif /* defined(__zoo__ZMath__) */
