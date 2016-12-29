cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)

add_library(native-lib SHARED
    src/main/cpp/helper/JavaByteArray.cpp
    src/main/cpp/helper/JavaString.cpp
    src/main/cpp/jp_keita_kagurazaka_jnisample_SomeNativeClassWrapper.cpp
)

add_subdirectory(../../cpp-library cpp-library)
include_directories(../../cpp-library)

target_link_libraries(native-lib cpp-library)

set(DISTRIBUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../distribution/libs/android)
set_target_properties(native-lib PROPERTIES LIBRARY_OUTPUT_DIRECTORY
    "${DISTRIBUTION_DIR}/${ANDROID_ABI}")
