file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp)
file(GLOB_RECURSE INCL_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/**/.h)
add_library(utils SHARED ${INCL_FILES} ${SRC_FILES})
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(utils PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
