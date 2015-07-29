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

using namespace JSONPacker;

class CommandGenerater {
public:
    static void excCommand(std::string dataStr);
    static void sendUserInfo(std::string name, int userId);
    static void releaseAnimal(Animal* aniaml);
};

#endif /* defined(__Zoo__CommandGenerater__) */
