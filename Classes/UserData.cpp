//
//  UserData.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/14.
//
//

#include "UserData.h"

bool UserData::init()
{
    _data = ValueMap();
    return save();
}

bool UserData::save()
{   //保存箇所のフルパスを取得
    std::string path = UserData::getFilePath();
    
    // 保存
    if(FileUtils::getInstance()->writeToFile(_data, path)){
        CCLOG("save Success:%s", path.c_str());
        return true;
    }else{
        CCLOG("save Failed:%s", path.c_str());
        return false;
    }
}

UserData* UserData::load()
{
    UserData* result = new UserData();
    auto path = UserData::getFilePath();
    if (FileUtils::getInstance()->isFileExist(path) == false) {
        result->init();
    }
    result->_data = FileUtils::getInstance()->getValueMapFromFile(path);
    return result;
}

std::string UserData::getFilePath()
{
    return FileUtils::getInstance()->getWritablePath() + "user_data_20150322";
}

