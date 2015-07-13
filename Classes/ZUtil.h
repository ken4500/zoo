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
using namespace cocos2d;

class ZUtil{
public:
    static Vec2 getRadomPlace();
    static Vec2 convertRootWorldSpace(Vec2 vec, Node* node);
    static Rect convertRootWorldSpace(Rect rect, Node* node);
    
    static void printVec(Vec2 vec);
};


#endif /* defined(__Zoo__ZUtil__) */
