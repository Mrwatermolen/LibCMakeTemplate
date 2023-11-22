add_subdirectory(my_add)
add_subdirectory(my_sub)

add_library(my_math STATIC my_math.cpp ${ALL_OBJECT_FILES})

target_include_directories(my_math
        PUBLIC 
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_include_directories(my_math PRIVATE ${MY_MATH_LIB_INCLUDE_DIR})

# add the install targets to my_math-targets
install(TARGETS my_math
        EXPORT my_math-targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

# install the public header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/my_math DESTINATION include)
