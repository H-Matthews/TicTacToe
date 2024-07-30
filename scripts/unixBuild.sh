#!/bin/bash

if test -d ../build; then
    rm -dr ../build
fi

if test -d ../install; then
    rm -dr ../install
fi

mkdir ../build
cd ../build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../
cmake --build .
cmake --install . --prefix ../install
