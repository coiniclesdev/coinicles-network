#ifndef LLARP_UTIL_LOKINET_INIT_H
#define LLARP_UTIL_LOKINET_INIT_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef Coiniclesnet_INIT
#if defined(_WIN32)
#define Coiniclesnet_INIT \
  DieInCaseSomehowThisGetsRunInWineButLikeWTFThatShouldNotHappenButJustInCaseHandleItWithAPopupOrSomeShit
#else
#define Coiniclesnet_INIT _coiniclesnet_non_shit_platform_INIT
#endif
#endif

  int
  Coiniclesnet_INIT(void);

#ifdef __cplusplus
}
#endif
#endif