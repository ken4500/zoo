//
//  NativeLauncher.m
//  Noen
//
//  Created by Taisuke Fujita on 2015/02/05.
//
//

#include "NativeLauncher.h"
#include "Constants.h"
#import <GameKit/GameKit.h>
#import "AppController.h"
#import <Social/Social.h>
#import "Config.h"

namespace cocos2dext
{
    void NativeLauncher::openTweetDialog(std::string $tweet, std::function<void (bool)> callback)
    {
        UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
        while (topController.presentedViewController) {
            topController = topController.presentedViewController;
        }

        SLComposeViewController *vc = [SLComposeViewController
                                       composeViewControllerForServiceType:SLServiceTypeTwitter];
        NSString *tweet = [NSString stringWithUTF8String:$tweet.c_str()];
//        NSString *filePath = [NSString stringWithUTF8String:$filePath.c_str()];
        [vc setInitialText:tweet];
//        [vc addImage:[UIImage imageNamed:filePath]];
        [vc addURL:[NSURL URLWithString:[NSString stringWithFormat:@"https://itunes.apple.com/jp/app/id%d", IOS_APP_ID]]];
        vc.completionHandler = ^(SLComposeViewControllerResult res) {
            if (res == SLComposeViewControllerResultDone) {
                callback(true);
            } else if (res == SLComposeViewControllerResultCancelled) {
                callback(false);
            }
        };
        [topController presentViewController:vc animated:YES completion:nil];
    }

    void NativeLauncher::openFacebookDialog(std::string $msg, std::function<void (bool)> callback)
    {
        UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
        while (topController.presentedViewController) {
            topController = topController.presentedViewController;
        }

        NSString *msg = [NSString stringWithUTF8String:$msg.c_str()];
//        NSString *filePath = [NSString stringWithUTF8String:$filePath.c_str()];
        SLComposeViewController *vc = [SLComposeViewController
                                       composeViewControllerForServiceType:SLServiceTypeFacebook];
        [vc setInitialText:msg];
//        [vc addImage:[UIImage imageNamed:filePath]];
        [vc addURL:[NSURL URLWithString:[NSString stringWithFormat:@"https://itunes.apple.com/jp/app/id%d", IOS_APP_ID]]];
        vc.completionHandler = ^(SLComposeViewControllerResult res) {
            if (res == SLComposeViewControllerResultDone) {
                callback(true);
            } else if (res == SLComposeViewControllerResultCancelled) {
                callback(false);
            }
        };
        [topController presentViewController:vc animated:YES completion:nil];
    }
    
    void NativeLauncher::openReviewPage()
    {
        NSURL *reivewURL = [NSURL URLWithString:[NSString stringWithFormat:@"https://itunes.apple.com/jp/app/id%d", IOS_APP_ID]];
        [[UIApplication sharedApplication] openURL:reivewURL];
    }

    void NativeLauncher::loginGameCenter()
    {
        GKLocalPlayer *localPlayer = [GKLocalPlayer localPlayer];
        localPlayer.authenticateHandler = ^(UIViewController *viewController, NSError *error) {
            if (localPlayer.authenticated) {
                NSLog(@"Loged in.");
            } else {
                NSLog(@"Error : %@", error);
            }
        };
    }
    
    void NativeLauncher::postHighScore(int score)
    {
        GKLocalPlayer *localPlayer = [GKLocalPlayer localPlayer];
        if([localPlayer isAuthenticated]) {
            NSString *idName = [NSString stringWithUTF8String:"total"];
            GKScore *gkScore = [[GKScore alloc] initWithLeaderboardIdentifier:idName];
            gkScore.value = score;
            [GKScore reportScores:@[gkScore] withCompletionHandler:^(NSError *error) {
                if (error) {
                    NSLog(@"Error : %@", error);
                }
            }];
        } else {
            NativeLauncher::loginGameCenter();
        }
    }
}
