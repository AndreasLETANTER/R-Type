###############################BASE INFORMATION###################################
cmake_minimum_required(VERSION 3.17.0)
project("R-Type" VERSION 0.1.0 LANGUAGES CXX)

###############################COMPILATION VARIABLES##############################
set(CMAKE_CXX_STANDARD 17)
set(NAME "R-Type")
set(TEST_NAME "unit_tests")
set(CXX_FLAGS -Wall -Wextra -Werror)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

###############################DIRECTORIES SRC####################################
set(SRC
    src/EntityClass/Entity.cpp
    src/RegistryClass/Registry.cpp
    src/Systems/LoggingSystem/LoggingSystem.cpp
    src/Systems/PositionSystem/PositionSystem.cpp
    src/Systems/ControlSystem/ControlSystem.cpp
    src/Systems/DrawSystem/DrawSystem.cpp
    src/Systems/AutoMoveSystem/AutoMoveSystem.cpp
)

set(MAIN
    src/main.cpp
)

set(TESTS
    tests/SparseArrayTests.cpp
    tests/RegistryTests.cpp
    tests/PositionSystemTests.cpp
    tests/RegistrySystemsTests.cpp
)

###############################COMPILATION MAIN PROGRAM###########################
add_compile_options(${CXX_FLAGS})
include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${NAME} ${SRC} ${MAIN})
target_link_libraries(${NAME} PRIVATE sfml-graphics)

###############################COMPILATION TESTS##################################
find_library(CRITERION criterion)
#create the tests executable
add_executable(${TEST_NAME} ${SRC} ${TESTS})
#link the tests with the criterion library
target_link_libraries(${TEST_NAME} PRIVATE ${CRITERION} sfml-graphics)

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
    COMMAND find . -name ${NAME} -delete
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

#set the target to run the tests
add_custom_target(tests_run
    COMMAND make ${TEST_NAME}
    COMMAND ./${TEST_NAME}
    COMMENT "Running unit tests"
)

install(TARGETS ${NAME})
