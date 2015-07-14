//
//  UserDataController.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/14.
//
//

#ifndef __zoo__UserDataController__
#define __zoo__UserDataController__

#include "cocos2d.h"
#include "Constants.h"
#include "UserData.h"
#include "spine/Json.h"

USING_NS_CC;
using namespace std;

class UserDataController{
public:
    static UserDataController* getInstance();
    UserDataController();
    ~UserDataController();
    bool init();
    void reset();

    CC_SYNTHESIZE(UserData*, _userData, UserData);

    
private:
};


#endif /* defined(__zoo__UserDataController__) */
