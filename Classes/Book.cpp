//
//  Book.cpp
//  Zoo
//
//  Created by Ken Watanabe on 2015/08/02.
//
//

#include "Book.h"
#include "SoundManager.h"
#include "UserDataManager.h"

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
    
    _page = 1;
    _selectImage = nullptr;
    _allSpecies = Species::getAllSpecies();
    _bookNode = this->getChildByName("book");
    _animalImage = _bookNode->getChildByName<Sprite*>("image");
    _description = _bookNode->getChildByName<ui::Text*>("description");
    _animalName  = _bookNode->getChildByName<ui::TextBMFont*>("name");
    _sizeDescription = _bookNode->getChildByName<ui::Text*>("size");
    _pageLabel = this->getChildByName<ui::TextBMFont*>("pageLabel");

    for (int pos = 1; pos <= ANIMAL_NUM_IN_A_PAGE; pos++) {
        auto button = _bookNode->getChildByName<ui::Button*>(StringUtils::format("position%d", pos));
        button->addTouchEventListener(CC_CALLBACK_2(Book::_pushAnimalButton, this));
        button->setTag(pos);
    }
    
    _selectPos = 1;
    _pushAnimalButton((Ref*)_bookNode->getChildByName(StringUtils::format("position%d", _selectPos)), ui::Widget::TouchEventType::ENDED);
    
    _rightButton = getChildByName<ui::Button*>("rightButton");
    _rightButton->addTouchEventListener(CC_CALLBACK_2(Book::_pushRightButton, this));
    _leftButton = getChildByName<ui::Button*>("leftButton");
    _leftButton->addTouchEventListener(CC_CALLBACK_2(Book::_pushLeftButton, this));
    auto closeButton = getChildByName<ui::Button*>("closeButton");
    closeButton->addTouchEventListener(CC_CALLBACK_2(Book::_pushCloseButton, this));

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
    int min = (page - 1) * ANIMAL_NUM_IN_A_PAGE;
    int max = page * ANIMAL_NUM_IN_A_PAGE;
    int maxSpecies = (int)_allSpecies.size();
    
    _pageLabel->setString(StringUtils::format("%d / %d", page, _getMaxPage()));
    
    for (int i = min, pos = 1; i < max; i++, pos++) {
        auto button = _bookNode->getChildByName<ui::Button*>(StringUtils::format("position%d", pos));
        if (i >= maxSpecies) {
            button->setVisible(false);
            button->setEnabled(false);
            continue;
        } else {
            button->setVisible(true);
            button->setEnabled(true);
        }

        auto species = _allSpecies[i];
        auto size = button->getContentSize();
        auto image = button->getChildByName("image");
        if (image) {
            image->removeFromParent();
        }

        Sprite* newImage;
        if (UserDataManager::getInstance()->haveHadAnimalInPast(species->getName())) {
            newImage = Sprite::create(species->getImageName());
            newImage->setScale(0.25f);
        } else {
            newImage = Sprite::create("book/unkonwn_animal.png");
        }

        newImage->setName("image");
        newImage->setPosition(Vec2(size.width / 2, size.height / 2));
        button->addChild(newImage);
    }
    
    if (page == 1) {
        _leftButton->setEnabled(false);
        _leftButton->setOpacity(100);
        _rightButton->setEnabled(true);
        _rightButton->setOpacity(255);
    } else if (page == _getMaxPage()) {
        _leftButton->setEnabled(true);
        _leftButton->setOpacity(255);
        _rightButton->setEnabled(false);
        _rightButton->setOpacity(100);
    } else {
        _leftButton->setEnabled(true);
        _leftButton->setOpacity(255);
        _rightButton->setEnabled(true);
        _rightButton->setOpacity(255);
    }
}

void Book::_loadAnimal(Species* species)
{
    _animalImage->setTexture(species->getImageName());
    _animalName->setString(CCLS(species->getName().c_str()));
    Weight min = Weight(species->getMinHeight(), species->getDensity());
    Weight max = Weight(species->getMaxHeight(), species->getDensity());
    _sizeDescription->setString(StringUtils::format("%.02f%s 〜 %.02f%s", min.getWeight(), min.getUnitStr().c_str(), max.getWeight(), max.getUnitStr().c_str()));
    _description->setString("hogehogehoge");
}

void Book::_pushAnimalButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
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
        
        int index = button->getTag() + (_page - 1) * ANIMAL_NUM_IN_A_PAGE - 1;
        auto species = _allSpecies[index];
        _loadAnimal(species);
    }
}

void Book::_pushRightButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        button->runAction(Sequence::create(
            ScaleBy::create(0.1f, 1 / 0.9f),
            CallFunc::create([this]{
                _page = MIN(_page + 1, _getMaxPage());
                _loadPage(_page);
                _pushAnimalButton((Ref*)_bookNode->getChildByName(StringUtils::format("position%d", _selectPos)), ui::Widget::TouchEventType::ENDED);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void Book::_pushLeftButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        button->runAction(Sequence::create(
            ScaleBy::create(0.1f, 1 / 0.9f),
            CallFunc::create([this]{
                _page = MAX(_page - 1, 1);
                _loadPage(_page);
                _pushAnimalButton((Ref*)_bookNode->getChildByName(StringUtils::format("position%d", _selectPos)), ui::Widget::TouchEventType::ENDED);
            }),
            NULL
        ));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}

void Book::_pushCloseButton(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    auto button = dynamic_cast<ui::Button*>(pSender);
    if (eEventType == ui::Widget::TouchEventType::BEGAN) {
        button->runAction(ScaleBy::create(0.1f, 0.9));
    }
    if (eEventType == ui::Widget::TouchEventType::ENDED) {
        SoundManager::getInstance()->playDecideEffect2();
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
        this->runAction(Sequence::create(FadeOut::create(0.3f), RemoveSelf::create(), NULL));
    }
    if (eEventType == ui::Widget::TouchEventType::CANCELED) {
        button->runAction(ScaleBy::create(0.1f, 1 / 0.9f));
    }
}


int Book::_getMaxPage()
{
    return (int)ceilf(float(_allSpecies.size()) / ANIMAL_NUM_IN_A_PAGE);
}
