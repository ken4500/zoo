//
//  AdColonyAdsWrapper.h
//  PluginAdColony
//
//  Created by Xiaofan Dai on 2/27/15.
//  Copyright (c) 2015 Glossom, Inc. All rights reserved.
//
#import <Foundation/Foundation.h>

#import "AdsWrapper.h"
#include "AdColonyAgent.h"

@interface AdColonyAdsWrapper : AdsWrapper

+ (void) onAdsResult:(id) obj withZoneID:(NSString *)zoneID withRet:(AdColonyAdsResultCode) ret withMsg:(NSString*) msg;
+ (void) onPlayerGetPoints:(id) obj withZoneID:(NSString *)zoneID withSuccess:(BOOL)success withName:(NSString *)name withPoints: (int) points;

@end
