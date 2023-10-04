@echo off

IF NOT EXIST vcpkg (
    git clone https://github.com/microsoft/vcpkg.git
    cd vcpkg
    bootstrap-vcpkg.bat
) ELSE (
    cd vcpkg
)

vcpkg install sfml
vcpkg install asio

cd..
