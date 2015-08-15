//
//  NativeLauncher.cpp
//  Noen
//
//  Created by Taisuke Fujita on 2015/02/05.
//
//

#include "NativeLauncher.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>

#define CLASS_NAME "org/cocos2dx/cpp/AppActivity"

using namespace cocos2d;

namespace cocos2dext
{
	void NativeLauncher::openTweetDialog(std::string $tweet, std::string $filePath)
	{
		JniMethodInfo methodInfo;
		if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "tweet", "(Ljava/lang/String;Ljava/lang/String;)V")) {
            return;
		}
        jstring tweetArg = methodInfo.env->NewStringUTF($tweet.c_str());
        jstring filePathArg = methodInfo.env->NewStringUTF($filePath.c_str());
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, tweetArg, filePathArg);
        methodInfo.env->DeleteLocalRef(tweetArg);
        methodInfo.env->DeleteLocalRef(filePathArg);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

    void NativeLauncher::showLocalNotification(std::string message, int interval, int tag)
    {
        JniMethodInfo methodInfo;
        
        if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "showLocalNotification", "(Ljava/lang/String;II)V")) {
            return;
        }
        
        jstring stringArg = methodInfo.env->NewStringUTF(message.c_str());
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, stringArg, interval, tag);
        methodInfo.env->DeleteLocalRef(stringArg);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
    
    void NativeLauncher::cancelLocalNotification(int tag)
    {
        JniMethodInfo methodInfo;
        
        if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "cancelLocalNotification", "(I)V")) {
            return;
        }
        
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, tag);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }

    /**
     * オファーウォール型GameFeat表示
     */
    void NativeLauncher::showGameFeat()
    {
    	JniMethodInfo methodInfo;
        
        if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "showGameFeatJNI", "()V")) {
        	return;
        }

        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    }
    
    /**
     * アイコン型GameFeat表示
     */
    void NativeLauncher::showGameFeatIcon()
    {
        JniMethodInfo methodInfo;
        
        if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "showGameFeatIconJNI", "()V")) {
            return;
        }
        
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    }
    
    /**
     * アイコン型GameFeat非表示
     */
    void NativeLauncher::hideGameFeatIcon()
    {
        JniMethodInfo methodInfo;
        
        if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "hideGameFeatIconJNI", "()V")) {
        	return;
        }
        
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    }
    
    void NativeLauncher::loginGameCenter()
    {
        JniMethodInfo methodInfo;
        
        if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "loginGameCenter", "()V")) {
            return;
        }
        
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    }
    
    void NativeLauncher::postHighScore(int score)
    {
        JniMethodInfo methodInfo;
        
        if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "postHighScore", "(I)V")) {
            return;
        }
        
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, score);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
    
    void NativeLauncher::showBanner()
    {
        JniMethodInfo methodInfo;
        
        if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "showBanner", "()V")) {
            return;
        }
        
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    }
    
    void NativeLauncher::hideBanner()
    {
        JniMethodInfo methodInfo;
        
        if (!JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "hideBanner", "()V")) {
            return;
        }
        
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    }
}
