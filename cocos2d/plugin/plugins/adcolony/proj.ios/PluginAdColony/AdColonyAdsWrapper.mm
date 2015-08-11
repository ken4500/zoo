//
//  AdColonyAdsWrapper.m
//  PluginAdColony
//
//  Created by Xiaofan Dai on 2/27/15.
//  Copyright (c) 2015 Glossom, Inc. All rights reserved.
//

#import "AdColonyAdsWrapper.h"
#include "PluginUtilsIOS.h"

using namespace cocos2d::plugin;

@implementation AdColonyAdsWrapper

+ (void) onAdsResult:(id) obj withZoneID:(NSString *)zoneID withRet:(AdColonyAdsResultCode) ret withMsg:(NSString*) msg{
  
  PluginProtocol* plugin = PluginUtilsIOS::getPluginPtr(obj);
  ProtocolAds* adsPlugin = dynamic_cast<ProtocolAds*>(plugin);
  if (adsPlugin) {
    const char* chMsg = [msg UTF8String];
    //AdsResultCode cRet = (AdsResultCode) ret;
    const char* chZoneID = [zoneID UTF8String];
    AdColonyAdsIntenelListener* listener = (AdColonyAdsIntenelListener*) adsPlugin->getAdsListener();
    if (listener)
    {
      listener->onAdsResult(ret, chZoneID, chMsg);
    }
  } else {
    PluginUtilsIOS::outputLog("Can't find the C++ object of the ads plugin");
  }
  
}

+ (void) onPlayerGetPoints:(id) obj withZoneID:(NSString *)zoneID withSuccess:(BOOL)success withName:(NSString *)name withPoints: (int) points{
  PluginProtocol* plugin = PluginUtilsIOS::getPluginPtr(obj);
  ProtocolAds* adsPlugin = dynamic_cast<ProtocolAds*>(plugin);
  if (adsPlugin) {
    AdColonyAdsIntenelListener* listener = (AdColonyAdsIntenelListener*) adsPlugin->getAdsListener();
    if (listener)
    {
      const char* chZoneID = [zoneID UTF8String];
      const char* chName = [name UTF8String];

      listener->onPlayerGetPoints(adsPlugin, chZoneID, success, chName, points);
    }
  } else {
    PluginUtilsIOS::outputLog("Can't find the C++ object of the ads plugin");
  }
}

@end
