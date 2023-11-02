###############################BASE INFORMATION###################################
cmake_minimum_required(VERSION 3.17.0)
project("R-Type" VERSION 0.1.0 LANGUAGES CXX)

###############################COMPILATION VARIABLES##############################
set(CMAKE_CXX_STANDARD 17)
set(SERVER_NAME "r-type_server")
set(CLIENT_NAME "r-type_client")
set(ECS_TESTS_NAME "r-type_ecs_tests")
set(SERVER_TESTS_NAME "r-type_server_tests")
set(CLIENT_TESTS_NAME "r-type_client_tests")
set(RTYPE_TESTS_NAME "r-type_tests")

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(CXX_FLAGS -Wall -Wextra -Werror)
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CXX_FLAGS -Wall -Wextra)
endif()

###############################INSTALL PACKAGES###################################
include(FetchContent)

FetchContent_Declare(
    cmrc
    GIT_REPOSITORY "https://github.com/vector-of-bool/cmrc.git"
)
FetchContent_MakeAvailable(cmrc)

FetchContent_Declare(
    libconfig
    GIT_REPOSITORY "https://github.com/hyperrealm/libconfig.git"
)
FetchContent_MakeAvailable(libconfig)

if (CMAKE_HOST_WIN32)
    set(libconfig_name "libconfig")
else()
    set(libconfig_name "config")
endif()

FetchContent_Declare(
    SFML
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG "2.6.x"
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
    Boost
    GIT_REPOSITORY "https://github.com/boostorg/boost.git"
    GIT_TAG "boost-1.82.0"
)
FetchContent_MakeAvailable(Boost)

###############################DIRECTORIES SRC####################################

set(ASSETS_FILES
    assets/SpaceBackground.png
    assets/SpaceShips.gif
    assets/PBulletNugo.png
    assets/PBulletAndreas.png
    assets/PBulletEliot.png
    assets/PBulletLouis.png
    assets/PBulletHugo.png
    assets/BulletSpriteMonster.png
    assets/GreyRobotObstacle.gif
    assets/OrangeCrabEnemy.gif
    assets/EBulletOrangeCrab.png
    assets/YellowPopcornEnemy.gif
    assets/PowerUpAttackSpeed.png
    assets/PowerUpDamage.png
    assets/PowerUpHealth.png
    assets/PowerUpSpeed.png
    assets/EBulletYellowPopcorn.png
    assets/font.ttf
    assets/MenuMusic.wav
    assets/BackgroundMusic.wav
    assets/PlugDeathSoundEffect.wav
    assets/LaserSoundEffect.wav
    assets/RizzPowerUpSoundEffect.wav
)

set (ECS_SOURCES
    sources/ECS/EntityClass/Entity.cpp
    sources/ECS/RegistryClass/Registry.cpp
    sources/ECS/Systems/AutoMoveSystem/AutoMoveSystem.cpp
    sources/ECS/Systems/ControlSystem/ControlSystem.cpp
    sources/ECS/Systems/DrawSystem/DrawSystem.cpp
    sources/ECS/Systems/LoggingSystem/LoggingSystem.cpp
    sources/ECS/Systems/PositionSystem/PositionSystem.cpp
    sources/ECS/Systems/ProjectileSystem/ProjectileSystem.cpp
    sources/ECS/Systems/ShootSystem/ShootSystem.cpp
    sources/ECS/Systems/ShootSystem/ShootingPatterns/ShootingPatternFactory.cpp
    sources/ECS/Systems/ShootSystem/ShootingPatterns/AShootingPattern.cpp
    sources/ECS/Systems/ShootSystem/ShootingPatterns/LinearShootingPattern.cpp
    sources/ECS/Systems/ShootSystem/ShootingPatterns/SpreadShootingPattern.cpp
    sources/ECS/Systems/ShootSystem/ShootingPatterns/CircularShootingPattern.cpp
    sources/ECS/Systems/ShootSystem/ShootingPatterns/WaveShootingPattern.cpp
    sources/ECS/Systems/CollisionSystem/CollisionSystem.cpp
    sources/ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.cpp
    sources/ECS/Systems/HealthSystem/HealthSystem.cpp
    sources/ECS/Systems/ScrollSystem/ScrollSystem.cpp
    sources/ECS/Systems/PowerUpSystem/PowerUpSystem.cpp
    sources/ECS/Systems/PowerUpSystem/PowerUpType/PowerUpTypeFactory.cpp
    sources/ECS/Systems/PowerUpSystem/PowerUpType/AttackSpeedType.cpp
    sources/ECS/Systems/PowerUpSystem/PowerUpType/DamageType.cpp
    sources/ECS/Systems/PowerUpSystem/PowerUpType/HealthType.cpp
    sources/ECS/Systems/PowerUpSystem/PowerUpType/SpeedType.cpp
    sources/ECS/Systems/WaveSystem/WaveSystem.cpp
    sources/ECS/Components/EntityClass.cpp
    sources/ECS/Components/Drawable.cpp
    sources/utils/ParserClass/Parser.cpp
    sources/ECS/Assets/Assets.cpp
    sources/ECS/Systems/ScoreSystem/ScoreSystem.cpp
    sources/ECS/Systems/EntityClassSystem/EntityClassSystem.cpp
    sources/client/Buttons/ButtonFactory/ButtonFactory.cpp
    sources/client/Buttons/AButton/AButton.cpp
    sources/client/Buttons/OneUseButton/OneUseButton.cpp
    sources/client/Buttons/CooldownButton/CooldownButton.cpp
    sources/client/Buttons/Button/Button.cpp
)

set(SERVER_SOURCES
    sources/server/udpSocket/udpSocket.cpp
    sources/server/tcpSocket/tcpSocket.cpp
    sources/server/GameModes/DefaultMode/DefaultMode.cpp
    sources/server/GameModes/EndlessMode/EndlessMode.cpp
    sources/server/GameModes/AGameMode/AGameMode.cpp
    sources/server/GameModes/GameModeFactory/GameModeFactory.cpp
    sources/utils/debugColors/debugColors.cpp
    sources/utils/binaryConverter/binaryConverter.cpp
    sources/utils/HandleArgument/HandleArgument.cpp
)

set(CLIENT_SOURCES
    sources/utils/debugColors/debugColors.cpp
    sources/utils/binaryConverter/binaryConverter.cpp
    sources/utils/HandleArgument/HandleArgument.cpp
    sources/client/MainMenu/MainMenu.cpp
    sources/client/tcpClientSocket/tcpClientSocket.cpp
    sources/client/udpClientSocket/udpClientSocket.cpp
    sources/client/InputHandler/InputHandler.cpp
)

set(SERVER_MAIN
    sources/server/main.cpp
)

set(CLIENT_MAIN
    sources/client/main.cpp
)

set(ECS_TESTS
    tests/ECS/PositionSystemTests.cpp
    tests/ECS/RegistrySystemsTests.cpp
    tests/ECS/RegistryTests.cpp
    tests/ECS/SparseArrayTests.cpp
    tests/ECS/CollisionSystemTests.cpp
    tests/ECS/RegistryExportTests.cpp
)

set(SERVER_TESTS
)

set(CLIENT_TESTS
)

###############################COMPILATION MAIN PROGRAM###########################
add_compile_options(${CXX_FLAGS})
include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

cmrc_add_resource_library(
    assets

    ALIAS Assets::RType
    NAMESPACE Assets

    ${ASSETS_FILES}
)

list(APPEND ECS_SOURCES ${GENERATED_ASSET_FILES})

####################### Handle Levels' Configurations Files #######################
file(GLOB LEVEL_FILES "assets/levels/*.yaml")
foreach(LEVEL_FILE ${LEVEL_FILES})
    get_filename_component(LEVEL_NAME ${LEVEL_FILE} NAME_WE)
    set(LEVEL_CONFIG_HPP "${CMAKE_BINARY_DIR}/assets/${LEVEL_NAME}Config.hpp")

    file(REMOVE ${LEVEL_CONFIG_HPP})
    file(APPEND ${LEVEL_CONFIG_HPP} "#include <string>\n\n")
    file(APPEND ${LEVEL_CONFIG_HPP} "const std::string ${LEVEL_NAME}Config = R\"yaml_content(\n")
    file(READ ${LEVEL_FILE} LEVEL_CONFIG_CONTENT)
    file(APPEND ${LEVEL_CONFIG_HPP} "${LEVEL_CONFIG_CONTENT}")
    file(APPEND ${LEVEL_CONFIG_HPP} "    )yaml_content\";\n")

    set(ECS_SOURCES ${ECS_SOURCES} ${LEVEL_CONFIG_HPP})
endforeach()

add_executable(${SERVER_NAME} ${SERVER_MAIN} ${ECS_SOURCES} ${SERVER_SOURCES})
target_include_directories(${SERVER_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
    ${CMAKE_SOURCE_DIR}/build
)
target_link_libraries(${SERVER_NAME} PRIVATE sfml-graphics sfml-audio ${libconfig_name}++ Assets::RType Boost::asio)

add_executable(${CLIENT_NAME} ${CLIENT_MAIN} ${ECS_SOURCES} ${CLIENT_SOURCES})
target_include_directories(${CLIENT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
    ${CMAKE_SOURCE_DIR}/build
)
target_link_libraries(${CLIENT_NAME} PRIVATE sfml-graphics sfml-audio ${libconfig_name}++ Assets::RType Boost::asio)

###############################COMPILATION TESTS##################################
option(BUILD_TESTS "Build tests using Criterion" ON)
if(BUILD_TESTS)
    find_library(CRITERION criterion)
endif()

if (CRITERION)
    #create the tests executable with the criterion library
    add_executable(${ECS_TESTS_NAME} EXCLUDE_FROM_ALL ${ECS_SOURCES} ${ECS_TESTS})
    target_include_directories(${ECS_TESTS_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/sources
        ${CMAKE_SOURCE_DIR}/build
    )
    target_link_libraries(${ECS_TESTS_NAME} PRIVATE ${CRITERION} sfml-graphics sfml-audio Assets::RType Boost::asio)

    add_executable(${SERVER_TESTS_NAME} EXCLUDE_FROM_ALL ${ECS_SOURCES} ${SERVER_SOURCES} ${SERVER_TESTS})
    target_include_directories(${SERVER_TESTS_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/sources
        ${CMAKE_SOURCE_DIR}/build
    )
    target_link_libraries(${SERVER_TESTS_NAME} PRIVATE ${CRITERION} sfml-graphics sfml-audio Assets::RType Boost::asio)

    add_executable(${CLIENT_TESTS_NAME} EXCLUDE_FROM_ALL ${ECS_SOURCES} ${CLIENT_SOURCES} ${CLIENT_TESTS})
    target_include_directories(${CLIENT_TESTS_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/sources
        ${CMAKE_SOURCE_DIR}/build
    )
    target_link_libraries(${CLIENT_TESTS_NAME} PRIVATE ${CRITERION} sfml-graphics sfml-audio ${libconfig_name}++ Assets::RType Boost::asio)

    add_executable(${RTYPE_TESTS_NAME} EXCLUDE_FROM_ALL ${ECS_SOURCES} ${SERVER_SOURCES} ${CLIENT_SOURCES} ${ECS_TESTS} ${SERVER_TESTS} ${CLIENT_TESTS})
    target_include_directories(${RTYPE_TESTS_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/sources
        ${CMAKE_SOURCE_DIR}/build
    )
    target_link_libraries(${RTYPE_TESTS_NAME} PRIVATE ${CRITERION} sfml-graphics sfml-audio ${libconfig_name}++ Assets::RType Boost::asio)
endif()

###############################CUSTOM TARGETS#####################################
add_custom_target(fclean
    COMMAND make clean
    COMMAND find . -name "*~" -delete
    COMMAND find . -name "*.gcno" -delete
    COMMAND find . -name "*.gcda" -delete
    COMMAND find . -name "unit_test" -delete
    COMMAND find . -name "*.o" -delete
    COMMAND find . -name "*.so" -delete
    COMMAND find . -name "CMakeCache.txt" -delete
    COMMAND rm -rf CMakeFiles
    COMMAND find . -name "cmake_install.cmake" -delete
    COMMAND find . -name "Makefile" -delete
    COMMAND find . -name ${SERVER_NAME} -delete
    COMMAND find . -name ${CLIENT_NAME} -delete
    COMMAND find . -name "*.a" -delete
    COMMAND find . -name "lib" -delete
    COMMENT "Clean the project and the binary"
)

#set the target to recompile the project
add_custom_target(re
    COMMAND make clean
    COMMAND make
    COMMENT "Recompiling the project"
)

#compile the server only
add_custom_target(server
    COMMAND ${CMAKE_COMMAND} --build . --target ${SERVER_NAME}
)

#compile the client only
add_custom_target(client
    COMMAND ${CMAKE_COMMAND} --build . --target ${CLIENT_NAME}
)

if (CRITERION)
    #compile the ecs tests only
    add_custom_target(ecs_tests
        COMMAND ${CMAKE_COMMAND} --build . --target ${ECS_TESTS_NAME}
    )

    #compile the ecs tests only and run them
    add_custom_target(ecs_tests_run
        COMMAND ${CMAKE_COMMAND} --build . --target ${ECS_TESTS_NAME}
        COMMAND ../${ECS_TESTS_NAME}
    )

    #compile the server tests only
    add_custom_target(server_tests
        COMMAND ${CMAKE_COMMAND} --build . --target ${SERVER_TESTS_NAME}
    )

    #compile the server tests only and run them
    add_custom_target(server_tests_run
        COMMAND ${CMAKE_COMMAND} --build . --target ${SERVER_TESTS_NAME}
        COMMAND ../${SERVER_TESTS_NAME}
    )

    #compile the client tests only
    add_custom_target(client_tests
        COMMAND ${CMAKE_COMMAND} --build . --target ${CLIENT_TESTS_NAME}
    )

    #compile the client tests only and run them
    add_custom_target(client_tests_run
        COMMAND ${CMAKE_COMMAND} --build . --target ${CLIENT_TESTS_NAME}
        COMMAND ../${CLIENT_TESTS_NAME}
    )

    #compile all the tests
    add_custom_target(tests
        COMMAND ${CMAKE_COMMAND} --build . --target ${RTYPE_TESTS_NAME}
    )

    #compile all the tests and run them
    add_custom_target(tests_run
        COMMAND ${CMAKE_COMMAND} --build . --target ${RTYPE_TESTS_NAME}
        COMMAND ../${RTYPE_TESTS_NAME}
    )
endif()

#compile doxygen documentation
add_custom_target(doxygen
    COMMAND doxygen ../Doxyfile
)

install(TARGETS ${SERVER_NAME})
install(TARGETS ${CLIENT_NAME})
