JNIEXPORT void JNICALL setUser(JNIEnv *env, jobject jthiz, jobject objstu){
	jclass cls_user = env->GetObjectClass(objstu); 
	if(cls_user == NULL) {  
        LOGD("GetObjectClass failed \n");
    } 
	
	jfieldID jid = env->GetFieldID(cls_user, "id", "J");
	jlong id = env->GetLongField(objstu, jid);

	jfieldID jsex = env->GetFieldID(cls_user, "isMan", "Z");
	jboolean sex = env->GetBooleanField(objstu, jsex);

	jfieldID jname = env->GetFieldID(cls_user, "userName", "Ljava/lang/String;");
	jstring jstr = (jstring)env->GetObjectField(objstu, jname);
	const char* namePtr = (char*)env->GetStringUTFChars(jstr, 0);

	jfieldID jage = env->GetFieldID(cls_user, "age", "I");
	jint age = env->GetIntField(objstu, jage);

	LOGD("Id=%ld, 0x%x",(unsigned long)id, id );  
	LOGD("Name=%s",namePtr);  
	LOGD("sex=%d",sex);  
	LOGD("Age=%d",age);  
	
}