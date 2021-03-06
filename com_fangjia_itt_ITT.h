/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_fangjia_itt_ITT */

#ifndef _Included_com_fangjia_itt_ITT
#define _Included_com_fangjia_itt_ITT
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_pause
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1pause
  (JNIEnv *, jclass);

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_resume
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1resume
  (JNIEnv *, jclass);

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_detach
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1detach
  (JNIEnv *, jclass);

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_domain_create
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_fangjia_itt_ITT__1_1itt_1domain_1create
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_frame_begin_v3_null_id
 * Signature: (Lcom/fangjia/itt/ITT_Domain;)V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1frame_1begin_1v3_1null_1id
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    __itt_frame_end_v3_null_id
 * Signature: (Lcom/fangjia/itt/ITT_Domain;)V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT__1_1itt_1frame_1end_1v3_1null_1id
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_fangjia_itt_ITT
 * Method:    hello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT_hello
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
