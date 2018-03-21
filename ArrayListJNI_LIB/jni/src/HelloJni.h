#include <jni.h>  
/* Header for class HelloJni */  
#ifndef _Included_HelloJni  
#define _Included_HelloJni  
#include<android/log.h>
//#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "NDK_TEST", __VA_ARGS__)

#ifdef __cplusplus  
extern "C" {  
#endif  

JNIEXPORT void JNICALL setUser(JNIEnv *env, jobject jthiz, jobject objstu);
JNIEXPORT jobject getUser(JNIEnv *env, jobject jthiz);
JNIEXPORT void JNICALL setUserList(JNIEnv *env, jobject jthiz, jobject userList);
JNIEXPORT jobject JNICALL  getUserList(JNIEnv *env, jobject jthiz);

#ifdef __cplusplus  
}  
#endif  
#endif  