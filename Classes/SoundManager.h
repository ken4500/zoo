//
//  SoundManager.h
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/13.
//
//

#ifndef __Tetrominos__SoundManager__
#define __Tetrominos__SoundManager__

#include "cocos2d.h"
#include "Constants.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

class SoundManager : cocos2d::Ref{
public:
    static SoundManager* getInstance();
    SoundManager();
    ~SoundManager();
    bool init();

    void playBgm(string musicName);
    void stopBgm();
    void playEffect(string efectName);
    void playGameBgm();

private:
    int _currentBgmId;
    string _currentBgm;
};


#endif /* defined(__Tetrominos__SoundManager__) */
