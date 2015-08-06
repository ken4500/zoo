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
    static void printVec(Vec2 vec, std::string message);
    static void printNode(Node* node);
    static void printNode(Node* node, std::function<void (Node*)> func);

    static std::string submbstr(std::string str, int pos, int size);

    static double getTime();

    static void setGlobalZOrderRecursive(Node* node, float zorder);
    
    static float calcDurationTime(cocostudio::timeline::ActionTimeline* timeline, std::string animationName);
    
    static double boxrnd(double m, double sig);
    
    static uint32_t toHash32(uint8_t *bytes, size_t length);

private:
    static void _printNodeRecursive(Node* node, int count, std::function<void (Node*)> func);
};


#endif /* defined(__Zoo__ZUtil__) */
