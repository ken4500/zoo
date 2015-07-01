//
//  ZMath.h
//  zoo
//
//  Created by Ken Watanabe on 2015/06/21.
//
//

#ifndef __zoo__ZMath__
#define __zoo__ZMath__

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

};

#endif /* defined(__zoo__ZMath__) */
