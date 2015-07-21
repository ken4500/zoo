//
//  ZMath.cpp
//  zoo
//
//  Created by Ken Watanabe on 2015/06/21.
//
//

#include "ZMath.h"
#include <math.h>
using namespace std;
using namespace cocos2d;

float ZMath::min(float a, float b)
{
    return (a > b) ? b : a;
}

float ZMath::max(float a, float b)
{
    return (a > b) ? a : b;
}

float ZMath::degToRad(float degree)
{
    return degree / 180.0f * M_PI;
}

float ZMath::radToDeg(float rad)
{
    return rad * 180.0f / M_PI;
}

int ZMath::random(int min, int max)
{
    return rand() % (max - min) + min;
}

Vec2 ZMath::divideInternally(Vec2 p1, Vec2 p2, float n, float m)
{
    float x = (n * p1.x + m * p2.x) / (n + m);
    float y = (n * p1.y + m * p2.y) / (n + m);
    return Vec2(x, y);
}
