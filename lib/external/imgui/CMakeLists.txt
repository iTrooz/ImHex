cmake_minimum_required(VERSION 3.16)
project(imgui)

set(CMAKE_CXX_STANDARD 17)

if(TRUE) # TODO check if debug cmake build
    set(TEST_ENGINE_SRC_DIR ${EXTERN_LIBS_FOLDER}/imgui/test_engine/imgui_test_engine)

    file(GLOB_RECURSE
        TEST_ENGINE_SRC_FILES
        ${TEST_ENGINE_SRC_DIR}/*.cpp
    )

    add_compile_definitions(IMGUI_ENABLE_TEST_ENGINE=ON)
endif()

find_package(PkgConfig REQUIRED)
find_package(Freetype REQUIRED)
find_package(OpenGL REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

add_library(imgui OBJECT
        source/imgui.cpp
        source/imgui_demo.cpp
        source/imgui_draw.cpp
        include/misc/freetype/imgui_freetype.cpp # TODO move source and includes in the same directory
        source/imgui_impl_glfw.cpp
        source/imgui_impl_opengl3.cpp
        source/imgui_tables.cpp
        source/imgui_widgets.cpp

        source/TextEditor.cpp

        source/imnodes.cpp

        source/implot.cpp
        source/implot_items.cpp
        source/implot_demo.cpp

        source/fonts/fontawesome_font.c
        source/fonts/codicons_font.c
        source/fonts/unifont_font.c

        ${TEST_ENGINE_SRC_FILES}
)

target_compile_definitions(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)
target_compile_options(imgui PRIVATE -Wno-stringop-overflow)

target_compile_definitions(imgui PUBLIC IMGUI_USER_CONFIG="imgui_config.h")

target_include_directories(imgui PUBLIC include ${FREETYPE_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${OpenGL_INCLUDE_DIRS})
target_link_directories(imgui PUBLIC ${GLFW_LIBRARY_DIRS} ${OpenGL_LIBRARY_DIRS})
target_link_libraries(imgui PUBLIC Freetype::Freetype ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
