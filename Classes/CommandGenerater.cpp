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

void CommandGenerater::excCommand(std::string dataStr)
{
    auto data = JSONPacker::unpackCommandDataJSON(dataStr);
    if (data.commandName == "create") {
        auto animal = Animal::CreateWithSpeceis(data.stringDataList[0], data.numberDataList[0]);
        WorldManager::getInstance()->releaseAnimalByNetwork(animal);
    } else if (data.commandName == "user_info") {
        auto name = data.stringDataList[0];
        auto id = data.numberDataList[0];
        SceneManager::getInstance()->setOpponentUserInfo(name, id);
    }
}

void CommandGenerater::sendUserInfo(std::string name, int userId)
{
    CommandData data;
    data.commandName = "user_info";
    data.stringDataList.push_back(name);
    data.numberDataList.push_back(userId);
    auto json = JSONPacker::packCommandData(data);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}

void CommandGenerater::releaseAnimal(Animal* animal)
{
    CommandData data;
    data.commandName = "create";
    data.stringDataList.push_back(animal->getName());
    data.numberDataList.push_back(animal->getHeight()->getMmLength());
    auto json = JSONPacker::packCommandData(data);
    SceneManager::getInstance()->sendData(json.c_str(), json.length());
}

