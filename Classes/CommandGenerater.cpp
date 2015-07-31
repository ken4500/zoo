//
//  CommandGenerater.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/28.
//
//

#include "CommandGenerater.h"
#include "WorldManager.h"
#include "SceneManager.h"

#include <sys/time.h>

void CommandGenerater::excCommand(std::string dataStr)
{
    auto data = JSONPacker::unpackCommandDataJSON(dataStr);
    CCLOG("###EXECUTE COMMAND LIST###");
    for (auto command : data) {
        CCLOG("# command = %s", command.commandName.c_str());
        if (command.commandName == "user_info")
        {
            auto name = command.stringDataList[0];
            auto id = command.numberDataList[0];
            SceneManager::getInstance()->setOpponentUserInfo(name, id, command.time);
        }
        else if (command.commandName == "create_tree")
        {
            auto id = command.intDataList[0];
            auto length = new Length(command.numberDataList[0]);
            auto pos = Vec2(command.numberDataList[1], command.numberDataList[2]);
            auto tree = dynamic_cast<CoinTree*>(CSLoader::createNode("CoinTree.csb"));
            tree->setLength(*length);
            tree->setId(id);
            tree->setRealPosition(pos);
            WorldManager::getInstance()->createTreeByNetwork(tree);
        }
        else if (command.commandName == "dead_tree")
        {
            auto id = command.intDataList[0];
            WorldManager::getInstance()->deadTreeByNetwork(id);
        }
        else if (command.commandName == "create_animal")
        {
            auto animal = Animal::CreateWithSpeceis(command.stringDataList[0], command.numberDataList[0]);
            animal->setId(command.intDataList[0]);
            WorldManager::getInstance()->releaseAnimalByNetwork(animal);
        }
        else if (command.commandName == "remove_animal")
        {
            auto id = command.intDataList[0];
            WorldManager::getInstance()->removeAnimalByNetwork(id);
        }
        else if (command.commandName == "walk_animal")
        {
            int id = command.intDataList[0];
            auto animal = WorldManager::getInstance()->getOpponentAnimal(id);
            Vec2 targetPoint = Vec2(command.numberDataList[0], command.numberDataList[1]);
            targetPoint = WorldManager::getInstance()->getDisplayPosition(targetPoint);
            auto speed = Length(command.numberDataList[2]);
            animal->startWalk(targetPoint, speed);
        }
        else if (command.commandName == "dash_animal")
        {
            int id = command.intDataList[0];
            auto animal = WorldManager::getInstance()->getOpponentAnimal(id);
            Vec2 targetPoint = Vec2(command.numberDataList[0], command.numberDataList[1]);
            targetPoint = WorldManager::getInstance()->getDisplayPosition(targetPoint);
            auto speed = Length(command.numberDataList[2]);
            animal->startDash(targetPoint, speed);
        }
        else if (command.commandName == "stop_animal")
        {
            int id = command.intDataList[0];
            auto animal = WorldManager::getInstance()->getOpponentAnimal(id);
            Vec2 position = Vec2(command.numberDataList[0], command.numberDataList[1]);
            animal->setRealPosition(position);
            animal->startStop();
        }
        else if (command.commandName == "fight_tree")
        {
            int id = command.intDataList[0];
            int treeId = command.intDataList[1];
            auto animal = WorldManager::getInstance()->getOpponentAnimal(id);
            auto tree = dynamic_cast<AbstractBattleEntity*>(WorldManager::getInstance()->getCointTree(treeId));
            Vec2 position = Vec2(command.numberDataList[0], command.numberDataList[1]);
            animal->setRealPosition(position);
            if (tree) {
                animal->fight(tree);
            }
        }
        else if (command.commandName == "levelup")
        {
            int level = command.intDataList[0];
            WorldManager::getInstance()->levelupOpponent(level);
        }
    }
}

void CommandGenerater::sendData(CommandData data)
{
    auto json = JSONPacker::packCommandData(data);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}

void CommandGenerater::sendData(std::vector<CommandData> data)
{
    auto json = JSONPacker::packCommandData(data);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());    
}

CommandData CommandGenerater::sendUserInfo(std::string name, int userId)
{
    CommandData data;
    data.commandName = "user_info";
    data.time = ZUtil::getTime();
    data.stringDataList.push_back(name);
    data.numberDataList.push_back(userId);
    return data;
}

CommandData CommandGenerater::makeCoinTree(CoinTree* coinTree)
{
    CommandData data;
    data.commandName = "create_tree";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(coinTree->getId());
    data.numberDataList.push_back(coinTree->getLength().getMmLength());
   
    Vec2 pos = coinTree->getRealPosition();
    data.numberDataList.push_back(pos.x);
    data.numberDataList.push_back(pos.y);
    
    return data;
}

CommandData CommandGenerater::deadCoinTree(CoinTree* coinTree)
{
    CommandData data;
    data.commandName = "dead_tree";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(coinTree->getId());
    
    return data;
}

CommandData CommandGenerater::releaseAnimal(Animal* animal)
{
    CommandData data;
    data.commandName = "create_animal";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(animal->getId());
    data.stringDataList.push_back(animal->getName());
    data.numberDataList.push_back(animal->getHeight().getMmLength());
    return data;
}

CommandData CommandGenerater::removeAnimal(Animal* animal)
{
    CommandData data;
    data.commandName = "remove_animal";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(animal->getId());
    return data;
}

CommandData CommandGenerater::walkAnimal(Animal* animal)
{
    CommandData data;
    data.commandName = "walk_animal";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(animal->getId());
    auto target = animal->getTargetPointByWalk();
    target = WorldManager::getInstance()->getRealPosition(target);
    data.numberDataList.push_back(target.x);
    data.numberDataList.push_back(target.y);
    data.numberDataList.push_back(animal->getSpeed().getMmLength());
    return data;
}

CommandData CommandGenerater::dashAnimal(Animal* animal)
{
    CommandData data;
    data.commandName = "dash_animal";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(animal->getId());
    auto target = animal->getTargetPointByDash();
    target = WorldManager::getInstance()->getRealPosition(target);
    data.numberDataList.push_back(target.x);
    data.numberDataList.push_back(target.y);
    data.numberDataList.push_back(WorldManager::getInstance()->getDashSpeed().getMmLength());
    return data;
}

CommandData CommandGenerater::stopAnimal(Animal* animal)
{
    CommandData data;
    data.commandName = "stop_animal";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(animal->getId());
    auto position = animal->getRealPosition();
    data.numberDataList.push_back(position.x);
    data.numberDataList.push_back(position.y);
    return data;
}

CommandData CommandGenerater::fightTree(Animal* animal, AbstractBattleEntity* tree)
{
    CommandData data;
    data.commandName = "fight_tree";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(animal->getId());
    data.intDataList.push_back(tree->getId());
    auto position = animal->getRealPosition();
    data.numberDataList.push_back(position.x);
    data.numberDataList.push_back(position.y);
    return data;
}

CommandData CommandGenerater::levelUp(WorldInfo* info)
{
    CommandData data;
    data.commandName = "levelup";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(info->level);
    return data;
}
