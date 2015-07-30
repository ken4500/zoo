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
    static void sendData(CommandData data);
    static void sendData(std::vector<CommandData> data);

    static CommandData sendUserInfo(std::string name, int userId);
    static CommandData releaseAnimal(Animal* aniaml);
    static CommandData makeCoinTree(CoinTree* coinTree);
    static CommandData walkAnimal(Animal* animal);
    static CommandData dashAnimal(Animal* animal);
    static CommandData stopAnimal(Animal* animal);
    static CommandData fightTree(Animal* animal, AbstractBattleEntity* tree);
};

#endif /* defined(__Zoo__CommandGenerater__) */
