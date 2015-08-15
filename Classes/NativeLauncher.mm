#include "NativeLauncher.h"
#import <Social/Social.h>
#import <GameKit/GameKit.h>
#import "AppController.h"

namespace cocos2dext
{
    
    void NativeLauncher::showLocalNotification(std::string message, int interval, int tag)
    {
        // 通知を作成する
        UILocalNotification *notification = [[UILocalNotification alloc] init];
        
        notification.fireDate = [[NSDate date] dateByAddingTimeInterval:interval];
        notification.timeZone = [NSTimeZone defaultTimeZone];
        notification.alertBody = [NSString stringWithCString:message.c_str()
                                                    encoding:NSUTF8StringEncoding];
        notification.alertAction = @"Open";
        notification.soundName = UILocalNotificationDefaultSoundName;
        
        NSNumber* tag1 = [NSNumber numberWithInteger:tag];
        NSDictionary *infoDict = [NSDictionary dictionaryWithObject:tag1 forKey:@"ID"];
        notification.userInfo = infoDict;
        
        // 通知を登録する
        [[UIApplication sharedApplication] scheduleLocalNotification:notification];
        
        [notification release];
    }
    
    void NativeLauncher::cancelLocalNotification(int tag)
    {
        for(UILocalNotification *notification in [[UIApplication sharedApplication] scheduledLocalNotifications]) {
            if([[notification.userInfo objectForKey:@"ID"] integerValue] == tag) {
                [[UIApplication sharedApplication] cancelLocalNotification:notification];
            }
        }
    }
    
}