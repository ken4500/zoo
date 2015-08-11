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
#include "AdColonyAgent.h"
#include "AdColonyInternal.h"
#include "PluginJniHelper.h"
#include <android/log.h>
#include "PluginUtils.h"
#include "PluginJavaData.h"

namespace cocos2d { namespace plugin {

extern "C" {
	JNIEXPORT void JNICALL Java_org_cocos2dx_plugin_AdsAdColonyWrapper_nativeOnAdsResult(JNIEnv*  env, jobject thiz, jstring className, jint ret, jstring zoneID, jstring msg) {

		std::string strMsg = PluginJniHelper::jstring2string(msg);
		std::string strClassName = PluginJniHelper::jstring2string(className);
        std::string strZoneIds = PluginJniHelper::jstring2string(zoneID);
        
		PluginProtocol* pPlugin = PluginUtils::getPluginPtr(strClassName);
		PluginUtils::outputLog("ProtocolAds", "nativeOnAdsResult(), Get plugin ptr : %p", pPlugin);
		if (pPlugin != NULL)
		{
			PluginUtils::outputLog("ProtocolAds", "nativeOnAdsResult(), Get plugin name : %s", pPlugin->getPluginName());
			ProtocolAds* pAds = dynamic_cast<ProtocolAds*>(pPlugin);
			if (pAds != NULL)
			{
			    AdColonyAdsIntenelListener* listener = (AdColonyAdsIntenelListener*)pAds->getAdsListener();
			    if (listener)
				{
			        listener->onAdsResult((AdColonyAdsResultCode) ret, strZoneIds.c_str(), strMsg.c_str());
				}
			}
		}
		
	}

	JNIEXPORT void JNICALL Java_org_cocos2dx_plugin_AdsAdColonyWrapper_nativeOnPlayerGetPoints(JNIEnv*  env, jobject thiz, jstring className, jstring zoneID, jboolean success, jstring name, jint points) {

		std::string strClassName = PluginJniHelper::jstring2string(className);
		std::string strZoneIds = PluginJniHelper::jstring2string(zoneID);
		std::string strName = PluginJniHelper::jstring2string(name);
		PluginProtocol* pPlugin = PluginUtils::getPluginPtr(strClassName);
		PluginUtils::outputLog("ProtocolAds", "nativeOnPlayerGetPoints(), Get plugin ptr : %p", pPlugin);
		if (pPlugin != NULL)
		{
			PluginUtils::outputLog("ProtocolAds", "nativeOnPlayerGetPoints(), Get plugin name : %s", pPlugin->getPluginName());
			ProtocolAds* pAds = dynamic_cast<ProtocolAds*>(pPlugin);
			if (pAds != NULL)
			{
				AdColonyAdsIntenelListener* listener = (AdColonyAdsIntenelListener*)pAds->getAdsListener();
                if (listener)
                {
                    listener->onPlayerGetPoints(pAds, strZoneIds.c_str(), success, strName.c_str(), points);
                }
			}
		}

	}

}

}} // namespace cocos2d { namespace plugin {
