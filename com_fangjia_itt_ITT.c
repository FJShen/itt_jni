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
 * Method:    hello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_fangjia_itt_ITT_hello
  (JNIEnv *env, jclass obj){
    printf("Hello from JNI class ITT\n");
  }