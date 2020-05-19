/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class network_coinicles_coiniclesnet_CoiniclesnetDaemon */

#ifndef _Included_network_coinicles_coiniclesnet_CoiniclesnetDaemon
#define _Included_network_coinicles_coiniclesnet_CoiniclesnetDaemon
#ifdef __cplusplus
extern "C"
{
#endif
  /*
   * Class:     network_coinicles_coiniclesnet_CoiniclesnetDaemon
   * Method:    Obtain
   * Signature: ()Ljava/nio/Buffer;
   */
  JNIEXPORT jobject JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetDaemon_Obtain(JNIEnv *, jclass);

  /*
   * Class:     network_coinicles_coiniclesnet_CoiniclesnetDaemon
   * Method:    Free
   * Signature: (Ljava/nio/Buffer;)V
   */
  JNIEXPORT void JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetDaemon_Free(JNIEnv *, jclass, jobject);

  /*
   * Class:     network_coinicles_coiniclesnet_CoiniclesnetDaemon
   * Method:    Configure
   * Signature: (Lnetwork/coinicles/coiniclesnet/CoiniclesnetConfig;)Z
   */
  JNIEXPORT jboolean JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetDaemon_Configure(JNIEnv *, jobject, jobject);

  /*
   * Class:     network_coinicles_coiniclesnet_CoiniclesnetDaemon
   * Method:    Mainloop
   * Signature: ()I
   */
  JNIEXPORT jint JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetDaemon_Mainloop(JNIEnv *, jobject);

  /*
   * Class:     network_coinicles_coiniclesnet_CoiniclesnetDaemon
   * Method:    IsRunning
   * Signature: ()Z
   */
  JNIEXPORT jboolean JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetDaemon_IsRunning(JNIEnv *, jobject);

  /*
   * Class:     network_coinicles_coiniclesnet_CoiniclesnetDaemon
   * Method:    Stop
   * Signature: ()Z
   */
  JNIEXPORT jboolean JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetDaemon_Stop(JNIEnv *, jobject);

  /*
   * Class:     network_coinicles_coiniclesnet_CoiniclesnetDaemon
   * Method:    InjectVPN
   * Signature: (Lnetwork/coinicles/coiniclesnet/CoiniclesnetVPN;)Z
   */
  JNIEXPORT jboolean JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetDaemon_InjectVPN(JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif