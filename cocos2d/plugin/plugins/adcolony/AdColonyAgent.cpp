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

#include <stdio.h>

#include "PluginProtocol.h"
#include "PluginManager.h"

#include "AdColonyAgent.h"

using namespace cocos2d::plugin;

static cocos2d::plugin::ProtocolAds *s_sharedAdColonyAdsPlugin = nullptr;
static AdColonyAgent *s_sharedInstance = nullptr;



AdColonyAgent* AdColonyAgent::getInstance()
{
  if(nullptr == s_sharedInstance)
  {
    s_sharedInstance = new (std::nothrow)AdColonyAgent();
    s_sharedAdColonyAdsPlugin->setAdsListener(new AdColonyAdsIntenelListener());

  }
  return s_sharedInstance;
}

AdColonyAgent::AdColonyAgent()
{
  if (nullptr == s_sharedAdColonyAdsPlugin) {
    s_sharedAdColonyAdsPlugin = dynamic_cast<ProtocolAds*>(PluginManager::getInstance()->loadPlugin("AdsAdColony"));
  }
}

void AdColonyAgent::setDebugMode(bool debug)
{
  s_sharedAdColonyAdsPlugin->setDebugMode(debug);
}

void AdColonyAgent::setCustomID(const char* customID)
{
  PluginParam pCustomID(customID);
  s_sharedAdColonyAdsPlugin->callFuncWithParam("setCustomID", &pCustomID, NULL);
}

std::string AdColonyAgent::getCustomID()
{
  return s_sharedAdColonyAdsPlugin->callStringFuncWithParam("getCustomID", NULL);
}

void AdColonyAgent::configure(const char* options, const char* appID, const std::vector<std::string>& zoneIDs, AdColonyAdsListener *listener)
{
  TAdsDeveloperInfo devInfo;
  devInfo["AdColonyClientOptions"] = options;
  devInfo["AdColonyAppID"] = appID;
  std::string zoneIDsStr = "";
  for (int i=0; i < (int)(zoneIDs.size()); i++) {
    if (i != 0) {
      zoneIDsStr += ",";
    }
    std::string zoneID = zoneIDs[i];
    zoneIDsStr += zoneID;
  }
  devInfo["AdColonyZoneIDs"] = zoneIDsStr;
  s_sharedAdColonyAdsPlugin->configDeveloperInfo(devInfo);
  this->setAdsListener(listener);

}

void AdColonyAgent::setAdsListener(AdColonyAdsListener *listener)
{
  _listener = listener;
}

AdColonyAdsListener * AdColonyAgent::getAdsListener()
{
  return _listener;
}
void AdColonyAgent::showVideoAd(const char* zoneID)
{
  cocos2d::plugin::TAdsInfo adInfo;
  adInfo["AdColonyAdType"] = "interstitial";
  adInfo["AdColonyZoneID"] = zoneID;
  s_sharedAdColonyAdsPlugin->showAds(adInfo, ProtocolAds::kPosCenter);
}

void AdColonyAgent::showV4VC(const char* zoneID, bool prePopup, bool postPopup)
{
  cocos2d::plugin::TAdsInfo adInfo;
  adInfo["AdColonyAdType"] = "v4vc";
  adInfo["withConfirmationDialog"] = prePopup ? "true" : "false";
  adInfo["withResultsDialog"] = postPopup ? "true" : "false";
  adInfo["AdColonyZoneID"] = zoneID;
  s_sharedAdColonyAdsPlugin->showAds(adInfo, ProtocolAds::kPosCenter);
}

std::string AdColonyAgent::statusForZone(const char* zoneID)
{
  PluginParam pZoneID(zoneID);
  return s_sharedAdColonyAdsPlugin->callStringFuncWithParam("statusForZone", &pZoneID, NULL);
}


bool AdColonyAgent::isReady(const char* zoneID)
{
  return s_sharedAdColonyAdsPlugin->callBoolFuncWithParam("isReady", NULL);
}

void AdColonyAdsIntenelListener::onAdsResult(AdColonyAdsResultCode code, const char* zoneID, const char* msg){
  AdColonyAdsListener *listener = AdColonyAgent::getInstance()->getAdsListener();
  if (listener) {
    switch (code) {
      case kAdColonyAdsAvailable:
        listener->onAdColonyAdAvailabilityChange(true, zoneID, msg);
        break;
      case kAdColonyAdsNotAvailable:
        listener->onAdColonyAdAvailabilityChange(false, zoneID, msg);
        break;
      case kAdColonyVideoStarted:
        listener->onAdColonyAdStarted();
        break;
      case kAdColonyVideoFinished:
        listener->onAdColonyAdAttemptFinished(true);
        break;
      case kAdColonyVideoFailed:
        listener->onAdColonyAdAttemptFinished(false);
        break;
      default:
        break;
    }
  }

}

void AdColonyAdsIntenelListener::onPlayerGetPoints(cocos2d::plugin::ProtocolAds* pAdsPlugin, const char* zoneID, bool success, const char* name,int points)
{
  AdColonyAdsListener *listener = AdColonyAgent::getInstance()->getAdsListener();
  if (listener) {
    listener->onAdColonyV4VCReward(success, name, points);
  }
}
