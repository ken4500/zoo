#include "AppDelegate.h"
#include "MainScene.h"
#include "TitleScene.h"
#include "Constants.h"
#include "NativeLauncher.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("Zoo", Rect(0, 0, 1136, 640));
        director->setOpenGLView(glview);
    }

    glview->setDesignResolutionSize(1136, 640, ResolutionPolicy::FIXED_WIDTH);

    // turn on display FPS
    if (DEBUG_MODE) {
        director->setDisplayStats(true);
    }

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / GAME_FPS);

    FileUtils::getInstance()->addSearchPath("res");
    FileUtils::getInstance()->addSearchPath("res/animal");

    // create a scene. it's an autorelease object
    auto scene = TitleScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    int saveTime = (int)time(NULL);
    auto defaults = UserDefault::getInstance();
    defaults->setIntegerForKey("saveTime", saveTime);
    defaults->flush();
    
    cocos2dext::NativeLauncher::cancelAllLocalNotification();
    cocos2dext::NativeLauncher::showLocalNotification(CCLS("PUSH_NOTIFICATION_2DAYS"), 60 * 60 * 24 * 2, 1);
    cocos2dext::NativeLauncher::showLocalNotification(CCLS("PUSH_NOTIFICATION_1WEEK"), 60 * 60 * 24 * 7, 2);
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
