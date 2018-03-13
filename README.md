# Bitprim Database <a target="_blank" href="https://gitter.im/bitprim/Lobby">![Gitter Chat][badge.Gitter]</a>

*Bitcoin High Performance Blockchain Database*

| **master(linux/osx)** | **dev(linux/osx)**   | **master(windows)**   | **dev(windows)** |
|:------:|:-:|:-:|:-:|
| [![Build Status](https://travis-ci.org/bitprim/bitprim-database.svg)](https://travis-ci.org/bitprim/bitprim-database)       | [![Build StatusB](https://travis-ci.org/bitprim/bitprim-database.svg?branch=dev)](https://travis-ci.org/bitprim/bitprim-database?branch=dev)  | [![Appveyor Status](https://ci.appveyor.com/api/projects/status/github/bitprim/bitprim-database?svg=true)](https://ci.appveyor.com/project/bitprim/bitprim-database)  | [![Appveyor StatusB](https://ci.appveyor.com/api/projects/status/github/bitprim/bitprim-database?branch=dev&svg=true)](https://ci.appveyor.com/project/bitprim/bitprim-database?branch=dev)  |

Table of Contents
=================

   * [Bitprim Database](#bitprim-database)
      * [About Bitprim Database](#about-bitprim-database)
      * [Installation](#installation)
        * [Using Conan](#using-conan-recommended)
        * [Build from source](#build-from-source)
            * [Debian/Ubuntu](#debianubuntu)
            * [Windows with Visual Studio](#windows-with-visual-studio)

## About Bitprim Database

Bitprim Database is a custom database build directly on the operating system's [memory-mapped file](https://en.wikipedia.org/wiki/Memory-mapped_file) system. All primary tables and indexes are built on in-memory hash tables, resulting in constant-time lookups. The database uses [sequence locking](https://en.wikipedia.org/wiki/Seqlock) to avoid writer starvation while never blocking the reader. This is ideal for a high performance blockchain server as reads are significantly more frequent than writes and yet writes must proceed wtihout delay. The [bitprim-blockchain](https://github.com/bitprim/bitprim-blockchain) library uses the database as its blockchain store.

## Installation

### Using Conan (recommended)

Conan is a Python package for dependency management; it only requires Python and Pip.
With Conan, install can be performed on any OS. If there are no prebuilt binaries for a given
OS-compiler-arch combination, Conan will build from source.

```
pip install conan
conan remote add bitprim https://api.bintray.com/conan/bitprim/bitprim
conan install bitprim-database/0.1@bitprim/stable
```

The last step will install binaries and headers in Conan's cache, a directory outside the usual
system paths. This will avoid conflict with system packages such as boost.
Also, notice it references the stable version 0.1. To see which versions are available,
please check [Bintray](https://bintray.com/bitprim/bitprim/bitprim-database%3Abitprim).

### Build from source

#### Debian/Ubuntu

Make sure you have installed [bitprim-core](https://github.com/bitprim/bitprim-core) beforehand according to its build instructions.

```
$ git clone https://github.com/bitprim/bitprim-database.git
$ cd bitprim-database
$ mkdir build
$ cd build
$ cmake .. -DWITH_TESTS=OFF -DWITH_TOOLS=OFF -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-std=c++11"
$ make -j2
$ sudo make install
$ sudo ldconfig
```

bitprim-database will now be installed in `/usr/local/`.

#### Windows with Visual Studio

This project, unlike secp256k1, has external dependencies such as boost.
The easiest way to build them is to use Conan from the CMake script,
which will install boost and other libraries in non-system directories.

From a [Visual Studio Developer Command Prompt](https://docs.microsoft.com/en-us/dotnet/framework/tools/developer-command-prompt-for-vs):

```
$ pip install conan
$ git clone https://github.com/bitprim/bitprim-database.git
$ cd bitprim-database
$ mkdir build
$ cd build
$ conan install ..
$ cmake .. -DUSE_CONAN=ON -DNO_CONAN_AT_ALL=OFF
$ msbuild ALL_BUILD.vcxproj
```

[badge.Gitter]: https://img.shields.io/badge/gitter-join%20chat-blue.svg
