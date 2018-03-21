LOCAL_PATH:= $(call my-dir)
SRC:=src
include $(CLEAR_VARS)
LOCAL_MODULE    := libarray

LOCAL_CFLAGS += -D_REENTRANT
LOCAL_CFLAGS += -DPIC
LOCAL_CFLAGS += -DME_COM_EST=1
LOCAL_CFLAGS += -DME_COM_MATRIXSSL=0
LOCAL_CFLAGS += -DME_COM_NANOSSL=0
LOCAL_CFLAGS += -DME_COM_OPENSSL=0
LOCAL_CFLAGS += -DME_COM_SSL=0
LOCAL_CFLAGS += -DME_COM_VXWORKS=0
LOCAL_CFLAGS += -DME_COM_WINSDK=1
LOCAL_CFLAGS += -DME_DEBUG

LOCAL_CFLAGS += -DQNX

LOCAL_SRC_FILES := \
			$(SRC)/HelloJni.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/src
LOCAL_PRELINK_MODULE := false
LOCAL_ARM_MODE := arm
LOCAL_LDLIBS    += -L$(SYSROOT)/usr/lib -lGLESv2 -llog -ldl -lm 	
LOCAL_STATIC_LIBRARIES += cpufeatures

###LOCAL_LDLIBS +=  -L$(LOCAL_PATH)/../lib/lib_so
include $(BUILD_SHARED_LIBRARY)
$(call import-module,android/cpufeatures)

