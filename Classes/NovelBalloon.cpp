//
//  NovelBalloon.cpp
//  zoo
//
//  Created by Ken Watanabe on 2014/09/23.
//
//

#include "NovelBalloon.h"
#include "SoundManager.h"

NovelBalloon::~NovelBalloon() {
    unscheduleAllSelectors();
    unscheduleUpdate();
}

void NovelBalloon::processTap() {
    // 通常のバルーンモード
    if (this->_textCompleted) {
        if (this->_arrowAction != NULL) {
            this->stopAction(this->_arrowAction);
            this->_arrowAction = NULL;
        }
        
        auto arrow = _balloonSprite->getChildByTag(10);
        if (arrow) {
            arrow->removeFromParent();
        }
        // 完了コールバックを実行する
        SoundManager::getInstance()->playNovelTap();
        this->_completionCallback();
    }
}

#define ONEMASK ((size_t)(-1) / 0xFF)

int unicodeCharacterCount(const char* strBytes) {
    const char *s;
    size_t count = 0;
    size_t u;
    unsigned char b;
    
    // Handle any initial misaligned bytes
    for (s = strBytes; (uintptr_t)(s) & (sizeof(size_t) - 1); s++) {
        b = *s;
        // Exit if we hit a zero byte
        if (b == '\0') {
            return (int)((s - strBytes) - count);
        }
        // Is this byte NOT the first byte of a character?
        count += (b >> 7) & ((~b) >> 6);
    }
    
    // Handle complete blocks
    for (; ; s += sizeof(size_t)) {
        // Prefetch 256 bytes ahead
        __builtin_prefetch(&s[256], 0, 0);
        // Grab 4 or 8 bytes of UTF-8 data
        u = *(size_t *)(s);
        // Exit the loop if there are any zero bytes
        if ((u - ONEMASK) & (~u) & (ONEMASK * 0x80)) {
            break;
        }
        // Count bytes which are NOT the first byte of a character
        u = ((u & (ONEMASK * 0x80)) >> 7) & ((~u) >> 6);
        count += (u * ONEMASK) >> ((sizeof(size_t) - 1) * 8);
    }
    
    // Take care of any left-over bytes
    for (; ; s++) {
        b = *s;
        // Exit if we hit a zero byte
        if (b == '\0') {
            break;
        }
        // Is this byte NOT the first byte of a character?
        count += (b >> 7) & ((~b) >> 6);
    }
    
    return (int)((s - strBytes) - count);
}

Label* NovelBalloon::getLabelSprite(const std::string& text) {
    auto fontName  = "ninja_font.fnt";
    auto fontColor = Color3B::BLACK;
    LabelColor color(text);
    Label* textLabel = Label::createWithBMFont(fontName, color.getRawString());
    textLabel->setAlignment(TextHAlignment::LEFT);
    textLabel->setWidth(3000);
    textLabel->setScale(0.75);
    textLabel->setAnchorPoint(Vec2(0, 1));

    // ナレーション用の設定
    if (_action->getTarget() == NovelAction::Target::Narration) {
        textLabel->setVerticalAlignment(cocos2d::TextVAlignment::CENTER);
        textLabel->setHorizontalAlignment(cocos2d::TextHAlignment::CENTER);
        textLabel->setWidth(640);
        textLabel->setHeight(200);
        textLabel->setScale(1.0);
        textLabel->setAnchorPoint(Vec2(0.5f, 0.5f));
        fontColor = Color3B::WHITE;
    }

    textLabel->setColor(Color3B::BLACK);
    int textLength = unicodeCharacterCount(color.getRawString().c_str());
    for (int i = 0; i < textLength; i++) {
        Sprite* charSpr = textLabel->getLetter(i);
        if (charSpr != NULL) {
            charSpr->setColor(fontColor);
        }
    }

    Node* labelNode = reinterpret_cast<Node*>(textLabel);
    labelNode->setZOrder(1);
    color.applyColor(textLabel);
    return textLabel;
}

void NovelBalloon::incrementText(bool forceFinish) {
    std::string text = this->_action->getValue();
    int textLength = unicodeCharacterCount(_contentSprite->getString().c_str());
    
    if (forceFinish) {
        // 強制的に最後まで表示
        this->_currentTextLength = textLength;
    } else {
        this->_currentTextLength++;
    }
    if (this->_currentTextLength > textLength) {
    }
    
    if (this->_contentSprite == NULL) {
    } else {
        for (int i = 0; i < _currentTextLength; i++) {
            Sprite* currentSpr = _contentSprite->getLetter(i);
            if (currentSpr != NULL && currentSpr->getOpacity() == 0 &&
                currentSpr->getNumberOfRunningActions() == 0) {
                if (forceFinish) {
                    currentSpr->setOpacity(255);
                } else {
                    currentSpr->setOpacity(0);
                    currentSpr->runAction(FadeIn::create(0.05));
                }
            }
        }
    }
    
    if (this->_currentTextLength == textLength) {
        this->unscheduleUpdate();
    }
}

void NovelBalloon::update(float delta) {
    std::string text = this->_action->getValue();
    int textLength = unicodeCharacterCount(_contentSprite->getString().c_str());
    _totalTime += delta;
    while (!_textCompleted && _totalTime >= 0.012 && textLength > _currentTextLength) {
        _totalTime -= 0.012;
        incrementText(false);
    }
}

void NovelBalloon::setLabelColor(cocos2d::Color3B color) {
    int textLength = unicodeCharacterCount(_contentSprite->getString().c_str());
    for (int i = 0; i < textLength; i++) {
        Sprite* currentSpr = _contentSprite->getLetter(i);
        if (currentSpr != NULL) {
            currentSpr->setColor(color);
        }
    }
}

void NovelBalloon::playBalloonSpecificAnimation() {
    switch (_action->getBalloon()) {
        case NovelAction::Balloon::Normal:
        case NovelAction::Balloon::Battle:
        case NovelAction::Balloon::Thought:
        case NovelAction::Balloon::Battle_Thought:
            break;
        case NovelAction::Balloon::Shout:
        case NovelAction::Balloon::Battle_Shout:
            if (_action->getTarget() == NovelAction::Target::Left) {
                _balloonSprite->runAction(Sequence::create(DelayTime::create(0.1f),
                                           Repeat::create(Sequence::create(MoveBy::create(0.04, Point(15.0f, 15.0f)),
                                                                           MoveBy::create(0.08, Point(-30.0f, -30.0f)),
                                                                           MoveBy::create(0.04, Point(15.0f, 15.0f)),
                                                                           NULL), 2),
                                           NULL));
            } else if (_action->getTarget() == NovelAction::Target::Right) {
                _balloonSprite->runAction(Sequence::create(DelayTime::create(0.1f),
                                           Repeat::create(Sequence::create(MoveBy::create(0.04, Point(-15.0f, 15.0f)),
                                                                           MoveBy::create(0.08, Point(30.0f, -30.0f)),
                                                                           MoveBy::create(0.04, Point(-15.0f, 15.0f)),
                                                                           NULL), 2),
                                           NULL));
            }
            break;
        default:
            break;
    }
}

void NovelBalloon::showArrow() {
    _arrowAction = runAction(Sequence::create(
        DelayTime::create(0.5f),
        CallFunc::create([this]() {
            if (_arrowAction == NULL) {
                return;
            }
            _arrowAction = NULL;
            
            auto arrow = Node::create();
            arrow->setTag(10);
            arrow->setPosition(this->_arrowPos);
            auto parts1 = Sprite::create("chat/ui/tap.png");
            parts1->setPosition(Vec2(0, 22));
            arrow->addChild(parts1, 2);
            this->_balloonSprite->addChild(arrow);

            parts1->runAction(RepeatForever::create(Sequence::create(
                EaseInOut::create(MoveBy::create(0.7f, Vec2(0, 20)), 2),
                EaseInOut::create(MoveBy::create(0.7f, Vec2(0, -20)), 2),
                NULL
            )));
        }),
        NULL
    ));
}


void NovelBalloon::setOpacity(GLubyte opacity)
{
    Node::setOpacity(opacity);
    if (this->_contentSprite != NULL) {
        auto textSpr = this->_contentSprite;
        int textLength = unicodeCharacterCount(textSpr->getString().c_str());
        for (int i = 0; i <= textLength; i++) {
            Node* currentNode = textSpr->getLetter(i);
            if (currentNode == NULL) {
                continue;
            }
            currentNode->setOpacity(opacity);
        }
    }
}


NovelBalloon* NovelBalloon::create(std::shared_ptr<NovelAction> action,
                                   int balloonIdx,
                                   std::function<void ()> completionCallback) {
    NovelBalloon* result = new NovelBalloon();
    result->_completionCallback = completionCallback;
    result->_action = action;
    result->_balloonIdx = balloonIdx;
    result->setCascadeOpacityEnabled(true);

    Sprite* balloon;
    Vec2 labelPos = Vec2(65, 130);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    switch (action->getBalloon()) {
        case NovelAction::Balloon::Normal:
        case NovelAction::Balloon::Shout:
            balloon = Sprite::create("chat/ui/fukidashi.png");
            result->_arrowPos = Point(balloon->getContentSize().width - 50, 0);
            balloon->setAnchorPoint(Vec2(0.5, 0.5));
            if (action->getTarget() == NovelAction::Target::Left) {
                balloon->setPosition(Vec2(visibleSize.width/ 2 - 40, 150));
            } else if (action->getTarget() == NovelAction::Target::Right) {
                balloon->setPosition(Vec2(-visibleSize.width/ 2 + 40, 100));
                balloon->setFlippedX(true);
            }
            break;
        default:
            if (action->getTarget() == NovelAction::Target::Narration) {
                balloon = Sprite::create("clear_box_black_640x200.png");
                result->_arrowPos = Point(600, 20);
                balloon->setAnchorPoint(Vec2(0.5, 0.5));
                balloon->setPosition(Vec2(visibleSize.width /2, visibleSize.height / 2));
                labelPos = Vec2(balloon->getContentSize().width / 2, 100);
            }
            break;
    }
    result->_balloonSprite = balloon;
    result->addChild(balloon);

    // テキストラベルの生成
    Label* textSpr = result->getLabelSprite(action->getValue());
    result->_contentSprite = textSpr;

    // テキストのスプライトを生成してみて最終的なテキスト高さを計算する
    Size finalSize = textSpr->getContentSize();
    textSpr->setPosition(labelPos);
    result->_balloonSprite->addChild(textSpr);
    int textLength = unicodeCharacterCount(textSpr->getString().c_str());
    for (int i = 0; i <= textLength; i++) {
        Node* currentNode = textSpr->getLetter(i);
        if (currentNode == NULL) {
            continue;
        }
        currentNode->setOpacity(0);
    }

    // テキスト表示スタート
    if (!action->getValue().empty()) {
        result->scheduleUpdate();
    }
    result->_balloonSprite->runAction(Sequence::create(
        DelayTime::create(0.012f * textLength + 0.08f),
        CallFunc::create([result, action]() {
            result->_textCompleted = true;
            if (action->getTarget() != NovelAction::Target::Narration) {
                result->showArrow();
            }
        }),
        NULL
    ));

    return result;
}
