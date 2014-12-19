# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (sc)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set (CMAKE_C_FLAGS "${CMAKE_ANSI_CFLAGS} ${CMAKE_C_FLAGS} -std=c99")

include_directories(${CMAKE_SOURCE_DIR})


# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
#target_include_directories (Hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set(BASE utils/net.c utils/error.c)

remove_definitions(-DGC -DVALIDATOR)
add_definitions(-DGC)
add_executable (test_halfgate
   test/test_sc_and.c
   utils/simd.c
   circuits/int_circuits.c
   gc/halfgate/gc.c
   )
remove_definitions(-DGC -DVALIDATOR)

add_definitions(-DGC)
add_executable (test_simd
   test/test_simd.c
   utils/simd.c
   )
remove_definitions(-DGC -DVALIDATOR)


add_definitions(-DGC)
add_executable (test_xor
   circuits/int_circuits.c
   validator/validator.c
   test/test_xor.c
   )
remove_definitions(-DGC -DVALIDATOR)

add_definitions(-DGC)
add_executable (test_and
   circuits/int_circuits.c
   validator/validator.c
   test/test_and.c
   )
remove_definitions(-DGC -DVALIDATOR)


add_executable (test_network
   test/test_network.c
   ${BASE}
   )

add_executable (test_server
   test/test_networks.c
   )

add_executable (test_client
   test/test_networkc.c
   )


remove_definitions(-DGC -DVALIDATOR)
add_definitions(-DGC)
add_executable (test_add
   circuits/int_circuits.c
   validator/validator.c
   test/test_add.c
   utils/converter.c
   )
