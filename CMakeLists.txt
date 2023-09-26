###############################BASE INFORMATION###################################
cmake_minimum_required(VERSION 3.17.0)
project("R-Type" VERSION 0.1.0 LANGUAGES CXX)

###############################COMPILATION VARIABLES##############################
set(CMAKE_CXX_STANDARD 17)
set(NAME "R-Type")
set(CXX_FLAGS -Wall -Wextra -Werror)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

###############################DIRECTORIES SRC####################################

set(ASSET_FILES
    ../assets/Space_Background.png
)

set(SRC
    sources/client/Game/Game.cpp
    sources/client/Background/Background.cpp
)

set(MAIN
    sources/main.cpp
)

set(TESTS

)

###############################COMPILATION MAIN PROGRAM###########################
add_compile_options(${CXX_FLAGS})
include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/assets")
foreach(asset_file ${ASSET_FILES})
    get_filename_component(asset_name ${asset_file} NAME_WE)
    set(output_hpp_file "${CMAKE_BINARY_DIR}/assets/${asset_name}.hpp")
    add_custom_command(
        OUTPUT ${output_hpp_file}
        COMMAND xxd -i ${asset_file} > ${output_hpp_file}
        DEPENDS ${asset_file}
    )
    list(APPEND GENERATED_ASSET_FILES ${output_hpp_file})
endforeach()

list(APPEND SRC ${GENERATED_ASSET_FILES})

add_executable(${NAME} ${SRC} ${MAIN})
target_link_libraries(${NAME} PRIVATE sfml-graphics)

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

install(TARGETS ${NAME})
