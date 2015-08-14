//
//  SoundManager.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/13.
//
//

#include "SoundManager.h"
#include "audio/include/AudioEngine.h"
#include "ZUtil.h"
#include "WorldManager.h"
using namespace cocos2d::experimental;

#define BGM_VOLUME 0.3
#define SE_VOLUEM 1.0


static SoundManager* shared_controller = nullptr;

//  static methods
SoundManager* SoundManager::getInstance()
{
    if (!shared_controller) {
        shared_controller = new SoundManager();
        shared_controller->init();
    }
    
    return shared_controller;
}

SoundManager::SoundManager()
{
    _preFightTime = 0;
    _preFight2Time = 0;
    _preCoinTime  = 0;
}

SoundManager::~SoundManager()
{
    delete shared_controller;
    shared_controller = nullptr;
}

bool SoundManager::init()
{
    return true;
}

// BGM再生
void SoundManager::playBgm(string musicName)
{
    if (musicName == "") {
        AudioEngine::stop(_currentBgmId);
        _currentBgm = "";
    } else if(_currentBgm != musicName) {
        AudioEngine::stop(_currentBgmId);
        _currentBgmId = AudioEngine::play2d(musicName.c_str(), true, BGM_VOLUME);
        _currentBgm = musicName;
    }
}

// BGM停止
void SoundManager::stopBgm()
{
    AudioEngine::stop(_currentBgmId);
    _currentBgm = "";
}

void SoundManager::pauseBgm()
{
    AudioEngine::pause(_currentBgmId);
}

void SoundManager::resumeBgm()
{
    AudioEngine::resume(_currentBgmId);
}

void SoundManager::fadeOutBgm(float interval)
{
    if (Director::getInstance()->getScheduler()->isScheduled("fadeout_bgm", this)) {
        return;
    }
    
    _currentBgm = "";
    int bgmId = _currentBgmId;
    float updateDuration = 0.1f;
    int repeatCount = MAX(1, int(interval / updateDuration));
    fadeoutVolume = BGM_VOLUME;
    float decreaseVolume = fadeoutVolume / (repeatCount + 1);
    
    Director::getInstance()->getScheduler()->schedule([this, decreaseVolume, bgmId](float dt){
        fadeoutVolume -= decreaseVolume;
        AudioEngine::setVolume(bgmId, fadeoutVolume);
        CCLOG("FADE OUT = %f", fadeoutVolume);
        if (fadeoutVolume < 0.05f) {
            AudioEngine::stop(bgmId);
        }
    }, this, updateDuration, repeatCount, false, false, "fadeout_bgm");
}

void SoundManager::fadeInBgm(float interval, string musicName)
{
    if(_currentBgm == musicName) {
        return;
    }
    
    if (Director::getInstance()->getScheduler()->isScheduled("fadein_bgm", this)) {
        return;
    }

    _currentBgmId = AudioEngine::play2d(musicName.c_str(), true);
    _currentBgm = musicName;
    AudioEngine::setVolume(_currentBgmId, 0.0f);

    fadeinVolume = 0;
    float updateDuration = 0.1f;
    int repeatCount = MAX(1, int(interval / updateDuration));
    float increaseVolume = BGM_VOLUME / repeatCount;

    Director::getInstance()->getScheduler()->schedule([this, increaseVolume](float dt){
        fadeinVolume += increaseVolume;
        AudioEngine::setVolume(_currentBgmId, fadeinVolume);
    }, this, updateDuration, repeatCount, false, false, "fadein_bgm");
}

void SoundManager::transitionBgm(float interval, string musicName)
{
    if (musicName == "") {
        AudioEngine::stop(_currentBgmId);
        _currentBgm = "";
    } else if(_currentBgm != musicName) {
        fadeOutBgm(interval / 2);
        
        Director::getInstance()->getScheduler()->schedule([this, interval, musicName](float dt){
            fadeInBgm(interval / 2, musicName);
        }, this, interval / 2, 0, false, false, "transition_fadein");
    }
}

// エフェクト再生
void SoundManager::playEffect(string effectName)
{
    AudioEngine::play2d(effectName.c_str(), false, SE_VOLUEM);
}

void SoundManager::playTitleBgm()
{
    playBgm("sound/bgm/title.mp3");
}

void SoundManager::playMainBgm()
{
    auto info = WorldManager::getInstance()->getWorldInfo();
    std::string musicName;
    if (info->level >= 27) {
        musicName = "sound/bgm/title.mp3";
    } else if (info->level >= 20) {
        musicName = "sound/bgm/main4.mp3";
    } else if (info->level >= 15) {
        musicName = "sound/bgm/main3.mp3";
    } else if (info->level >= 10) {
        musicName = "sound/bgm/main2.mp3";
    } else {
        musicName = "sound/bgm/main1.mp3";
    }

    transitionBgm(1.0f, musicName);
}

void SoundManager::playBattleBgm()
{
    Director::getInstance()->getScheduler()->schedule([&](float dt){
        playBgm("sound/bgm/battle.mp3");
    }, this, 1.0f, 0, false, false, "battle_bgm");
}

void SoundManager::playBattleStartEffect()
{
    playEffect("sound/se/battle_start.mp3");
}

void SoundManager::playNovelTap()
{
    playEffect("sound/se/novel_click.wav");
}

void SoundManager::playCancellEffect()
{
    // TODO:
}

void SoundManager::playDecideEffect1()
{
    // TODO:
}

void SoundManager::playDecideEffect2()
{
    playEffect("sound/se/decide2.wav");
}

void SoundManager::playGetCoinEffect()
{
    double time = ZUtil::getTime();
    if (time - _preCoinTime < 0.15) {
        return;
    }
    _preCoinTime = time;

    playEffect("sound/se/coin3.wav");
}

void SoundManager::playGachaEffect1()
{
    playEffect("sound/se/gacha1.wav");
}

void SoundManager::playGachaEffect2()
{
    Director::getInstance()->getScheduler()->schedule([&](float dt){
        playEffect("sound/se/gacha2.wav");
    }, this, 0.2f, 0, false, false, "main_bgm");
}

void SoundManager::playLevelupEffect()
{
    playEffect("sound/se/levelup.wav");
}

void SoundManager::playAnimalDead()
{
    playEffect("sound/se/p_dead2.wav");
}

void SoundManager::playEnemyAnimalDead()
{
    playEffect("sound/se/p_dead2.wav");
}

void SoundManager::playFightSound()
{
    double time = ZUtil::getTime();
    if (time - _preFightTime < 0.2) {
        return;
    }
    
    _preFightTime = time;
    
    playEffect("sound/se/fight1.wav");
}


void SoundManager::playFight2Sound()
{
    double time = ZUtil::getTime();
    if (time - _preFight2Time < 0.2) {
        return;
    }
    
    _preFight2Time = time;
    
    playEffect("sound/se/fight2.wav");
}
