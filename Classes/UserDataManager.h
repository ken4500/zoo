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

    // 世界情報に関するメソッド
    WorldInfo* getWorldInfo();
    void setWorldInfo(WorldInfo* info);

    // 言語設定に関するメソッド
    LanguageType getLanguage();
    void setLanguage(LanguageType language);

    // 所持コインに関するメソッド
    long int getCoin();
    void addCoin(long int coin);
    void setCoin(long int coin);

    // 体力に関するメソッド
    int getMaxLife();
    int getLife();
    int getNextRepairLifeTime();
    bool isMaxLife();
    void repairLife();
    void decreateLife(int life);
    void addMaxLife(int addMaxLife);

    // 所持動物に関するメソッド
    std::vector<Animal*> getAnimalList();
    void addAnimal(Animal* animal);
    void removeAnimal(Animal* animal);

    // 過去の取得動物データに関するメソッド
    bool haveHadAnimalInPast(std::string animalName);
    void getAnimal(Animal* animal);
    Weight getMaxWeight(std::string animalName);
    Weight getMinWeight(std::string animalNmae);
    Length getMaxHeight(std::string animalName);
    Length getMinHeight(std::string animalNmae);
    int getAnimalCount(std::string animalName);

    CC_SYNTHESIZE(UserData*, _userData, UserData);
    
private:
};


#endif /* defined(__zoo__UserDataManager__) */
