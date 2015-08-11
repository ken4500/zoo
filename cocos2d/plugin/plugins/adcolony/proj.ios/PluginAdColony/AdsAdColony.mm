//
//  PluginAdColony.m
//  PluginAdColony
//
//  Created by Junhua Li on 2015/02/24.
//  Copyright (c) 2015年 Glossom, Inc. All rights reserved.
//

#import "AdsAdColony.h"
#import "AdColonyAdsWrapper.h"

#define OUTPUT_LOG(...)     if (self.debug) NSLog(__VA_ARGS__);

@implementation AdsAdColony

@synthesize debug = __debug;

- (void) configDeveloperInfo: (NSMutableDictionary*) devInfo{
  OUTPUT_LOG(@"configDeveloperInfo");
  
  NSString * appID = [devInfo objectForKey:@"AdColonyAppID"];
  NSString * zoneIDsStr = [devInfo objectForKey:@"AdColonyZoneIDs"];
  NSArray *zoneIDs = [zoneIDsStr componentsSeparatedByString:@","];

  [AdColony configureWithAppID:appID zoneIDs:zoneIDs delegate:self logging:YES];

  
  //it seems AdColony conflicts with cocos2d-x when using opengl, we use a new window for AdColony.
  if(_videoWindow == nil){
    _videoWindow = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    [_videoWindow setBackgroundColor:[UIColor clearColor]];
    _videoWindow.rootViewController = [[UIViewController alloc] init];
    [_videoWindow setWindowLevel:UIWindowLevelStatusBar];
    _keyWindow = [[[UIApplication sharedApplication] windows] objectAtIndex:0];
    [_videoWindow makeKeyAndVisible];
    [_keyWindow makeKeyAndVisible];
    [_videoWindow setHidden:TRUE];
  }
  
}

- (void) showAds: (NSMutableDictionary*) info position:(int) pos{
  NSString * zoneID = [info objectForKey:@"AdColonyZoneID"];
  BOOL isV4VC = (info[@"AdColonyAdType"] != nil && [info[@"AdColonyAdType"] caseInsensitiveCompare:@"v4vc"] == NSOrderedSame);
  if (isV4VC) {
    BOOL withPrePopup = (info[@"withConfirmationDialog"] != nil && [info[@"withConfirmationDialog"] caseInsensitiveCompare:@"true"] == NSOrderedSame);
    BOOL withPostPopu = (info[@"withResultsDialog"]!= nil && [info[@"withResultsDialog"] caseInsensitiveCompare:@"true"] == NSOrderedSame);
    [AdColony playVideoAdForZone:zoneID withDelegate:self withV4VCPrePopup:withPrePopup andV4VCPostPopup:withPostPopu];
  }else{
    [AdColony playVideoAdForZone:zoneID withDelegate:self];
  }
}

- (void) hideAds: (NSMutableDictionary*) info{
  
}
- (void) queryPoints{
  
}
- (void) spendPoints: (int) points{
  
}
- (void) setDebugMode: (BOOL) debug{
  self.debug = true;
}
- (NSString*) getSDKVersion{
  return @"2.5.0";
}
- (NSString*) getPluginVersion{
  return @"0.9.0";
}


-(BOOL)isReady:(NSString *)zoneID
{
  return [AdColony zoneStatusForZone:zoneID] == ADCOLONY_ZONE_STATUS_ACTIVE;
}

- (NSString *) statusForZone:( NSString * )zoneID
{
  return [self zoneStatusToString:[AdColony zoneStatusForZone:zoneID]];
}

- (NSString*)zoneStatusToString:(ADCOLONY_ZONE_STATUS)type {
  NSString *result = nil;
  switch(type) {
    case ADCOLONY_ZONE_STATUS_NO_ZONE:
      result = @"invalid";//to keep same with android: https://github.com/AdColony/AdColony-Android-SDK/wiki/API-Details#statusforzone-string-zone_id-
      break;
    case ADCOLONY_ZONE_STATUS_OFF:
      result = @"off";
      break;
    case ADCOLONY_ZONE_STATUS_LOADING:
      result = @"loading";
      break;
    case ADCOLONY_ZONE_STATUS_ACTIVE:
      result = @"active";
      break;
    default:
      result = @"unknown";
  }
  
  return result;
}

- (void) setCustomID:( NSString * )customID
{
  [AdColony setCustomID:customID];
}

/**
 * Returns the device's current custom identifier.
 * @return The custom identifier string most recently set using `+ setCustomID:`.
 * @see setCustomID:
 */
- ( NSString * ) getCustomID
{
  return [AdColony getCustomID];
}

/** @name V4VC Availability and Currency Info */

/**
 * Returns if it is possible for the user to receive a virtual currency reward for playing an ad in the zone.
 * This method takes into account whether V4VC has been configured properly for the zone on the
 * [AdColony Control Panel](http://clients.adcolony.com), whether the user's daily reward cap has been reached,
 * and whether there are ads available.
 * @param zoneID The zone in question.
 * @return A boolean indicating whether a reward is currently available for the user.
 */
- ( BOOL ) isVirtualCurrencyRewardAvailableForZone:( NSString * )zoneID
{
  return [AdColony isVirtualCurrencyRewardAvailableForZone:zoneID];
}

/**
 * Returns the number of possible virtual currency rewards currently available for the user.
 * This method takes into account daily caps, available ads, and other variables.
 * @param zoneID The zone in question.
 * @return An integer number of remaining virtual currency rewards that can possibly occur in the near future.
 */
- ( int ) getVirtualCurrencyRewardsAvailableTodayForZone:( NSString * )zoneID
{
  return [AdColony getVirtualCurrencyRewardsAvailableTodayForZone:zoneID];
}

/**
 * Returns the name of the virtual currency rewarded by the zone.
 * You must first configure AdColony using `+ configureWithAppID:zoneIDs:delegate:logging:`
 * and ensure the zone's status is not `ADCOLONY_ZONE_STATUS_UNKNOWN` before this function will return an accurate result.
 * @param zoneID The zone in question
 * @return A string name of the virtual currency rewarded by the zone, as configured on the [AdColony Control Panel](http://clients.adcolony.com).
 */
- ( NSString * ) getVirtualCurrencyNameForZone:( NSString * )zoneID{
  return [AdColony getVirtualCurrencyNameForZone:zoneID];
}

/**
 * Returns the amount of virtual currency rewarded by the zone.
 * You must first configure AdColony using `+ configureWithAppID:zoneIDs:delegate:logging:`
 * and ensure the zone's status is not `ADCOLONY_ZONE_STATUS_UNKNOWN` before this function will return an accurate result.
 * @param zoneID The zone in question
 * @return An integer indicating the amount of virtual currency rewarded by the zone, as configured on the [AdColony Control Panel](http://clients.adcolony.com).
 */
- ( int ) getVirtualCurrencyRewardAmountForZone:( NSString * )zoneID
{
  return [AdColony getVirtualCurrencyRewardAmountForZone:zoneID];
}


/** @name V4VC Multiple Videos per Reward Info */

/**
 * Returns the number of ads that the user must play to earn the designated reward.
 * You must first configure AdColony using `+ configureWithAppID:zoneIDs:delegate:logging:`
 * and ensure the zone's status is not `ADCOLONY_ZONE_STATUS_UNKNOWN` before this function will return an accurate result.
 * @param currencyName The name of the currency to query
 * @return An integer number of ads that the user must play per currency reward, as configured on the [AdColony Control Panel](http://clients.adcolony.com).
 */
- ( int ) getVideosPerReward:( NSString * )currencyName
{
  return [AdColony getVideosPerReward:currencyName];
}

/**
 * Returns the number of ads that the user has seen towards their next reward.
 * You must first configure AdColony using `+ configureWithAppID:zoneIDs:delegate:logging:`
 * and ensure the zone's status is not `ADCOLONY_ZONE_STATUS_UNKNOWN` before this function will return an accurate result.
 * @param currencyName The name of the currency to query.
 * @return An integer number of ads that the user has seen towards their next reward.
 */
- ( int ) getVideoCreditBalance:( NSString * )currencyName
{
  return [AdColony getVideoCreditBalance:currencyName];
}


/** @name Options and Other Functionality */

/**
 * Cancels any full-screen ad that is currently playing and returns control to the app.
 * No earnings or V4VC rewards will occur if an ad is canceled programmatically by the app.
 * This should only be used by apps that must immediately respond to non-standard incoming events,
 * like a VoIP phone call. This should not be used for standard app interruptions such as
 * multitasking or regular phone calls.
 */
- ( void ) cancelAd
{
  [AdColony cancelAd];
}

/**
 * Whether a full-screen AdColony ad is currently being played.
 * @return A boolean indicating if AdColony is currently playing an ad.
 */
- ( BOOL ) videoAdCurrentlyRunning
{
  return [AdColony videoAdCurrentlyRunning];
}

/**
 * This method permanently turns off all AdColony ads for this app on the current device.
 * After this method is called, no ads will be played unless the app is deleted and reinstalled.
 * This method could be used in the implementation of an In-App Purchase to disable ads;
 * make sure to allow In-App Purchases to be restored by the user in the case of deleting and reinstalling the app.
 */
- ( void ) turnAllAdsOff
{
  [AdColony turnAllAdsOff];
}


/** @name Video Ad Readiness */

/**
 * Provides your app with real-time updates about ad availability changes.
 * This method is called when a zone's ad availability state changes (when ads become available, or become unavailable).
 * Listening to these callbacks allows your app to update its user interface immediately.
 * For example, when ads become available in a zone you could immediately show an ad for that zone.
 * @param available Whether ads became available or unavailable.
 * @param zoneID The affected zone.
 */
- ( void ) onAdColonyAdAvailabilityChange:( BOOL )available inZone:( NSString * )zoneID{
  OUTPUT_LOG(@"onAdColonyAdAvailabilityChange:%d inZone:%@", available, zoneID);
  
  NSString *msg = [NSString stringWithFormat:@"onAdColonyAdAvailabilityChange:%d inZone:%@", available, zoneID];
  AdColonyAdsResultCode ret = available ? kAdColonyAdsAvailable : kAdColonyAdsNotAvailable;
  [AdColonyAdsWrapper onAdsResult:self withZoneID:zoneID withRet:ret withMsg:msg];
}


/** @name Virtual Currency Rewards (V4VC) */

/**
 * Notifies your app when a virtual currency transaction has completed as a result of displaying an ad.
 * In your implementation, check for success and implement any app-specific code that should be run when
 * AdColony has successfully rewarded. Client-side V4VC implementations should increment the user's currency
 * balance in this method. Server-side V4VC implementations should contact the game server to determine
 * the current total balance for the virtual currency.
 * @param success Whether the transaction succeeded or failed.
 * @param currencyName The name of currency to reward.
 * @param amount The amount of currency to reward.
 * @param zoneID The affected zone.
 */
- ( void ) onAdColonyV4VCReward:( BOOL )success currencyName:( NSString * )currencyName currencyAmount:( int )amount inZone:( NSString * )zoneID{
  OUTPUT_LOG(@"onAdColonyV4VCReward:%d currencyName:%@ currencyAmount:%d inZone: %@", success, currencyName, amount, zoneID);

  [AdColonyAdsWrapper onPlayerGetPoints:self withZoneID:zoneID withSuccess:success withName:currencyName withPoints:amount];
}

// AdColonyAdDelegate
/**
 * Notifies your app that an ad will actually play in response to the app's request to play an ad.
 * This method is called when AdColony has taken control of the device screen and is about to begin
 * showing an ad. Apps should implement app-specific code such as pausing a game and turning off app music.
 * @param zoneID The affected zone.
 */
- ( void ) onAdColonyAdStartedInZone:( NSString * )zoneID{
  OUTPUT_LOG(@"onAdColonyAdStartedInZone: %@", zoneID);
    // Add the view controller's view to the window and display.
    _keyWindow = [[[UIApplication sharedApplication] windows] objectAtIndex:0];
    [_videoWindow makeKeyAndVisible];
    _keyWindowViewController = _keyWindow.rootViewController;
    [_keyWindow setRootViewController:nil];
    
  [AdColonyAdsWrapper onAdsResult:self withZoneID:zoneID withRet:kAdColonyVideoStarted withMsg:@"AdColony ad will be presented"];

}

/**
 * Notifies your app that an ad completed playing (or never played) and control has been returned to the app.
 * This method is called when AdColony has finished trying to show an ad, either successfully or unsuccessfully.
 * If an ad was shown, apps should implement app-specific code such as unpausing a game and restarting app music.
 * @param shown Whether an ad was actually shown.
 * @param zoneID The affected zone.
 */
- ( void ) onAdColonyAdAttemptFinished:(BOOL)shown inZone:( NSString * )zoneID{
  OUTPUT_LOG(@"onAdColonyAdAttemptFinished:%d inZone:%@", shown, zoneID);
  [AdColonyAdsWrapper onAdsResult:self withZoneID:zoneID withRet:(shown ? kAdColonyVideoFinished : kAdColonyVideoFailed) withMsg:@"AdColony ad finished"];

    if(_videoWindow != nil && !_videoWindow.hidden){
        _keyWindow.rootViewController = _keyWindowViewController;
        [_keyWindow makeKeyAndVisible];
        [_videoWindow setHidden:YES];
    }
}

@end
