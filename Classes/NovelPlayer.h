//
//  NovelPlayer.h
//  zoo
//
//  Created by Ken Watanabe on 2014/09/21.
//
//

#ifndef __ninjya__NovelPlayer__
#define __ninjya__NovelPlayer__

#include "cocos2d.h"
#include <iostream>
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "NovelAction.h"
using namespace std;
USING_NS_CC;

class NovelPlayer {
public:
    NovelPlayer(rapidjson::Value& novelJson);
    shared_ptr<vector<shared_ptr<NovelAction>>> popNextActions();
    bool goToNextScene();
    bool getIsNextActionFullscreen();
    bool getIsFirstPlayback();
    bool getMoreActionsAvailable();
    bool getHasTutorial();
    shared_ptr<NovelAction> getLastMusic();
    vector<string>& getImages();
private:
    queue<shared_ptr<NovelAction> > _actions;
    vector<std::string> _images;
    bool _isFirstPlayback = false;
    bool _hasTutorial = false;
};


#endif /* defined(__ninjya__NovelPlayer__) */
