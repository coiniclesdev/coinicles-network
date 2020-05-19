#include "network_coinicles_coiniclesnet_CoiniclesnetVPN.h"
#include "coiniclesnet_jni_vpnio.hpp"
#include "coiniclesnet_jni_common.hpp"
#include <net/ip.hpp>

extern "C"
{
  JNIEXPORT jint JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetVPN_PacketSize(JNIEnv *, jclass)
  {
    return llarp::net::IPPacket::MaxSize;
  }

  JNIEXPORT jobject JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetVPN_Alloc(JNIEnv *env, jclass)
  {
    coiniclesnet_jni_vpnio *vpn = new coiniclesnet_jni_vpnio();
    return env->NewDirectByteBuffer(vpn, sizeof(coiniclesnet_jni_vpnio));
  }

  JNIEXPORT void JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetVPN_Free(JNIEnv *env, jclass, jobject buf)
  {
    coiniclesnet_jni_vpnio *vpn = FromBuffer< coiniclesnet_jni_vpnio >(env, buf);
    if(vpn == nullptr)
      return;
    delete vpn;
  }
  JNIEXPORT void JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetVPN_Stop(JNIEnv *env, jobject self)
  {
    coiniclesnet_jni_vpnio *vpn = GetImpl< coiniclesnet_jni_vpnio >(env, self);
    if(vpn)
    {
      vpn->Close();
    }
  }

  JNIEXPORT jint JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetVPN_ReadPkt(JNIEnv *env, jobject self,
                                               jobject pkt)
  {
    coiniclesnet_jni_vpnio *vpn = GetImpl< coiniclesnet_jni_vpnio >(env, self);
    if(vpn == nullptr)
      return -1;
    void *pktbuf = env->GetDirectBufferAddress(pkt);
    auto pktlen  = env->GetDirectBufferCapacity(pkt);
    if(pktbuf == nullptr)
      return -1;
    return vpn->ReadPacket(pktbuf, pktlen);
  }

  JNIEXPORT jboolean JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetVPN_WritePkt(JNIEnv *env, jobject self,
                                                jobject pkt)
  {
    coiniclesnet_jni_vpnio *vpn = GetImpl< coiniclesnet_jni_vpnio >(env, self);
    if(vpn == nullptr)
      return false;
    void *pktbuf = env->GetDirectBufferAddress(pkt);
    auto pktlen  = env->GetDirectBufferCapacity(pkt);
    if(pktbuf == nullptr)
      return false;
    return vpn->WritePacket(pktbuf, pktlen);
  }

  JNIEXPORT void JNICALL
  Java_network_coinicles_coiniclesnet_CoiniclesnetVPN_SetInfo(JNIEnv *env, jobject self,
                                               jobject info)
  {
    coiniclesnet_jni_vpnio *vpn = GetImpl< coiniclesnet_jni_vpnio >(env, self);
    if(vpn == nullptr)
      return;
    VisitObjectMemberStringAsStringView< bool >(
        env, info, "ifaddr", [vpn](llarp::string_view val) -> bool {
          vpn->SetIfAddr(val);
          return true;
        });
    VisitObjectMemberStringAsStringView< bool >(
        env, info, "ifname", [vpn](llarp::string_view val) -> bool {
          vpn->SetIfName(val);
          return true;
        });
    vpn->info.netmask = GetObjectMemberAsInt< uint8_t >(env, info, "netmask");
  }
}