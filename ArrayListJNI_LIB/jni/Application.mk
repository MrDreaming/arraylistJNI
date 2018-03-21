LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
APP_PROJECT_PATH := $(call my-dir)/../
APP_MODULES      :=array
APP_STL := stlport_static

linphone-root-dir:=$(APP_PROJECT_PATH)jni/
LINPHONE_VIDEO:=1
APP_BUILD_SCRIPT:=$(call my-dir)/Android.mk
APP_PLATFORM := android-17
APP_ABI := armeabi
APP_CFLAGS:=-DDISABLE_NEON 