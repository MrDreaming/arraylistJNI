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