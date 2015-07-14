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

// エフェクト再生
void SoundManager::playEffect(string effectName)
{
    AudioEngine::play2d(effectName.c_str(), false);
}

// タイトルのバックミュージック
void SoundManager::playGameBgm()
{
//    string bgm = "sound/bgm.mp3";
//    playBgm(bgm);
}

