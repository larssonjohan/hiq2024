file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp)
file(GLOB_RECURSE INCL_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/**/.h)
add_library(lib SHARED ${INCL_FILES} ${SRC_FILES})
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(lib PRIVATE utils)

