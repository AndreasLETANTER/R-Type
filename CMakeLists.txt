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
set(CXX_FLAGS -Wall -Wextra -Werror)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

###############################DIRECTORIES SRC####################################

set(ASSETS_FILES
    ../assets/Space_Background.png
    ../assets/BurpTemporaryBullet.png
    ../assets/NugoTemporaryIcon.png
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
    sources/ECS/Systems/CollisionSystem/CollisionSystem.cpp
    sources/ECS/Systems/ProjectileCollisionSystem/ProjectileCollisionSystem.cpp
    sources/ECS/Systems/HealthSystem/HealthSystem.cpp
    sources/ECS/Components/Drawable.cpp
)

set(SERVER_SOURCES
    sources/server/handleArgument/handleArgument.cpp
    sources/utils/debugColors/debugColors.cpp
)

set(CLIENT_SOURCES
    sources/client/Game/Game.cpp
    sources/client/Background/Background.cpp
    sources/utils/debugColors/debugColors.cpp
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
    tests/ECS/ProjectileCollisionSystemTests.cpp
    tests/ECS/HealthSystemTests.cpp
    tests/ECS/RegistryExportTests.cpp
    tests/ECS/RegistryImportTests.cpp
)

set(SERVER_TESTS
    tests/server/handleArgument.cpp
)

set(CLIENT_TESTS
)

###############################COMPILATION MAIN PROGRAM###########################
add_compile_options(${CXX_FLAGS})
include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/assets")
foreach(asset_file ${ASSETS_FILES})
    get_filename_component(asset_name ${asset_file} NAME_WE)
    set(output_hpp_file "${CMAKE_BINARY_DIR}/assets/${asset_name}.hpp")
    add_custom_command(
        OUTPUT ${output_hpp_file}
        COMMAND xxd -i ${asset_file} > ${output_hpp_file}
        DEPENDS ${asset_file}
    )
    list(APPEND GENERATED_ASSET_FILES ${output_hpp_file})
endforeach()

list(APPEND ECS_SOURCES ${GENERATED_ASSET_FILES})

add_executable(${SERVER_NAME} ${SERVER_MAIN} ${ECS_SOURCES} ${SERVER_SOURCES})
target_include_directories(${SERVER_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
)
target_link_libraries(${SERVER_NAME} PRIVATE sfml-graphics)

add_executable(${CLIENT_NAME} ${CLIENT_MAIN} ${ECS_SOURCES} ${CLIENT_SOURCES})
target_include_directories(${CLIENT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
    ${CMAKE_SOURCE_DIR}/build
)
target_link_libraries(${CLIENT_NAME} PRIVATE sfml-graphics)

###############################COMPILATION TESTS##################################
find_library(CRITERION criterion)
#create the tests executable with the criterion library
add_executable(${ECS_TESTS_NAME} EXCLUDE_FROM_ALL ${ECS_SOURCES} ${ECS_TESTS})
target_include_directories(${ECS_TESTS_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
    ${CMAKE_SOURCE_DIR}/build
)
target_link_libraries(${ECS_TESTS_NAME} PRIVATE ${CRITERION} sfml-graphics)

add_executable(${SERVER_TESTS_NAME} EXCLUDE_FROM_ALL ${ECS_SOURCES} ${SERVER_SOURCES} ${SERVER_TESTS})
target_include_directories(${SERVER_TESTS_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
)
target_link_libraries(${SERVER_TESTS_NAME} PRIVATE ${CRITERION} sfml-graphics)

add_executable(${CLIENT_TESTS_NAME} EXCLUDE_FROM_ALL ${ECS_SOURCES} ${CLIENT_SOURCES} ${CLIENT_TESTS})
target_include_directories(${CLIENT_TESTS_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
    ${CMAKE_SOURCE_DIR}/build
)
target_link_libraries(${CLIENT_TESTS_NAME} PRIVATE ${CRITERION} sfml-graphics)

add_executable(${RTYPE_TESTS_NAME} EXCLUDE_FROM_ALL ${ECS_SOURCES} ${SERVER_SOURCES} ${CLIENT_SOURCES} ${ECS_TESTS} ${SERVER_TESTS} ${CLIENT_TESTS})
target_include_directories(${RTYPE_TESTS_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/sources
    ${CMAKE_SOURCE_DIR}/build
)
target_link_libraries(${RTYPE_TESTS_NAME} PRIVATE ${CRITERION} sfml-graphics)

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

#compile doxygen documentation
add_custom_target(doxygen
    COMMAND doxygen ../Doxyfile
)

install(TARGETS ${SERVER_NAME})
install(TARGETS ${CLIENT_NAME})
