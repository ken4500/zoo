# it is needed for ndk-r5
APP_PLATFORM := android-10
APP_STL := c++_static
#APP_STL := gnustl_static

APP_CPPFLAGS := -frtti -std=c++11 -fsigned-char
APP_MODULES := PluginAdColonyStatic
APP_ABI := armeabi armeabi-v7a
#APP_ABI :=x86
#APP_ABI := armeabi armeabi-v7a arm64-v8a x86 x86_64 mips mips64
