@echo off

vcpkg list | findstr "sfml" > nul
if errorlevel 1 (
    echo Installing SFML...
    vcpkg install sfml
    vcpkg install asio
    vcpkg install boost
)

pause
