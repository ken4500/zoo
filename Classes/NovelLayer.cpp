//
//  NovelLayer.cpp
//  zoo
//
//  Created by Ken Watanabe on 2014/09/21.
//
//

#include "NovelLayer.h"
#include "SoundManager.h"
#include "UserDataManager.h"

NovelLayer::NovelLayer()
{
    
}

NovelLayer::~NovelLayer()
{
    
}

NovelLayer* NovelLayer::create(rapidjson::Value& novelJson, GLubyte opacity, bool fade, std::function<void ()> callback, std::function<void ()> callback2) {
    auto result = NovelLayer::create();
    result->_endCallback = callback;
    result->_endCallback2 = callback2;
    result->_targetOpacity = opacity;
    if (fade) {
        result->setOpacity(0);
    } else {
        result->setOpacity(opacity);
    }
    result->_playFade = fade;
    rapidjson::Value& actions = novelJson["actions"];
    result->_player = new NovelPlayer(actions);
    
    return result;
}

bool NovelLayer::init()
{
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0))) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    setContentSize(visibleSize);

    
    // アトラス読み込み
//    auto cache = SpriteFrameCache::getInstance();
//    cache->addSpriteFramesWithFile("chat_images.plist","chat_images.png");
    
    //  touch callbacks
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [this](Touch* touch, Event* event) {
        if (this->_touchAbsorber != NULL) {
            this->_touchAbsorber->processTap();
        }
        return true;
    };
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // skipボタン作成
    auto skipItem = MenuItemImage::create("ui/skip_button.png", "ui/skip_button.png", CC_CALLBACK_1(NovelLayer::_pushedSkipButton, this));
    skipItem->setAnchorPoint(Vec2(1.0f, 1.0f));
    skipItem->setPosition(Vec2(visibleSize.width - 20, visibleSize.height - 20));
    auto menu = Menu::create(skipItem, NULL);
    menu->setPosition(Vec2::ZERO);
    menu->setName("skip_menu");
    addChild(menu, 1);

    return true;
}

void NovelLayer::completeAction(int actionIdx) {
    std::set<int>::iterator actionItr = _inProgressActions.find(actionIdx);
    if (actionItr == _inProgressActions.end()) {
        return;
    }
    _inProgressActions.erase(actionItr);
    
    if (_inProgressActions.empty()) {
        this->playNext();
    }
}

int NovelLayer::beginAction() {
    int actionIdx = _actionIdx;
    _actionIdx++;
    _inProgressActions.insert(actionIdx);
    return actionIdx;
}

void NovelLayer::updateSpeechBalloon(NovelAction* action) {
    int actionIdx = this->beginAction();
    auto targetBalloon = NovelBalloon::create(action,
                                              _balloonIdx,
                                              [this, actionIdx]() {
                                                  this->_touchAbsorber = NULL;
                                                  this->completeAction(actionIdx);
                                                  if (_debugSkip == 1) {
                                                      this->endScene();
                                                  }
                                              });
    targetBalloon->setCascadeColorEnabled(true);
    

    _balloonIdx++;
    float offset = 0.0f;
    if (action->getTarget() == NovelAction::Target::Right) {
        offset = -50.0f;
    } else if (action->getTarget() == NovelAction::Target::Left) {
        offset = 50.0f;
    }
    auto currentPos = targetBalloon->getPosition();
    currentPos.x -= offset;
    targetBalloon->setPosition(currentPos);
    targetBalloon->runAction(EaseExponentialOut::create(MoveBy::create(0.15f, Point(offset, 0))));
    targetBalloon->playBalloonSpecificAnimation();
    this->_touchAbsorber = targetBalloon;

    if (action->getTarget() == NovelAction::Target::Right) {
        if (this->_rightBalloon) {
            this->_rightBalloon->removeFromParent();
        }
        if (this->_defaultBalloon) {
            this->_defaultBalloon->removeFromParent();
        }
        if (this->_leftBalloon) {
            this->_leftBalloon->setOpacity(128);
            this->_rightNode->setZOrder(2);
            this->_leftNode->setZOrder(1);
        }
        _rightNode->addChild(targetBalloon);
        this->_rightBalloon = targetBalloon;
    } else if (action->getTarget() == NovelAction::Target::Left) {
        if (this->_leftBalloon) {
            this->_leftBalloon->removeFromParent();
        }
        if (this->_defaultBalloon) {
            this->_defaultBalloon->removeFromParent();
        }
        if (this->_rightBalloon) {
            this->_rightBalloon->setOpacity(128);
            this->_rightNode->setZOrder(1);
            this->_leftNode->setZOrder(2);
        }
        _leftNode->addChild(targetBalloon);
        this->_leftBalloon = targetBalloon;
    } else if (action->getTarget() == NovelAction::Target::Narration) {
        if (this->_leftBalloon) {
            this->_leftBalloon->setOpacity(128);
        }
        if (this->_rightBalloon) {
            this->_rightBalloon->setOpacity(128);
        }
        if (this->_defaultBalloon) {
            this->_defaultBalloon->removeFromParent();
        }
        this->_defaultBalloon = targetBalloon;
        this->addChild(targetBalloon);
    }
}

void NovelLayer::clearBalloons() {
    if (this->_leftBalloon != NULL) {
        this->_leftBalloon->removeFromParent();
        this->_leftBalloon = NULL;
    }
    if (this->_rightBalloon != NULL) {
        this->_rightBalloon->removeFromParent();
        this->_rightBalloon = NULL;
    }
    if (this->_defaultBalloon != NULL) {
        this->_defaultBalloon->removeFromParent();
        this->_defaultBalloon = NULL;
    }
    _balloonIdx = 0;
}

void NovelLayer::beginScene() {
    this->clearBalloons();
    
    this->_isSceneBreak = false;
    this->_inProgressActions.clear();
    
    this->playNext();
}

void NovelLayer::endScene() {
    if (_endCallback != NULL) {
        _endCallback();
    }
    if (_endCallback2 != NULL) {
        _endCallback2();
    }
}

void NovelLayer::playDelay(NovelAction* action) {
    const float delayTime = ::atof(action->getValue().c_str());
    int actionIdx = beginAction();
    runAction(Sequence::create(DelayTime::create(delayTime),
                               CallFunc::create([this, actionIdx]() { this->completeAction(actionIdx); }),
                               NULL));
}

void NovelLayer::playWait() {
}

void NovelLayer::showItem(NovelAction* action, const bool fade) {
}

void NovelLayer::hideItem(bool fade) {
}

void NovelLayer::setImage(NovelAction* action)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto value = action->getValue();
    auto imageName = action->getValue();
    auto target = action->getTarget();
    auto effect = action->getValue2();
    if (target == NovelAction::Target::Left) {
        imageName = StringUtils::format("chat/character/chat_%s.png", imageName.c_str());
        if (_leftChara == NULL) {
            _leftNode = Node::create();
            _leftNode->setPosition(Vec2(0, 0));
            _leftChara = Sprite::create(imageName);
            _leftChara->setAnchorPoint(Vec2(0, 0));
            _leftChara->setPosition(Vec2(20, 50));
            addChild(_leftNode);
            _leftNode->addChild(_leftChara);
        } else {
            if (value == "remove") {
                _leftNameImage->removeFromParent();
                _leftNameImage = NULL;
                _leftChara->removeFromParent();
                _leftChara = NULL;
                _leftBalloon->removeFromParent();
                _leftBalloon = NULL;
                _leftNode->removeFromParent();
                _leftNode = NULL;
            } else {
                _leftChara->setTexture(imageName);
            }
        }
    } else if (target == NovelAction::Target::Right) {
        imageName = StringUtils::format("chat/character/chat_%s.png", imageName.c_str());
        if (_rightChara == NULL) {
            _rightNode = Node::create();
            _rightNode->setPosition(Vec2(visibleSize.width, 0));
            _rightChara = Sprite::create(imageName);
            _rightChara->setAnchorPoint(Vec2(1, 0));
            _rightChara->setPosition(Vec2(-20, 50));
            addChild(_rightNode);
            _rightNode->addChild(_rightChara);
        } else {
            if (value == "remove") {
                _rightNameImage->removeFromParent();
                _rightNameImage = NULL;
                _rightChara->removeFromParent();
                _rightChara = NULL;
                _rightBalloon->removeFromParent();
                _rightBalloon = NULL;
                _rightNode->removeFromParent();
                _rightNode = NULL;
            } else {
                _rightChara->setTexture(imageName);
            }
        }
    } else if (target == NovelAction::Target::Background) {
        if (value == "remove") {
            if (effect == "nextPage") {
                _backGroundImage->runAction(Sequence::create(
                    PageTurn3D::create(0.6f, Size(100, 100)),
                    RemoveSelf::create(),
                    NULL
                ));
            } else if (effect == "fade") {
                _backGroundImage->runAction(Sequence::create(FadeOut::create(1.0f), RemoveSelf::create(), NULL));
            } else {
                _backGroundImage->removeFromParent();
            }
            _backGroundImage = NULL;
        } else {
            if (_backGroundImage == NULL) {
                auto back = Sprite::create(StringUtils::format("chat/back/%s", imageName.c_str()));
                back->setScale(visibleSize.width/back->getContentSize().width);
                back->setAnchorPoint(Vec2(0, 0));
                back->setPosition(Vec2::ZERO);
                back->setZOrder(-1);
                _backGroundImage = NodeGrid::create();
                _backGroundImage->addChild(back);
                _backGroundImage->setCascadeOpacityEnabled(true);
                addChild(_backGroundImage);
                
            } else {
                clearBalloons();
                
                auto removedImage = _backGroundImage;

                auto back = Sprite::create(StringUtils::format("chat/back/%s", imageName.c_str()));
                back->setScale(visibleSize.width/back->getContentSize().width);
                back->setAnchorPoint(Vec2(0, 0));
                back->setPosition(Vec2::ZERO);
                back->setZOrder(removedImage->getZOrder()-1);
                _backGroundImage = NodeGrid::create();
                _backGroundImage->addChild(back);
                _backGroundImage->setCascadeOpacityEnabled(true);
                addChild(_backGroundImage);
                
                if (effect == "nextPage") {
                    removedImage->runAction(Sequence::create(
                        PageTurn3D::create(0.6f, Size(100, 100)),
                        RemoveSelf::create(),
                        NULL
                    ));
                } else {
                    auto dummyBack = LayerColor::create(Color4B::BLACK, visibleSize.width, visibleSize.height);
                    addChild(dummyBack, -100);
                    dummyBack->runAction(Sequence::create(
                        DelayTime::create(1.0f),
                        RemoveSelf::create(),
                        NULL
                    ));

                    removedImage->runAction(Sequence::create(
                        FadeOut::create(1.0f),
                        RemoveSelf::create(),
                        NULL
                    ));
                
                    _backGroundImage->setOpacity(0);
                    _backGroundImage->runAction(FadeIn::create(1.0f));
                }

            }
        }
    }
}

void NovelLayer::setNameImage(NovelAction* action)
{
    auto name = action->getValue();
    auto target = action->getTarget();
    LanguageType curLanguage = UserDataManager::getInstance()->getLanguage();
    if (target == NovelAction::Target::Left) {
        if (_leftNameImage == NULL) {
            _leftNameImage = Sprite::create("chat/ui/name_rect.png");
            _leftNameImage->setAnchorPoint(Vec2::ZERO);
            _leftNameImage->setPosition(Vec2(20, 20));
            _leftNode->addChild(_leftNameImage, 11);
            auto nameImageSize = _leftNameImage->getContentSize();
            Label* label1;
            if (curLanguage == LanguageType::CHINESE) {
                label1 = Label::createWithTTF(name.c_str(), "font/simiyo.ttf", 30);
            } else {
                label1 = Label::createWithTTF(name.c_str(), "font/yasashisa.ttf", 30);

            }
            label1->setName("label");
            label1->setColor(Color3B::WHITE);
            label1->setAnchorPoint(Vec2(0.5f, 0.5f));
            label1->setPosition(Vec2(nameImageSize.width / 2, nameImageSize.height / 2));
            _leftNameImage->addChild(label1);
        } else {
            auto label = (Label*)_leftNameImage->getChildByName("label");
            label->setString(name);
        }
    } else if (target == NovelAction::Target::Right) {
        if (_rightNameImage == NULL) {
            _rightNameImage = Sprite::create("chat/ui/name_rect.png");
            _rightNameImage->setAnchorPoint(Vec2(1, 0));
            _rightNameImage->setPosition(Vec2(-20, 20));
            _rightNode->addChild(_rightNameImage, 11);
            auto nameImageSize = _rightNameImage->getContentSize();
            Label* label1;
            if (curLanguage == LanguageType::CHINESE) {
                label1 = Label::createWithTTF(name.c_str(), "font/simiyo.ttf", 30);
            } else {
                label1 = Label::createWithTTF(name.c_str(), "font/yasashisa.ttf", 30);
                
            }
            label1->setName("label");
            label1->setAnchorPoint(Vec2(0.5, 0.5f));
            label1->setColor(Color3B::WHITE);
            label1->setPosition(Vec2(nameImageSize.width / 2, nameImageSize.height / 2));
            _rightNameImage->addChild(label1);
        } else {
            auto label = (Label*)_rightNameImage->getChildByName("label");
            label->setString(name);
        }
    }
}

void NovelLayer::playNext() {
    // 次のアクションセット取得
    auto actions = this->_player->popNextActions();
    if (actions.empty()) {
        // アクションが無いのでシーン終了
        this->endScene();
    } else {
        int rootActionIdx = this->beginAction();
        // 取得したアクションを実行する
        for (auto action : actions) {
            switch (action->getType()) {
                case NovelAction::Type::Set:
                    setImage(action);
                    break;
                case NovelAction::Type::Name:
                    setNameImage(action);
                    break;
                case NovelAction::Type::Speak:
                case NovelAction::Type::Narration:
                    this->updateSpeechBalloon(action);
                    break;
                case NovelAction::Type::Delay:
                    this->playDelay(action);
                    break;
                case NovelAction::Type::Shake:
                    break;
                case NovelAction::Type::Wait:
                    this->playWait();
                    break;
                case NovelAction::Type::Clear:
                    this->clearBalloons();
                    break;
                case NovelAction::Type::ShowImage:
                    this->showItem(action, true);
                    break;
                case NovelAction::Type::ShowImageInstant:
                    this->showItem(action, false);
                    break;
                case NovelAction::Type::HideImage:
                    this->hideItem(true);
                    break;
                case NovelAction::Type::HideImageInstant:
                    this->hideItem(false);
                    break;
                case NovelAction::Type::Music:
                    if (action->getValue() == "fadeout") {
                        SoundManager::getInstance()->fadeOutBgm(1.0f);
                    } else {
                        SoundManager::getInstance()->playBgm(action->getValue());
                    }
                    break;
                case NovelAction::Type::Effect:
                    SoundManager::getInstance()->playEffect(action->getValue());
                    break;
                default:
                    break;
            }
        }
        this->completeAction(rootActionIdx);
    }
}

void NovelLayer::playNovel() {
    if (this->_isPlaying) {
        return;
    }
    this->_isPlaying = true;
    if (this->_playFade) {
        this->runAction(Sequence::create(FadeTo::create(0.5, this->_targetOpacity),
                                         CallFunc::create([this]() { this->playNext(); }),
                                         NULL));
    } else {
        this->playNext();
    }
    this->_preloadFinished = true;
}

void NovelLayer::_pushedSkipButton(Ref* sender)
{
    SoundManager::getInstance()->playCancellEffect();
    
    // 一番最後のBGMを探して再生
    NovelAction* bgm = _player->getLastMusic();
    if (bgm != nullptr) {
        SoundManager::getInstance()->playBgm(bgm->getValue());
    }
    
    this->endScene();
}

void NovelLayer::removeSkipButton()
{
    auto skipMenu = getChildByName("skip_menu");
    if (skipMenu) {
        skipMenu->removeFromParent();
    }
}
