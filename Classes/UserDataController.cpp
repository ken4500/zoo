//
//  UserDataController.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/14.
//
//

#include "UserDataController.h"

static UserDataController* shared_controller = nullptr;

UserDataController::UserDataController()
{
}

UserDataController::~UserDataController()
{
    delete shared_controller;
    shared_controller = nullptr;
}

UserDataController* UserDataController::getInstance()
{
    if (!shared_controller) {
        shared_controller = new UserDataController();
        shared_controller->init();
    }
    
    return shared_controller;
}

bool UserDataController::init()
{
    _userData = UserData::load();
    
    return true;
}

void UserDataController::reset()
{
    _userData->init();
    _userData->save();
}


