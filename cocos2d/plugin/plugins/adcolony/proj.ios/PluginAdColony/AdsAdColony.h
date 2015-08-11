//
//  PluginAdColony.h
//  PluginAdColony
//
//  Created by Junhua Li on 2015/02/24.
//  Copyright (c) 2015年 Glossom, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "InterfaceAds.h"
#import <AdColony/AdColony.h>

@interface AdsAdColony : NSObject <InterfaceAds, AdColonyDelegate, AdColonyAdDelegate>

@property BOOL debug;

@property(nonatomic, readonly) UIWindow* keyWindow;
@property(nonatomic, readonly) UIWindow* videoWindow;
@property(nonatomic, readonly) UIViewController * keyWindowViewController;


@end
