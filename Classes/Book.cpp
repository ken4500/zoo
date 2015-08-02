//
//  Book.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/02.
//
//

#include "Book.h"

const int ANIMAL_NUM_IN_A_PAGE = 9;
using namespace cocos2d;

bool Book::init() {
    if (!Node::init()) {
        return false;
    }

    // load the character animation timeline
    this->timeline = CSLoader::createTimeline("Book.csb");
    // retain the character animation timeline so it doesn't get deallocated
    this->timeline->retain();

    auto back = LayerColor::create(Color4B(0, 0, 0, 100));
    addChild(back, -1);
    
    return true;
}

void Book::onEnter()
{
    Layer::onEnter();
    
    _page = 0;
    _selectImage = nullptr;
    _allSpecies = Species::getAllSpecies();
    _bookNode = this->getChildByName("book");
    ZUtil::printNode(this);

    for (int pos = 1; pos <= ANIMAL_NUM_IN_A_PAGE; pos++) {
        auto button = _bookNode->getChildByName<ui::Button*>(StringUtils::format("position%d", pos));
        button->addTouchEventListener(CC_CALLBACK_2(Book::_pushAnimalButton, this));
        button->setTag(pos);
    }


    // タッチイベントの設定
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(Book::onTouchBegan, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    _loadPage(_page);
}

// タッチイベント(モーダルの下のイベントを通さないために)
bool Book::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}

void Book::_loadPage(int page)
{
    int min = page * ANIMAL_NUM_IN_A_PAGE;
    int max = MIN((page + 1) * ANIMAL_NUM_IN_A_PAGE, (int)_allSpecies.size());
    
    
    for (int i = min, pos = 1; i < max; i++, pos++) {
//        auto species = _allSpecies[i];
        auto button = _bookNode->getChildByName(StringUtils::format("position%d", pos));
        auto size = button->getContentSize();
        auto image = button->getChildByName("image");
        if (image) {
            image->removeFromParent();
        }
        auto newImage = Sprite::create("book/unkonwn_animal.png");
        newImage->setName("image");
        newImage->setPosition(Vec2(size.width / 2, size.height / 2));
        button->addChild(newImage);
    }
}

void Book::_pushAnimalButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    auto size = button->getContentSize();
    auto pos = Vec2(size.width / 2, size.height / 2);
    if (_selectImage == nullptr) {
        _selectImage = Sprite::create("book/select_animal.png");
        button->addChild(_selectImage);
    } else {
        _selectImage->retain();
        _selectImage->removeFromParent();
        button->addChild(_selectImage);
        _selectImage->release();
    }

    _selectImage->setPosition(pos);
}

void Book::_pushRightButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
}

void Book::_pushLeftButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
}
