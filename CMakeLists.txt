cmake_minimum_required(VERSION 3.20)

project(LIB_CMAKE_TEMPLATE VERSION 0.0.0 LANGUAGES CXX)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are not allowed")
endif()

set(LIB_CMAKE_TEMPLATE_MAIN_PROJECT OFF)
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  set(LIB_CMAKE_TEMPLATE_MAIN_PROJECT ON)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(LIB_CMAKE_TEMPLATE_MAIN_PROJECT)
    set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src/include)

add_subdirectory(src)
add_subdirectory(test)

install(EXPORT my_math-targets
        NAMESPACE MY_LIB::
        FILE my_math-targets.cmake
        DESTINATION lib/cmake/my_math )

include(CMakePackageConfigHelpers)

configure_package_config_file(
        ${CMAKE_CURRENT_LIST_DIR}/cmake/my_math-config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/my_math-config.cmake
        INSTALL_DESTINATION lib/cmake/my_math 
)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/my_math-config-version.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/my_math-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/my_math-config-version.cmake
        DESTINATION lib/cmake/my_math)

export(EXPORT my_math-targets
        NAMESPACE MY_LIB::
        FILE ${CMAKE_CURRENT_BINARY_DIR}/my_math-targets.cmake)