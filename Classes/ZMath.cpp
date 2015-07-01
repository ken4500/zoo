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
