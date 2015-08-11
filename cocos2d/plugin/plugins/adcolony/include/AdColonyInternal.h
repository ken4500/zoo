/****************************************************************************
 Copyright (c) 2015 Glossom, Inc. All rights reserved.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef PluginAdColony_AdColonyInternal_h
#define PluginAdColony_AdColonyInternal_h


#include "ProtocolAds.h"

typedef enum
{
  kAdColonyAdsAvailable = 0,           // Ads are now available!
  kAdColonyAdsNotAvailable,            // Ads are now not available!
  kAdColonyVideoStarted,               // Ad starts playing.
  kAdColonyVideoFinished,              // Ad has finished playing.
  kAdColonyVideoFailed,                // Ad was not successfully shown.
  kAdColonyNetworkError,               // Network error
  kAdColonyUnknownError,               // Unknown error
} AdColonyAdsResultCode;
class AdColonyAdsIntenelListener : public cocos2d::plugin::AdsListener
{
public:
  /**
   @brief The advertisement request result
   @param type AdColonyAdsResultCode.
   @param zoneID The zone from which the ad should play.
   @param msg message.
   */
  virtual void onAdsResult(AdColonyAdsResultCode code, const char* zoneID, const char* msg);
  
  /**
   @brief Player get points from advertisement(For example: Tapjoy)
   @param pAdsPlugin  The plugin which the player get points. Used to spend the points.
   @param zoneID The zone from which the ad should play.
   @param success Whether the transaction succeeded or failed.
   @param name The currency name.
   @param points The point number player has got.
   */
  virtual void onPlayerGetPoints(cocos2d::plugin::ProtocolAds* pAdsPlugin, const char* zoneID, bool success, const char* name,int points);
  
  /**
   @brief The advertisement request result
   @warning: this is inheretent from AdsListener, Do not use this
   */
  void onAdsResult(cocos2d::plugin::AdsResultCode code, const char* msg) {};
  
  /**
   @brief Player get points from advertisement(For example: Tapjoy)
   @warning: this is inheretent from AdsListener, Do not use this
   */
  void onPlayerGetPoints(cocos2d::plugin::ProtocolAds* pAdsPlugin, int points) {};
};

#endif
