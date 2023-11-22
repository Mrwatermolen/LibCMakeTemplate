add_library(my_sub OBJECT my_sub.cpp)

set(ALL_OBJECT_FILES ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:my_sub> PARENT_SCOPE)