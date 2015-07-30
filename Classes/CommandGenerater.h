//
//  CommandGenerater.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/28.
//
//

#ifndef __Zoo__CommandGenerater__
#define __Zoo__CommandGenerater__

#include "cocos2d.h"
#include "JSONPacker.h"
#include "Animal.h"
#include "CoinTree.h"

using namespace JSONPacker;

class CommandGenerater {
public:
    static void excCommand(std::string dataStr);
    static void sendUserInfo(std::string name, int userId);
    static void releaseAnimal(Animal* aniaml);
    static void makeCoinTree(CoinTree* coinTree);
    static void walkAnimal(Animal* animal, Vec2 targetPoint, double time);
};

#endif /* defined(__Zoo__CommandGenerater__) */
