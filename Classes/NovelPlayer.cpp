//
//  NovelPlayer.cpp
//  zoo
//
//  Created by Ken Watanabe on 2014/09/21.
//
//

#include "NovelPlayer.h"

NovelPlayer::NovelPlayer(rapidjson::Value& novelJson) {
    
    // JSON からシーンを読み込む
    auto actions = queue<NovelAction*>();
    set<string> images;
    for (int i = 0; i < novelJson.Size(); i++) {
        rapidjson::Value& item = novelJson[i];
        auto parsedAction = NovelAction::createFromJson(item);
        if (parsedAction->getType() == NovelAction::Type::Set ||
            parsedAction->getType() == NovelAction::Type::ShowImage ||
            parsedAction->getType() == NovelAction::Type::ShowImageInstant) {
            _images.push_back(parsedAction->getValue());
        }
        _actions.push(parsedAction);
    }
    
    // 再生開始
    this->goToNextScene();
}

bool NovelPlayer::goToNextScene()
{
    this->_isFirstPlayback = true;
    return true;
}

bool NovelPlayer::getHasTutorial() {
    return _hasTutorial;
}

std::vector<std::string>& NovelPlayer::getImages() {
    return _images;
}

bool NovelPlayer::getIsNextActionFullscreen() {
    if (this->_actions.empty()) {
        return false;
    }
    return this->_actions.front()->getFullscreen();
}

bool NovelPlayer::getIsFirstPlayback() {
    return this->_isFirstPlayback;
}

bool NovelPlayer::getMoreActionsAvailable() {
    return !this->_actions.empty();
}

NovelAction* NovelPlayer::getLastMusic()
{
    NovelAction* music = nullptr;
    queue<NovelAction*>actionList = this->_actions;
    while (!actionList.empty())
    {
        auto action = actionList.front();
        actionList.pop();
        if (action->getType() == NovelAction::Type::Music) {
            music = action;
        }
    }
    
    return music;
}

std::vector<NovelAction*> NovelPlayer::popNextActions() {
    this->_isFirstPlayback = false;
    
    bool leftSet      = false;  // 左の立ち絵指定アクションが入った
    bool rightSet     = false;  // 右の立ち絵指定アクションが入った
    bool narrationSet = false;  // ナレーション指定アクションが入った
    bool backgroundSet = false; // 背景指定アクションが入った

    auto result = std::vector<NovelAction*>();
    
    while (true) {
        if (this->_actions.empty()) {
            // アクションが残っていないので終了
            break;
        }
        auto nextAction = this->_actions.front();
        if (nextAction->getType() == NovelAction::Type::Speak) {
            if (leftSet || rightSet || narrationSet || backgroundSet) {
                // すでに立ち絵変更アクションが実行予定リストにある場合はブロックする
                break;
            } else {
                this->_actions.pop();
                result.push_back(nextAction);
                // 発言アクションは必ずブロックされる
                break;
            }
        } else if (nextAction->getType() == NovelAction::Type::Set) {
            bool* targetState = nullptr;
            switch (nextAction->getTarget()) {
                case NovelAction::Target::Left:
                    targetState = &leftSet;
                    break;
                case NovelAction::Target::Right:
                    targetState = &rightSet;
                    break;
                case NovelAction::Target::Narration:
                    targetState = &narrationSet;
                    break;
                case NovelAction::Target::Background:
                    targetState = &backgroundSet;
                    break;
                default:
                    break;
            }
            if (!*targetState) {
                this->_actions.pop();
                result.push_back(nextAction);
                *targetState = true;
            } else {
                // すでにこのターゲットに立ち絵を指定するアクションがセットに存在するのでブロックされる
                break;
            }
        } else if (nextAction->getType() == NovelAction::Type::Music ||
                   nextAction->getType() == NovelAction::Type::Effect ||
                   nextAction->getType() == NovelAction::Type::Location ||
                   nextAction->getType() == NovelAction::Type::Name ||
                   nextAction->getType() == NovelAction::Type::Clear ||
                   nextAction->getType() == NovelAction::Type::Flash ||
                   nextAction->getType() == NovelAction::Type::HideImage ||
                   nextAction->getType() == NovelAction::Type::HideImageInstant ||
                   nextAction->getType() == NovelAction::Type::ShowImage ||
                   nextAction->getType() == NovelAction::Type::ShowImageInstant ||
                   nextAction->getType() == NovelAction::Type::Shake) {
            // ノンブロッキング処理
            this->_actions.pop();
            result.push_back(nextAction);
        } else if (nextAction->getType() == NovelAction::Type::Introduction ||
                   nextAction->getType() == NovelAction::Type::Narration ||
                   nextAction->getType() == NovelAction::Type::Wait ||
                   nextAction->getType() == NovelAction::Type::Delay ||
                   nextAction->getType() == NovelAction::Type::LWF) {
            // ブロッキング処理
            this->_actions.pop();
            result.push_back(nextAction);
            break;
        }
    }
    
    return result;
}