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
package org.cocos2dx.plugin;

import java.util.Hashtable;

import android.app.Activity;
import android.content.Context;
import android.util.Log;
import org.cocos2dx.plugin.AdsAdColonyWrapper;

import com.jirbo.adcolony.*;


public class AdsAdColony implements InterfaceAds, AdColonyAdListener, AdColonyV4VCListener, AdColonyAdAvailabilityListener{

	private static Activity mContext = null;
    protected static String TAG = "AdsAdColony";

    private AdsAdColony mAdapter = null;
    
    private String mAdColonyCustomID;
    private String mAdColonyDeviceID;
    private String mAdColonyAppID;
    private String mAdColonyZoneIDs;
    private String mAdColonyClientOptions;

    protected static void LogE(String msg, Exception e) {
        Log.e(TAG, msg, e);
        e.printStackTrace();
    }

    private static boolean isDebug = false;
    protected static void LogD(String msg) {
        if (isDebug) {
            Log.d(TAG, msg);
        }
    }

    public AdsAdColony(Context context) {
        mContext = (Activity)context;
        mAdapter = this;
    }

    @Override
    public void setDebugMode(boolean isDebugMode) {
    	isDebug = isDebugMode;
    }

    @Override
    public String getSDKVersion() {
        return "2.2.1";
    }

    @Override
    public String getPluginVersion() {
        return "0.9.0";
    }

    @Override
    public void configDeveloperInfo(Hashtable<String, String> devInfo) {
        try {
            mAdColonyAppID = devInfo.get("AdColonyAppID");
            mAdColonyZoneIDs = devInfo.get("AdColonyZoneIDs");
            mAdColonyClientOptions = devInfo.get("AdColonyClientOptions");
            LogD("init AppInfoAdColony : " + mAdColonyAppID);
            LogD("init zoneIDs: " + mAdColonyZoneIDs);
            LogD("init clientOption: " + mAdColonyClientOptions);
            final String[] zoneIDs = mAdColonyZoneIDs.split(",", 0);
            PluginWrapper.runOnMainThread(new Runnable() {
                @Override
                public void run() {
                	AdColony.configure(mContext,  mAdColonyClientOptions, mAdColonyAppID, zoneIDs);
                    AdColony.addAdAvailabilityListener(AdsAdColony.this);
                    AdColony.addV4VCListener(AdsAdColony.this);
                }
            });
        } catch (Exception e) {
            LogE("Something went wrong when configuring adcolony:", e);
        }
    }

    @Override
    public void showAds(Hashtable<String, String> adsInfo, int pos) {
    	try
	    {
    		final String zoneID = adsInfo.get("AdColonyZoneID");
    		final String adType = adsInfo.get("AdColonyAdType");
    		LogD("showAds : " + zoneID + " " + adType);
    		if(adType != null && adType.equals("v4vc")){
    			final String needConfirmDialog = adsInfo.get("withConfirmationDialog");
    			final String needResultDialog = adsInfo.get("withResultsDialog");
    			
    			PluginWrapper.runOnMainThread(new Runnable() {
                    @Override
                    public void run() {
                    	AdColonyV4VCAd ad = new AdColonyV4VCAd(zoneID).withListener(mAdapter);
    			        
                    	LogD("withConfirmationDialog:" + needConfirmDialog + " withResultsDialog:" + needResultDialog);
    			        if(needConfirmDialog != null && needConfirmDialog.equals("true")){
    			            ad.withConfirmationDialog();
    			        }
    			        if(needResultDialog != null && needResultDialog.equals("true")){
    			            ad.withResultsDialog();
    			        }
                    	ad.show();
                    }
                });
    		}else{
    			PluginWrapper.runOnMainThread(new Runnable() {
                    @Override
                    public void run() {
    			        AdColonyVideoAd ad = new AdColonyVideoAd(zoneID).withListener(mAdapter);
                        ad.show();
                    }
                });
    		}
	    } catch (Exception e) {
	        LogE("Something went wrong when showing the ad:", e);
	    }
    }

    @Override
    public void hideAds(Hashtable<String, String> adsInfo) {
    	LogD("AdColony not support hideAds!");
    }

    @Override
    public void queryPoints() {
        // TODO Auto-generated method stub
    	LogD("AdColony not support queryPoints!");
    }

    @Override
    public void spendPoints(int points) {
        // TODO Auto-generated method stub
    	LogD("AdColony not support spendPoints!");
    }
    
    
    
    // Ad Started Callback - called only when an ad successfully starts playing
    public void onAdColonyAdStarted(AdColonyAd ad)
    {
    	LogD("onAdColonyAdStarted");
  	    AdsAdColonyWrapper.onAdsResult(mAdapter, AdsAdColonyWrapper.RESULT_CODE_VideoStarted, "", "Ad starts playing.");
    }
    
    //Ad Attempt Finished Callback - called at the end of any ad attempt - successful or not.
    public void onAdColonyAdAttemptFinished( AdColonyAd ad )
    {
  	// You can ping the AdColonyAd object here for more information:
  	// ad.shown() - returns true if the ad was successfully shown.
  	// ad.notShown() - returns true if the ad was not shown at all (i.e. if onAdColonyAdStarted was never triggered)
  	// ad.skipped() - returns true if the ad was skipped due to an interval play setting
  	// ad.canceled() - returns true if the ad was cancelled (either programmatically or by the user)
  	// ad.noFill() - returns true if the ad was not shown due to no ad fill.
  	  
    	 LogD("onAdColonyAdAttemptFinished");
    	 if(ad.shown()){
             AdsAdColonyWrapper.onAdsResult(mAdapter, AdsAdColonyWrapper.RESULT_CODE_VideoFinished, "", "Ad has finished playing.");
    	 }else{
    		 AdsAdColonyWrapper.onAdsResult(mAdapter, AdsAdColonyWrapper.RESULT_CODE_VideoFailed, "", "Ad was not successfully shown.");
    	 }
    }
    
    
    //Ad Availability Change Callback
    public void onAdColonyAdAvailabilityChange(boolean available, String zoneID) 
    {
    	LogD("onAdColonyAdAvailabilityChange zoneID:"+zoneID + " status:" + available);
  	    if(available)
  	    {
  	        AdsAdColonyWrapper.onAdsResult(mAdapter, AdsAdColonyWrapper.RESULT_CODE_AdsAvailable, zoneID, "Ads are now available!");
  	    }else{
  	    	AdsAdColonyWrapper.onAdsResult(mAdapter, AdsAdColonyWrapper.RESULT_CODE_AdsNotAvailable, zoneID, "Ads are now not available!");
  	    }
    }
    
    // Reward Callback
    public void onAdColonyV4VCReward(AdColonyV4VCReward reward)
    {
  	    LogD("onAdColonyV4VCReward name:" + reward.name() + " amount:" + reward.amount() + " success:" + reward.success());
  	    if (reward.success()){
  	    	AdsAdColonyWrapper.onPlayerGetPoints(mAdapter, "", true, reward.name(), reward.amount());
  	    }else{
  	    	AdsAdColonyWrapper.onPlayerGetPoints(mAdapter, "", false, reward.name(), reward.amount());
  	    }
    }
    
    // use callBoolFuncWithParam to call
    public boolean isReady(String zoneID){
        if(AdColony.statusForZone(zoneID).equals("active")){
        	return true;
        }else{
        	return false;
        }
    }
    
    public void setDeviceID(String deviceID){
    	AdColony.setDeviceID(deviceID);
    }
    
    public void setCustomID(String customID){
    	AdColony.setCustomID(customID);
    }
    
    public String getDeviceID(){
    	return AdColony.getDeviceID();
    }
    
    public String getCustomID(){
    	return AdColony.getCustomID();
    }
    
    public String statusForZone(String zoneID){
    	return AdColony.statusForZone(zoneID);
    }
    
    public int getRemainingV4VCForZone(String zoneID){
    	return AdColony.getRemainingV4VCForZone(zoneID);
    }
    
    public int getVirtualCurrencyRewardsAvailableTodayForZone(String zoneID){
    	return getRemainingV4VCForZone(zoneID);
    }
    
    public boolean isVirtualCurrencyRewardAvailableForZone(String zoneID){
    	return getRemainingV4VCForZone(zoneID)>0?true:false;
    }
    
}
