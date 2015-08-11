LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PluginAdColonyStatic

LOCAL_MODULE_FILENAME := libPluginAdColonyStatic

LOCAL_SRC_FILES :=\
$(addprefix ../../platform/android/, \
    JniProtocolAdColonyAds.cpp \
) \
../../AdColonyAgent.cpp

LOCAL_CFLAGS := -std=c++11 -Wno-psabi
LOCAL_EXPORT_CFLAGS := -Wno-psabi

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../include $(LOCAL_PATH)/../../platform/android
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../protocols/include $(LOCAL_PATH)/../../../../protocols/platform/android
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../include $(LOCAL_PATH)/../../platform/android

LOCAL_LDLIBS := -landroid
LOCAL_LDLIBS += -llog
LOCAL_STATIC_LIBRARIES := android_native_app_glue

include $(BUILD_STATIC_LIBRARY)

$(call import-module,android/native_app_glue)
