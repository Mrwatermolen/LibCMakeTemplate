add_library(my_add OBJECT my_add.cpp)

set(ALL_OBJECT_FILES ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:my_add> PARENT_SCOPE)