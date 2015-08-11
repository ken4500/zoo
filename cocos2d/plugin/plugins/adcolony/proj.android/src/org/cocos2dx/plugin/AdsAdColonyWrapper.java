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

import android.view.Gravity;
import android.view.View;
import android.view.WindowManager;

public class AdsAdColonyWrapper{
	
	public static final int RESULT_CODE_AdsAvailable = 0;         // Ads are now available!
	public static final int RESULT_CODE_AdsNotAvailable = 1;      // Ads are now not available!
    public static final int RESULT_CODE_VideoStarted = 2;         // Ad starts playing.
    public static final int RESULT_CODE_VideoFinished = 3;        // Ad has finished playing.
    public static final int RESULT_CODE_VideoFailed = 4;          // Ad was not successfully shown.
    public static final int RESULT_CODE_NetworkError = 5;         // Network error
    public static final int RESULT_CODE_UnknownError = 6;         // Unknown error           

	public static void onAdsResult(InterfaceAds adapter, int code, String zoneID, String msg) {
		final int curCode = code;
		final String curZoneID = zoneID;
		final String curMsg = msg;
		final InterfaceAds curObj = adapter;
		PluginWrapper.runOnGLThread(new Runnable(){
			@Override
			public void run() {
				String name = curObj.getClass().getName();
				name = name.replace('.', '/');
				AdsAdColonyWrapper.nativeOnAdsResult(name, curCode, curZoneID, curMsg);
			}
		});
	}
	private native static void nativeOnAdsResult(String className, int code, String zoneID, String msg);
	
	public static void onPlayerGetPoints(InterfaceAds adapter, String zoneID, boolean success, String name, int points) {
		final String curZoneID = zoneID;
		final boolean curSuccess = success;
		final String curName = name;
		final int curPoints = points;
		final InterfaceAds curAdapter = adapter;
		PluginWrapper.runOnGLThread(new Runnable(){
			@Override
			public void run() {
				String name = curAdapter.getClass().getName();
				name = name.replace('.', '/');
				AdsAdColonyWrapper.nativeOnPlayerGetPoints(name, curZoneID, curSuccess, curName, curPoints);
			}
		});
	}
	private native static void nativeOnPlayerGetPoints(String className, String zoneID, boolean success, String name, int points);
}
