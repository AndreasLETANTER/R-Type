#!/bin/bash

if [ ! -d "vcpkg" ]; then
    git clone https://github.com/microsoft/vcpkg.git
    cd vcpkg
    ./bootstrap-vcpkg.sh
else
    cd vcpkg
fi

./vcpkg install sfml
./vcpkg install boost-asio
