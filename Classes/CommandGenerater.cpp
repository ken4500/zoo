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
#include "ZUtil.h"

#include <sys/time.h>

void CommandGenerater::excCommand(std::string dataStr)
{
    auto data = JSONPacker::unpackCommandDataJSON(dataStr);
    CCLOG("###EXECUTE COMMAND LIST###");
    CCLOG("json = %s", dataStr.c_str());
    for (auto command : data) {
        CCLOG("# command = %s", command.commandName.c_str());
        if (command.commandName == "user_info")
        {
            auto name = command.stringDataList[0];
            auto id = command.intDataList[0];
            SceneManager::getInstance()->setOpponentUserInfo(name, id, command.time);
        }
        else if (command.commandName == "levelup")
        {
            CCLOG("##level = %d", command.intDataList[0]);
            int level = command.intDataList[0];
            WorldManager::getInstance()->levelupOpponent(level);
        }
        else if (command.commandName == "result_info")
        {
            Weight weight = Weight(command.numberDataList[0]);
            CCLOG("##result weight = %.02f %s", weight.getWeight(), weight.getUnitStr().c_str());
            WorldManager::getInstance()->recieveResult(weight);
        }
        else if (command.commandName == "create_tree")
        {
            CCLOG("##id = %d", command.intDataList[0]);
            auto id = command.intDataList[0];
            auto length = new Length(command.numberDataList[0]);
            auto pos = Vec2(command.numberDataList[1], command.numberDataList[2]);
            auto tree = dynamic_cast<CoinTree*>(CSLoader::createNode("CoinTree.csb"));
            tree->setLength(*length);
            tree->setId(id);
            tree->setRealPosition(pos);
            tree->setIsCreatedByOpponent(true);
            WorldManager::getInstance()->createTreeByNetwork(tree);
        }
        else if (command.commandName == "dead_tree")
        {
            auto id = command.intDataList[0];
            WorldManager::getInstance()->deadTreeByNetwork(id);
        }
        else if (command.commandName == "create_animal")
        {
            CCLOG("##create num = %d", command.intDataList[0]);
            int size = command.intDataList[0];
            std::vector<Animal*> animalList;
            for (int i = 0; i < size; i++) {
                auto animal = Animal::CreateWithSpeceis(command.stringDataList[i], command.numberDataList[i]);
                animal->setId(command.intDataList[i + 1]);
                animalList.push_back(animal);
            }
            WorldManager::getInstance()->releaseAnimalByNetwork(animalList);
        }
        else if (command.commandName == "remove_animal")
        {
            CCLOG("##id = %d", command.intDataList[0]);
            auto id = command.intDataList[0];
            WorldManager::getInstance()->removeAnimalByNetwork(id);
        }
        else if (command.commandName == "walk_animal")
        {
            int id = command.intDataList[0];
            auto animal = WorldManager::getInstance()->getOpponentAnimal(id);
            if (animal) {
                Vec2 targetPoint = Vec2(command.numberDataList[0], command.numberDataList[1]);
                targetPoint = WorldManager::getInstance()->getDisplayPosition(targetPoint);
                auto speed = Length(command.numberDataList[2]);
                animal->startWalk(targetPoint, speed);
            }
        }
        else if (command.commandName == "dash_animal")
        {
            int id = command.intDataList[0];
            auto animal = WorldManager::getInstance()->getOpponentAnimal(id);
            if (animal) {
                Vec2 targetPoint = Vec2(command.numberDataList[0], command.numberDataList[1]);
                targetPoint = WorldManager::getInstance()->getDisplayPosition(targetPoint);
                auto speed = Length(command.numberDataList[2]);
                animal->startDash(targetPoint, speed);
            }
        }
        else if (command.commandName == "stop_animal")
        {
            int id = command.intDataList[0];
            auto animal = WorldManager::getInstance()->getOpponentAnimal(id);
            if (animal) {
                Vec2 position = Vec2(command.numberDataList[0], command.numberDataList[1]);
                animal->setRealPosition(position);
                animal->startStop();
            }
        }
        else if (command.commandName == "fight_tree")
        {
            CCLOG("##animal id = %d", command.intDataList[0]);
            CCLOG("##tree id = %d", command.intDataList[1]);
            int id = command.intDataList[0];
            int treeId = command.intDataList[1];
            auto animal = WorldManager::getInstance()->getOpponentAnimal(id);
            auto tree = dynamic_cast<AbstractBattleEntity*>(WorldManager::getInstance()->getCoinTree(treeId));
            if (animal && tree) {
                Vec2 position = Vec2(command.numberDataList[0], command.numberDataList[1]);
                if (animal->getState() != AnimalState::Battle) {
                    animal->setRealPosition(position);
                }
                if (tree) {
                    animal->fight(tree);
                }
            }
        }
    }
}

void CommandGenerater::sendData(CommandData data)
{
    auto json = JSONPacker::packCommandData(data);
    CCLOG("send = %s", json.c_str());
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
    data.intDataList.push_back(userId);
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

CommandData CommandGenerater::sendResultInfo(Weight weight)
{
    CommandData data;
    data.commandName = "result_info";
    data.time = ZUtil::getTime();
    data.numberDataList.push_back(weight.getMgWeight());
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

CommandData CommandGenerater::releaseAnimal(std::vector<Animal*> animalList)
{
    CommandData data;
    data.commandName = "create_animal";
    data.time = ZUtil::getTime();
    data.intDataList.push_back((int)animalList.size());
    for (auto animal : animalList) {
        data.intDataList.push_back(animal->getId());
        data.stringDataList.push_back(animal->getName());
        data.numberDataList.push_back(animal->getHeight().getMmLength());
    }
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

