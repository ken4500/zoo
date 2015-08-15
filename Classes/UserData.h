//
//  UserData.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/14.
//
//

#ifndef __zoo__UserData__
#define __zoo__UserData__

#include <stdio.h>
#include "cocos2d.h"
#include "Constants.h"
USING_NS_CC;

class UserData :Ref {
public:
    bool init();
    void save();
    static UserData* load();
    
    bool isEndTutorial();
    ValueMap getStoryData();
    ValueMap getWorldInfo();
    long long int getCoin();
    ValueMap getLifeData();
    ValueVector getAnimalList();
    LanguageType getLanguage();
    ValueMap getAnimalDataList();
    int getDiamondNum();
    ValueMap getShopData();
    bool isReviewed();

    void setEndTutorial(bool endTutorial);
    void setStroyData(ValueMap storyData);
    void setWorldInfo(ValueMap info);
    void setCoin(long long int coin);
    void setLifeData(ValueMap lifeData);
    void setAnimalList(ValueVector animal);
    void setLanguage(LanguageType language);
    void setAnimalDataList(ValueMap getAnimalData);
    void setDiamondNum(int diamondNum);
    void setShopData(ValueMap shopData);
    void setIsReviewed(bool reviewed);
    
private:
    ValueMap _data;

    static std::string _getFilePath();
    void _save(float dt);
};



#endif /* defined(__zoo__UserData__) */
