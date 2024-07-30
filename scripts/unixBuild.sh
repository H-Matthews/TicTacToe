#!/bin/bash

cmake -E make_directory ../build
cd ../build 

cmake -DCMAKE_BUILD_TYPE=Debug ../
cmake --build . --target Debug --config Debug
cmake --install . --prefix ../install
