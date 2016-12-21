cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)

add_library(cpp-library SHARED
    SomeNativeClass.cpp
)

set(DISTRIBUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../jni-wrapper/distribution/libs/android)
set_target_properties(cpp-library PROPERTIES LIBRARY_OUTPUT_DIRECTORY
    "${DISTRIBUTION_DIR}/${ANDROID_ABI}")
