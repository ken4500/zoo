//
//  NetworkingWrapper.h
//  Doodler
//
//  Created by Daniel Haaser on 5/25/15.
//
//

#ifndef Noen_NativeLauncher_h
#define Noen_NativeLauncher_h

#include "cocos2d.h"

namespace cocos2dext {
    
    class NativeLauncher {
        
    public:
        
        static void showLocalNotification(std::string message, int interval, int tag);
        
        static void cancelAllLocalNotification();
    };
    
}

#endif
