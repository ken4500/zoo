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

class UserData {
public:
    bool init();
    bool save();
    static UserData* load();
    
    bool isEndTutorial();
    ValueMap getWorldInfo();
    long int getCoin();
    ValueMap getLifeData();
    ValueVector getAnimalList();
    LanguageType getLanguage();
    ValueMap getAnimalDataList();

    void setEndTutorial(bool endTutorial);
    void setWorldInfo(ValueMap info);
    void setCoin(long int coin);
    void setLifeData(ValueMap lifeData);
    void setAnimalList(ValueVector animal);
    void setLanguage(LanguageType language);
    void setAnimalDataList(ValueMap getAnimalData);

    
private:
    static std::string getFilePath();
    ValueMap _data;
};



#endif /* defined(__zoo__UserData__) */
