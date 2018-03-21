#include "HelloJni.h"  
#include <assert.h>
#include <stdlib.h>

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, "NDK_TEST", __VA_ARGS__)

JNIEXPORT void JNICALL setUser(JNIEnv *env, jobject jthiz, jobject objstu){
	jclass cls_user = env->GetObjectClass(objstu); 
	if(cls_user == NULL) {  
        LOGD("GetObjectClass failed \n");
    } 
	
	jmethodID jid = env->GetMethodID(cls_user,"getId","()J");  
	jlong id = env->CallLongMethod(objstu,jid);  

	jmethodID jsex = env->GetMethodID(cls_user,"isMan","()Z");  
	jboolean sex = env->CallBooleanMethod(objstu,jsex);  

	jmethodID jname = env->GetMethodID(cls_user,"getUserName","()Ljava/lang/String;");  
	jstring jstr = (jstring)env->CallObjectMethod(objstu,jname); 
	const char *namePtr = env->GetStringUTFChars(jstr,0);  

	jmethodID jage = env->GetMethodID(cls_user,"getAge","()I");  
	jint age = env->CallIntMethod(objstu,jage);  
	LOGD("Id=%ld, 0x%x",(unsigned long)id, id );  
	LOGD("Name=%s",namePtr);  
	LOGD("sex=%d",sex);  
	LOGD("Age=%d",age);  
	
}

JNIEXPORT jobject getUser(JNIEnv *env, jobject jthiz){
	jclass cls_user = env->FindClass("com/example/arraylistjni/User");
	jmethodID constrocMID = env->GetMethodID(cls_user,"<init>","()V"); 
	
	jobject obj_user = env->NewObject(cls_user,constrocMID,"");  
	//get field id  
	jfieldID user_id = env->GetFieldID(cls_user,"id","J");  
	jfieldID user_name = env->GetFieldID(cls_user,"userName","Ljava/lang/String;");  
	jfieldID user_isMan = env->GetFieldID(cls_user,"isMan","Z");  
	jfieldID user_age = env->GetFieldID(cls_user,"age","I");  
	
	env->SetLongField(obj_user,user_id,1008);  
	
	env->SetObjectField(obj_user,user_name,env->NewStringUTF(__FILE__));  
	env->SetBooleanField(obj_user,user_isMan,0);  
	env->SetIntField(obj_user,user_age,18);  
	LOGD("%s(%s:%d)add", __FILE__, __FUNCTION__, __LINE__);  
	return obj_user;
}

JNIEXPORT void JNICALL setUserList(JNIEnv *env, jobject jthiz, jobject userList){  
        int i;  
        //class ArrayList  
        jclass cls_arraylist = env->GetObjectClass(userList);  
        //method in class ArrayList  
        jmethodID arraylist_get = env->GetMethodID(cls_arraylist,"get","(I)Ljava/lang/Object;");  
        jmethodID arraylist_size = env->GetMethodID(cls_arraylist,"size","()I");  
        jint len = env->CallIntMethod(userList,arraylist_size);  
        LOGD("get java ArrayList<User> object by C++ , then print it.....\n");  
        for(i=0;i<len;i++){  
                jobject obj_user = env->CallObjectMethod(userList,arraylist_get,i);  
                jclass cls_user = env->GetObjectClass(obj_user);  
                jmethodID user_getId = env->GetMethodID(cls_user,"getId","()J");  
                jmethodID user_getUserName = env->GetMethodID(cls_user,"getUserName","()Ljava/lang/String;");  
                jmethodID user_isMan = env->GetMethodID(cls_user,"isMan","()Z");  
                jmethodID user_getAge = env->GetMethodID(cls_user,"getAge","()I");  
                jstring name = (jstring)env->CallObjectMethod(obj_user,user_getUserName);  
                jboolean b = true;  
                const char *namePtr = env->GetStringUTFChars(name,&b);  
                jlong id = env->CallLongMethod(obj_user,user_getId);  
                jboolean sex = env->CallBooleanMethod(obj_user,user_isMan);  
                jint age = env->CallIntMethod(obj_user,user_getAge);  
                LOGD("Id=%ld, 0x%x",(unsigned long)id, id );  
                LOGD("Name=%s",namePtr);  
                LOGD("sex=%d",sex);  
                LOGD("Age=%d",age);  
        }  
}  

JNIEXPORT jobject JNICALL  getUserList(JNIEnv *env, jobject jthiz){
		LOGD("%s(%s:%d)", __FILE__, __FUNCTION__, __LINE__);  
		
        //ArrayList Object  
        jclass cls_ArrayList = env->FindClass("java/util/ArrayList");  
        jmethodID construct = env->GetMethodID(cls_ArrayList,"<init>","()V");  
        jobject obj_ArrayList = env->NewObject(cls_ArrayList,construct,"");  
        jmethodID arrayList_add = env->GetMethodID(cls_ArrayList,"add","(Ljava/lang/Object;)Z");  
		LOGD("%s(%s:%d)arrayList_add=%d", __FILE__, __FUNCTION__, __LINE__, arrayList_add);  
		jclass cls_user = env->FindClass("com/example/arraylistjni/User");  
		
        //none argument construct function  
        jmethodID construct_user = env->GetMethodID(cls_user,"<init>","()V");  
        //new a object  
        jobject obj_user = env->NewObject(cls_user,construct_user,"");  

        int i;  
        for(i=0;i<10;i++){  
			jobject obj_user = env->NewObject(cls_user,construct_user,"");  
			jfieldID user_id = env->GetFieldID(cls_user,"id","J");  
			jfieldID user_name = env->GetFieldID(cls_user,"userName","Ljava/lang/String;");  
			jfieldID user_isMan = env->GetFieldID(cls_user,"isMan","Z");  
			jfieldID user_age = env->GetFieldID(cls_user,"age","I");  			
			env->SetLongField(obj_user,user_id,i);  			
			env->SetObjectField(obj_user,user_name,env->NewStringUTF("HelloJni.cpp"));  
			env->SetBooleanField(obj_user,user_isMan,1);  
			env->SetIntField(obj_user,user_age,21);  
			env->CallBooleanMethod(obj_ArrayList,arrayList_add,obj_user);  
			LOGD("%s(%s:%d)add %d", __FILE__, __FUNCTION__, __LINE__, i);  	
        }  
        return obj_ArrayList;  
}  

static JNINativeMethod methods[] = {
		{"setUserList", "(Ljava/util/ArrayList;)V", (void *) setUserList},
		{"getUserList", "()Ljava/util/ArrayList;", (void *) getUserList},
		{"setUser", "(Lcom/example/arraylistjni/User;)V", (void *) setUser},
		{"getUser", "()Lcom/example/arraylistjni/User;", (void *) getUser}
};

static int registerNativeMethods(JNIEnv *env, const char *className, JNINativeMethod *gMethods, int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == 0) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

static int registerNatives(JNIEnv *env) {
    const char *className = "com/example/arraylistjni/HelloJni";
    return registerNativeMethods(env, className, methods, sizeof(methods) / sizeof(methods[0]));
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv* env = 0;
    jint result = -1;

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK){
        return -1;
    }
    assert(env != 0);

    if (!registerNatives(env)) {
        return -1;
    }

    return JNI_VERSION_1_4;
}