#!/usr/bin/env bash
#
# \file  android_makefile.sh
# \brief build project
#


# vars
DIR_XLIB="../xLib"
DIR_BUILD="../../xLib_android_eclipse"


# build
mkdir -p $DIR_BUILD
cd $DIR_BUILD
cmake \
	-G"Eclipse CDT4 - Unix Makefiles" \
	-D_ECLIPSE_VERSION=4.3 \
	-DCMAKE_TOOLCHAIN_FILE=$DIR_XLIB/CMake/android.toolchain.cmake \
	$DIR_XLIB
