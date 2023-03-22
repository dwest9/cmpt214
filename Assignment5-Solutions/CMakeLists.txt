project(treasure)

# The standards for our CMPT214 class
set( CMAKE_C_STANDARD 11)
set( CMAKE_C_FLAGS "-Wall -Wextra ")

# To create the static and dynamic versions of the rn library
add_library( rn SHARED rand_num.c )

# To create the treasure executable (dynamically-linked)
add_executable( treasure treasure.c field.c position.c )

# To link the librn library with the treasure target
target_link_libraries( treasure rn )
