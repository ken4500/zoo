//
//  NativeLauncher.h
//  Noen
//
//  Created by Taisuke Fujita on 2015/02/05.
//
//

#ifndef Noen_NativeLauncher_h
#define Noen_NativeLauncher_h

#include "cocos2d.h"

namespace cocos2dext {

    class NativeLauncher {

    public:
        
        static void openTweetDialog(std::string tweet, std::function<void (bool)> callback);

        static void openFacebookDialog(std::string msg, std::function<void (bool)> callback);
        
        static void openReviewPage();
        
        static void loginGameCenter();

        static void postHighScore(int score);
        
        static void showBanner();
        
        static void hideBanner();
        
        static void showLocalNotification(std::string message, int interval, int tag);
        
        static void cancelAllLocalNotification();
    
    };
    
}

#endif
