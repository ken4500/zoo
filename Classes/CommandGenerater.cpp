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
    if (data.commandName == "create_animal")
    {
        auto animal = Animal::CreateWithSpeceis(data.stringDataList[0], data.numberDataList[0]);
        animal->setId(data.intDataList[0]);
        WorldManager::getInstance()->releaseAnimalByNetwork(animal);
    }
    else if (data.commandName == "user_info")
    {
        auto name = data.stringDataList[0];
        auto id = data.numberDataList[0];
        SceneManager::getInstance()->setOpponentUserInfo(name, id, data.time);
    }
    else if (data.commandName == "create_tree")
    {
        auto id = data.intDataList[0];
        auto length = new Length(data.numberDataList[0]);
        auto pos = Vec2(data.numberDataList[1], data.numberDataList[2]);
        auto tree = dynamic_cast<CoinTree*>(CSLoader::createNode("CoinTree.csb"));
        tree->setLength(length);
        tree->setId(id);
        tree->setRealPosition(pos);
        WorldManager::getInstance()->createTreeByNetwork(tree);
    }
    else if (data.commandName == "walk_animal")
    {
    }
}

void CommandGenerater::sendUserInfo(std::string name, int userId)
{
    CommandData data;
    data.commandName = "user_info";
    data.time = ZUtil::getTime();
    data.stringDataList.push_back(name);
    data.numberDataList.push_back(userId);
    auto json = JSONPacker::packCommandData(data);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}

void CommandGenerater::releaseAnimal(Animal* animal)
{
    CommandData data;
    data.commandName = "create_animal";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(animal->getId());
    data.stringDataList.push_back(animal->getName());
    data.numberDataList.push_back(animal->getHeight()->getMmLength());
    auto json = JSONPacker::packCommandData(data);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}

void CommandGenerater::makeCoinTree(CoinTree* coinTree)
{
    CommandData data;
    data.commandName = "create_tree";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(coinTree->getId());
    data.numberDataList.push_back(coinTree->getLength()->getMmLength());
   
    Vec2 pos = coinTree->getRealPosition();
    data.numberDataList.push_back(pos.x);
    data.numberDataList.push_back(pos.y);
    
    auto json = JSONPacker::packCommandData(data);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}

void CommandGenerater::walkAnimal(Animal* animal, Vec2 targetPoint, double time)
{
    CommandData data;
    data.commandName = "walk_animal";
    data.time = ZUtil::getTime();
    data.intDataList.push_back(animal->getId());
    data.stringDataList.push_back(animal->getName());
    data.numberDataList.push_back(animal->getHeight()->getMmLength());

    data.numberDataList.push_back(targetPoint.x);
    data.numberDataList.push_back(targetPoint.y);
    data.numberDataList.push_back(time);
    
    auto json = JSONPacker::packCommandData(data);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}
