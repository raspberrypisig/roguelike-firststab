cmake_minimum_required(VERSION 3.10)
project (roguelike-firststab)
#add_subdirectory(cmake)
#print_all_variables()
find_package(libtcod CONFIG REQUIRED)
add_definitions(-DSDL_MAIN_HANDLED)

add_custom_target(copy_assets
  COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/cmake/copy-assets.cmake ${CMAKE_CURRENT_LIST_DIR}/data
)
add_subdirectory(tutorial0)
add_subdirectory(tutorial1)
add_subdirectory(tutorial2a)
add_subdirectory(tutorial2b)
add_subdirectory(tutorial2c)

