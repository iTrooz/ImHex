cmake_minimum_required(VERSION 3.16)

include(ImHexPlugin)

add_subdirectory(${THIRD_PARTY_LIBS_FOLDER}/HashLibPlus ${CMAKE_CURRENT_BINARY_DIR}/HashLibPlus)
enableUnityBuild(hashplus)

# HashLibPlus's public Converters.h uses strtol without including its declaration.
if (MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(hashplus PUBLIC "$<$<COMPILE_LANGUAGE:CXX>:SHELL:-include stdlib.h>")
endif()

add_imhex_plugin(
    NAME
        hashes
    SOURCES
        source/plugin_hashes.cpp

        source/content/hashes.cpp

        source/content/views/view_hashes.cpp
    INCLUDES
        include
    LIBRARIES
        ui
        fonts
        hashplus
)
