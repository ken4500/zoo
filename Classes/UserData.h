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
    
private:
    static std::string getFilePath();
    ValueMap _data;
};



#endif /* defined(__zoo__UserData__) */
