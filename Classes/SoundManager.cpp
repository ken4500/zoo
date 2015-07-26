//
//  SoundManager.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/07/13.
//
//

#include "SoundManager.h"
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;


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
        _currentBgmId = AudioEngine::play2d(musicName.c_str(), true);
        _currentBgm = musicName;
    }
}

// BGM停止
void SoundManager::stopBgm()
{
    AudioEngine::stop(_currentBgmId);
    _currentBgm = "";
}

void SoundManager::fadeOutBgm(float interval)
{
    _currentBgm = "";
    int bgmId = _currentBgmId;
    static float volume = AudioEngine::getVolume(bgmId);
    float updateDuration = 0.05f;
    int repeatCount = MAX(1, int(interval / updateDuration));
    float decreaseVolume = volume / repeatCount;

    Director::getInstance()->getScheduler()->schedule([this, decreaseVolume, bgmId](float dt){
        volume -= decreaseVolume;
        AudioEngine::setVolume(bgmId, volume);
        if (volume < 0.01f) {
            AudioEngine::stop(bgmId);
        }
    }, this, updateDuration, repeatCount, false, false, "fadeout_bgm");
}

void SoundManager::fadeInBgm(float interval, string musicName)
{
    if(_currentBgm == musicName) {
        return;
    }
    AudioEngine::stop(_currentBgmId);
    _currentBgmId = AudioEngine::play2d(musicName.c_str(), true);
    _currentBgm = musicName;
    AudioEngine::setVolume(_currentBgmId, 0.0f);

    static float volume = 0;
    float updateDuration = 0.05f;
    int repeatCount = MAX(1, int(interval / updateDuration));
    float increaseVolume = 1.0f / repeatCount;

    Director::getInstance()->getScheduler()->schedule([this, increaseVolume](float dt){
        volume += increaseVolume;
        AudioEngine::setVolume(_currentBgmId, volume);
    }, this, updateDuration, repeatCount, false, false, "fadein_bgm");
}

// エフェクト再生
void SoundManager::playEffect(string effectName)
{
    AudioEngine::play2d(effectName.c_str(), false);
}

void SoundManager::playTitleBgm()
{
    playBgm("sound/bgm/title.mp3");
}

void SoundManager::playMainBgm()
{
    Director::getInstance()->getScheduler()->schedule([&](float dt){
        playBgm("sound/bgm/main.mp3");
    }, this, 1.0f, 0, false, false, "schedulerKey");
}

void SoundManager::playBattleBgm()
{
    fadeOutBgm(0.5f);
    Director::getInstance()->getScheduler()->schedule([&](float dt){
        playBgm("sound/bgm/battle.mp3");
    }, this, 1.0f, 0, false, false, "schedulerKey");
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
}
