#!/bin/sh

buildDir=bin

if [ ! -d "$buildDir" ]; then
    mkdir $buildDir
fi
cd $buildDir

# if linux
if [ -z "$1" ]; then
    cmake ..
    make
fi

# else if windows
if [ "$1" = "windows" ]; then
    cmake -G "MinGW Makefiles" ..
    mingw32-make
fi

cd .. #Leave build dir

