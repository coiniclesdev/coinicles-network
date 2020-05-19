# Coiniclesnet

[Español](readme_es.md)

Coiniclesnet is the reference implementation of LLARP (low latency anonymous routing protocol), a layer 3 onion routing protocol.

You can learn more about the high level design of LLARP [here](docs/high-level.txt)

And you can read the LLARP protocol specification [here](docs/proto_v0.txt)

You can view documentation on how to get started [here](https://coinicles-project.github.io/coinicles-docs/Coiniclesnet/CoiniclesnetOverview/) .

![build status](https://gitlab.com/coiniclesproject/coinicles-network/badges/master/pipeline.svg "build status")
![travis-ci](https://travis-ci.org/coinicles-project/coinicles-network.svg?branch=master "ci status")

## Usage

See the [documentation](https://coinicles-project.github.io/coinicles-docs/Coiniclesnet/CoiniclesnetOverview/) on how to get started.

Also read the [Public Testing Guide](https://coiniclesdocs.com/Coiniclesnet/Guides/PublicTestingGuide/#1-coiniclesnet-installation) for installation and other helpful information.

## Running on Linux

**DO NOT RUN AS ROOT**, run as normal user. This requires the binary to have the proper setcaps set by `make install` on the binary.

to run as client:

    $ coiniclesnet -g
    $ coiniclesnet-bootstrap
    $ coiniclesnet

to run as relay:

    $ coiniclesnet -r -g
    $ coiniclesnet-bootstrap
    $ coiniclesnet

## Running on MacOS/UNIX/BSD

**YOU HAVE TO RUN AS ROOT**, run using sudo. Elevated privileges are needed to create the virtual tunnel interface.

The MacOS installer places the normal binaries (`coiniclesnet` and `coiniclesnet-bootstrap`) in `/usr/local/bin` which should be in your path, so you can easily use the binaries from your terminal. The installer also nukes your previous config and keys and sets up a fresh config and downloads the latest bootstrap seed.

to run as client:

    $ coiniclesnet -g
    $ coiniclesnet-bootstrap
    $ sudo coiniclesnet

to run as relay:

    $ coiniclesnet -r -g
    $ coiniclesnet-bootstrap
    $ sudo coiniclesnet


## Running on Windows

**DO NOT RUN AS ELEVATED USER**, run as normal user.

to run as client, run the `run-coiniclesnet.bat` batch file as your normal user.


## Building

Build requirements:

* GNU Make
* CMake
* C++ 14 capable C++ compiler
* gcovr (if generating test coverage with gcc)
* libuv >= 1.27.0
* libsodium >= 1.0.18
* libcurl

### Linux

build:

    $ sudo apt install build-essential cmake git libcap-dev curl libuv1-dev libsodium-dev libcurl4-openssl-dev pkg-config
    $ git clone https://github.com/coinicles-project/coinicles-network
    $ cd coinicles-network
    $ make 

install:

    $ sudo make install


alternatively make a debian package with:

    $ debuild -uc -us -b

this puts the built packages in `../`


#### Static Linux

static native optimized:

    $ make static STATIC_LINK=ON

cross compile fully static armhf (rpi 2 and up)

    $ make static STATIC_LINK=ON DOWNLOAD_SODIUM=ON TOOLCHAIN=contrib/cross/armhf.toolchain.cmake

### MacOS

build:
    make sure you have cmake, libuv and xcode command line tools installed
    
    $ git clone https://github.com/coinicles-project/coinicles-network
    $ cd coinicles-network
    $ make -j8

install:

    $ sudo make install

### Windows

windows builds are cross compiled from ubuntu linux

build requirements:

* GNU Make
* CMake
* C++ 14 capable C++ compiler
* gcovr (if generating test coverage with gcc)
* libuv >= 1.27.0
* libsodium >= 1.0.17
* libcurl
* nsis
* cpack

setup:
 
    $ sudo apt install build-essential cmake git pkg-config mingw-w64 nsis
    
building:

    $ make windows-release DOWNLOAD_SODIUM=ON STATIC_LINK=ON

### Solaris 2.10+

NOTE: Oracle Solaris users need to download/compile the TAP driver from http://www.whiteboard.ne.jp/~admin2/tuntap/

The generated binaries _may_ work on Solaris 2.10 or earlier, you're on your own. (Recommended: `-static-libstdc++ -static-libgcc`, and the TAP driver if not already installed on the target system.)

Building on a v2.10 or earlier system is unsupported, and may not even work; recent GCC releases have progressively dropped support for older system releases.

build:

    $ sudo pkg install build-essential gcc8 wget tuntap cmake (optional: ninja ccache - from omnios extra) (OmniOS CE)
    $ sudo pkg install base-developer-utilities developer-gnu developer-studio-utilities gcc-7 wget cmake (Oracle Solaris, see note)
    $ sudo pkg install build-essential wget gcc-8 documentation/tuntap header-tun tun (optional: ninja ccache) (all other SunOS)
    $ git clone https://github.com/coinicles-project/coinicles-network
    $ cd coinicles-network
    $ gmake -j8

install:

    $ sudo make install


### NetBSD (and other platforms where pkgsrc is _the_ native package mgr)

TODO: add pkgsrc instructions

### OpenBSD (uses legacy netbsd pkg manager)

build:

    # pkg_add curl cmake git (optional: ninja ccache)
    $ git clone https://github.com/coinicles-project/coinicles-network
    $ cd coinicles-network
    $ gmake -j8

install (root):

    # gmake install

### FreeBSD

build:

    $ pkg install cmake git curl libuv libsodium pkgconf
    $ git clone https://github.com/coinicles-project/coinicles-network
    $ cd coinicles-network
    $ mkdir build
    $ cmake -DCMAKE_BUILD_TYPE=Release ..
    $ make

install (root):

    # make install
