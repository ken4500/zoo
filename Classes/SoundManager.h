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
    void pauseBgm();
    void resumeBgm();
    void fadeOutBgm(float interval);
    void fadeInBgm(float interval, string musicName);
    void transitionBgm(float interval, string musicName);
    void playEffect(string efectName);
    void playTitleBgm();
    void playMainBgm();
    void playBattleBgm();
    void playBattleStartEffect();
    void playNovelTap();
    void playCancellEffect();
    void playDecideEffect1();
    void playDecideEffect2();
    void playGetCoinEffect();
    void playGachaEffect1();
    void playGachaEffect2();
    void playLevelupEffect();
    void playAnimalDead();
    void playEnemyAnimalDead();
    void playFightSound();
    void playFight2Sound();

private:
    int _currentBgmId;
    string _currentBgm;
    double _preFightTime;
    double _preFight2Time;
    double _preCoinTime;
    float fadeinVolume;
    float fadeoutVolume;
};


#endif /* defined(__Tetrominos__SoundManager__) */
