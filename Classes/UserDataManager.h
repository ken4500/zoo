//
//  UserDataManager.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/14.
//
//

#ifndef __zoo__UserDataManager__
#define __zoo__UserDataManager__

#include "cocos2d.h"
#include "CommonInclude.h"
#include "UserData.h"
#include "spine/Json.h"
#include "Animal.h"

USING_NS_CC;
using namespace std;

class UserDataManager{
public:
    static UserDataManager* getInstance();
    UserDataManager();
    ~UserDataManager();
    bool init();
    void reset();

    bool isEndTutorial();
    void clearTutorial();

    WorldInfo* getWorldInfo();
    void setWorldInfo(WorldInfo* info);

    LanguageType getLanguage();
    void setLanguage(LanguageType language);

    int getCoin();
    void addCoin(int coin);
    void setCoin(int coin);

    int getMaxLife();
    int getLife();
    int getNextRepairLifeTime();
    bool isMaxLife();
    void repairLife();
    void decreateLife(int life);
    void addMaxLife(int addMaxLife);

    std::vector<Animal*> getAnimalList();
    void addAnimal(Animal* animal);
    void removeAnimal(Animal* animal);

    CC_SYNTHESIZE(UserData*, _userData, UserData);
    
private:
};


#endif /* defined(__zoo__UserDataManager__) */
