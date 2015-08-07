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

std::string ZUtil::submbstr(std::string str, int pos, int size)
{
    unsigned char lead;
    int char_size;
    int charNum = 0;
    int posIndex = 0;
    int startIndex = 0;
    int endIndex = 0;

    for (int index = 0; index < str.length(); index += char_size, posIndex++) {
        if (charNum == pos) {
            startIndex = index;
        }
        charNum++;
        lead = str[index];
        if (lead < 128) {
            char_size = 1;
        } else if (lead < 224) {
            char_size = 2;
        } else if (lead < 240) {
            char_size = 3;
        } else {
            char_size = 4;
        }

        if (charNum == pos + size) {
            endIndex = index + char_size;
            break;
        }
    }
    
    if (pos > charNum) {
        return "";
    }
    if (endIndex == 0) {
        endIndex = (int)str.length();
    }

    std::string rtn = str.substr(startIndex, endIndex - startIndex);
    
    return rtn;
}


double ZUtil::getTime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    double time = t.tv_sec + t.tv_usec / 1000000.0;
    time -= int(time / 100000) * 100000;
    return time;
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

double ZUtil::boxrnd(double m, double sig)
{
    double pi = 3.1415926535;      // 円周率
    double ur1 = rand_0_1();
    double ur2 = rand_0_1();
    double r   = sig * sqrt(-2 * log(ur1));
    double t   = 2 * pi * ur2;
    return r * cos(t) + m;
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