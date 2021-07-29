#include "com_fangjia_itt_ITT.h"
#include <jni.h>
#include <ittnotify.h>

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_pause
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1pause
  (JNIEnv *env, jclass obj){
    __itt_pause();
}

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_resume
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1resume
  (JNIEnv *env, jclass obj){
    __itt_resume();
}

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_detach
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1detach
  (JNIEnv *env, jclass obj){
    __itt_detach();
}


/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_domain_create
 * Signature: (Ljava/lang/String;)Ljava/lang/Long;
 */
JNIEXPORT jlong JNICALL Java_com_fangjia_itt_ITT__1_1itt_1domain_1create
  (JNIEnv *env, jclass obj, jstring j_name){
    jboolean iscopy;
    const char *name = (*env)->GetStringUTFChars(env, j_name, &iscopy);
    __itt_domain *pD = __itt_domain_create(name);
    (*env)->ReleaseStringUTFChars(env, j_name, name);

    //printf("From c function Java_com_fangjia_itt_ITT__1_1itt_1domain_1create: __itt_domain is %p\n", (void*)(pD));

    return (long)(pD);
}


/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_frame_begin_v3
 * Signature: (Lcom/fangjia/itt/ITT_Domain;Ljava/lang/Integer;)V
 */
/*JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1frame_1begin_1v3
  (JNIEnv *env, jclass clazz, jobject domain, jobject integer){
    //this method assumes the id is not NULL. 
    //In the case of NULL id, __itt_frame_begin_v3_null_id is called instead
    jfieldID fid;
    jmethodID mid;
    jlong domain_ptr;
    jint frame_id;

    //get domain pointer
    fid = (*env)->GetFieldID(env, domain, "domain_ptr", "J");
    domain_ptr = (*env)->GetLongField(env, domain, fid);

    //get frame_id
    mid = (*env)->GetMethodID(env, integer, "intValue", "()I");
    frame_id = (*env)->CallIntMethod(env, integer, mid);

    //invoke ITT API
    printf("invoking __itt_frame_begin_v3 on domain ptr %p with frame id %d", (void*)(domain_ptr), frame_id);
    __itt_frame_begin_v3((__itt_domain*)(domain_ptr), (int)(frame_id));
}*/

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_frame_begin_v3_null_id
 * Signature: (Lcom/fangjia/itt/ITT_Domain;Ljava/lang/Integer;)V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1frame_1begin_1v3_1null_1id
  (JNIEnv *env, jclass clazz, jobject domain){
    //this method is called when the frame ID is set to be null 
    jfieldID fid;
    jlong domain_ptr;
    jclass domain_class;

    //get domain pointer
    domain_class = (*env)->GetObjectClass(env, domain);
    fid = (*env)->GetFieldID(env, domain_class, "domain_ptr", "J");
    //if(fid==NULL){printf("NULL fid\n");return;}
    //else printf("fid=%d\n", fid);
    domain_ptr = (*env)->GetLongField(env, domain, fid);

    //invoke ITT API
    //printf("invoking __itt_frame_begin_v3 on domain ptr %p with frame id NULL", (void*)(domain_ptr));
    __itt_frame_begin_v3((__itt_domain*)(domain_ptr), NULL);     
}


/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_frame_end_v3
 * Signature: (Lcom/fangjia/itt/ITT_Domain;Ljava/lang/Integer;)V
 */
/*JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1frame_1end_1v3
  (JNIEnv *env, jclass clazz, jobject domain, jobject integer){
    //this method assumes the id is not NULL. 
    //In the case of NULL id, __itt_frame_end_v3_null_id is called instead
    jfieldID fid;
    jmethodID mid;
    jlong domain_ptr;
    jint frame_id;

    //get domain pointer
    fid = (*env)->GetFieldID(env, domain, "domain_ptr", "J");
    domain_ptr = (*env)->GetLongField(env, domain, fid);

    //get frame_id
    mid = (*env)->GetMethodID(env, integer, "intValue", "()I");
    frame_id = (*env)->CallIntMethod(env, integer, mid);

    //invoke ITT API
    printf("invoking __itt_frame_end_v3 on domain ptr %p with frame id %d", (void*)(domain_ptr), frame_id);
    __itt_frame_end_v3((__itt_domain*)(domain_ptr), (int)(frame_id));
}*/


/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_frame_end_v3_null_id
 * Signature: (Lcom/fangjia/itt/ITT_Domain;Ljava/lang/Integer;)V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1frame_1end_1v3_1null_1id
  (JNIEnv *env, jclass clazz, jobject domain){
    //this method is called when the frame ID is set to be null 
    jfieldID fid;
    jlong domain_ptr;
    jclass domain_class;

    //get domain pointer
    domain_class = (*env)->GetObjectClass(env, domain);
    fid = (*env)->GetFieldID(env, domain_class, "domain_ptr", "J");
    //if(fid==NULL){printf("NULL fid\n");return;}
    //else printf("fid=%d\n", fid);
    domain_ptr = (*env)->GetLongField(env, domain, fid);

    //invoke ITT API
    //printf("invoking __itt_frame_end_v3 on domain ptr %p with frame id NULL", (void*)(domain_ptr));
    __itt_frame_end_v3((__itt_domain*)(domain_ptr), NULL);  
}

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    hello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT_hello
  (JNIEnv *env, jclass obj){
    printf("Hello from JNI class ITT\n");
  }