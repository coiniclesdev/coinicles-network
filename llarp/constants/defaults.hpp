#ifndef LLARP_DEFAULTS_HPP
#define LLARP_DEFAULTS_HPP

#ifndef DEFAULT_RESOLVER_US
#define DEFAULT_RESOLVER_US "1.1.1.1"
#endif
#ifndef DEFAULT_RESOLVER_EU
#define DEFAULT_RESOLVER_EU "1.1.1.1"
#endif
#ifndef DEFAULT_RESOLVER_AU
#define DEFAULT_RESOLVER_AU "1.1.1.1"
#endif

#ifdef DEBIAN
#ifndef DEFAULT_COINICLESNET_USER
#define DEFAULT_COINICLESNET_USER "debian-coiniclesnet"
#endif
#ifndef DEFAULT_COINICLESNET_GROUP
#define DEFAULT_COINICLESNET_GROUP "debian-coiniclesnet"
#endif
#else
#ifndef DEFAULT_COINICLESNET_USER
#define DEFAULT_COINICLESNET_USER "coiniclesnet"
#endif
#ifndef DEFAULT_COINICLESNET_GROUP
#define DEFAULT_COINICLESNET_GROUP "coiniclesnet"
#endif
#endif

#endif
