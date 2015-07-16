//
//  NovelTouchHandler.h
//  zoo
//
//  Created by Ken Watanabe on 2014/09/24.
//
//

#ifndef ninjya_NovelTouchHandler_h
#define ninjya_NovelTouchHandler_h

class NovelTouchHandler {
public:
    virtual void processTap() = 0;
    virtual ~NovelTouchHandler() {};
};

class NovelTouchDummyHandler : public NovelTouchHandler {
private:
    std::function<void ()> _callback;
public:
    NovelTouchDummyHandler(std::function<void ()> callback) {
        _callback = callback;
    }
    virtual void processTap() override {
        if (_callback != nullptr) {
            auto callbackBackup = _callback;
            _callback = nullptr;
            callbackBackup();
        }
    }
};

#endif
