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

#ifndef PluginAdColony_AdColonyAgent_h
#define PluginAdColony_AdColonyAgent_h

#include "ProtocolAds.h"
#include "AdColonyInternal.h"

class AdColonyAdsListener
{
public:
  /**
   @brief Provides your app with real-time updates about ad availability changes
   @param success whether or not ad is ready to play.
   @param zoneID The zone from which the ad should play.
   @param msg message.
   */
  virtual void onAdColonyAdAvailabilityChange(bool success, const char* zoneID, const char* msg) {};
  
  /**
   @brief Notifies your app after an ad is displayed when a virtual currency transaction has completed
   @param success Whether the transaction succeeded or failed.
   @param name The currency name.
   @param points The point number player has got.
   */
  virtual void onAdColonyV4VCReward(bool success, const char* name,int points) {};

  /**
   @brief Notifies your app that an ad will actually play in response to the app's request to play an ad
   */
  virtual void onAdColonyAdStarted() {};
  
  /**
   @brief Notifies your app that an ad completed playing and control has been returned to the app
   @param adShown Whether an ad was actually shown.
   */
  virtual void onAdColonyAdAttemptFinished(bool adShown) {};
  
};

class AdColonyAgent
{
public:
  
  /**
   @brief Initiate plugin
   */
  AdColonyAgent();

  /**
   @brief Get the plugin instance.
   */
  static AdColonyAgent* getInstance();

  /**
   @brief Set debug mode
   @param debug Whether is debug mode.
   */
  void setDebugMode(bool debug);
  
  /**
   @brief Assigns your own custom identifier to the current app user.
   @param customID An arbitrary, application-specific identifier string for the current user. Must be less than 128 characters.
   */
  void setCustomID(const char* customID);
  
  /**
   @brief Returns the device's current custom identifier.
   @return The custom identifier string most recently set using `setCustomID`.
   */
  std::string getCustomID();
  
  /**
   @brief Configures AdColony specifically for your app; required for usage of the rest of the API.
   @param options A String containing your app version, and the origin store (example: “version:1.1,store:google”). Please note that if you are integrating into an Amazon app you will need to replace 'google' with 'amazon' in the client_options String.
   @param appID The AdColony app ID for your app. This can be created and retrieved at the [Control Panel](http://clients.adcolony.com).
   @param zoneIDs An list of at least one AdColony zone ID string. AdColony zone IDs can be created and retrieved at the [Control Panel](http://clients.adcolony.com). If `nil`, app will be unable to play ads and AdColony will only provide limited reporting and install tracking functionality.
   @param listener The listener to receive V4VC and ad availability events. Can be `NULL` for apps that do not need these events.
   */
  void configure(const char* options, const char* appID, const std::vector<std::string>& zoneIDs, AdColonyAdsListener *listener);
  
  /**
   @brief set AdColonyAdsListener.
   @param listener The listener to receive V4VC and ad availability events. Can be `NULL` for apps that do not need these events.
   */
  void setAdsListener(AdColonyAdsListener *listener);

  /**
   @brief Get AdColonyAdsListener.
   @return AdColonyAdsListener.
   */
  AdColonyAdsListener * getAdsListener();
  /**
   @brief Plays an AdColony ad.
   @param zoneID The zone from which the ad should play.
   */
  void showVideoAd(const char* zoneID);
  
  /**
   @brief Plays an AdColony V4VC ad if one is available.
   @param zoneID The zone from which the ad should play.
   @param prePopup Whether AdColony should display an instructional popup before the ad.
   @param postPopup Whether AdColony should display an instructional popup after the ad.
   */
  void showV4VC(const char* zoneID, bool prePopup, bool postPopup);
  
  /**
   @brief Returns status of the AdColony zone passed in.
   @param zoneID The zone from which the ad should play.
   @return  Returns one of the following strings:
   "invalid" - You've entered an incorrect zone id, or AdColony has not been configured with that zone ID.
   "unknown" - Indicates that AdColony has not yet received the zone's configuration from the server.
   "off" - The zone is disabled. The zone has been turned off on the control panel.
   "loading" - Indicates that the zone is preparing ads for display.
   "active" - The zone is enabled and has ads ready to be played.
   */
  std::string statusForZone(const char* zoneID);
  
  /**
   @brief Returns whether or not a video is available in the specified zone.
   @param zoneID The zone from which the ad should play.
   */
  bool isReady(const char* zoneID);
  
private:
  AdColonyAdsListener* _listener;
};

#endif
