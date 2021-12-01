cmake_minimum_required(VERSION 3.1)

project(ouEstLeBeurre)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_subdirectory(src)

# executable
add_executable(ouEstLeBeurre 
	app/main.cpp 
	src/Game.cpp 
	src/Player.cpp
	include/ou_est_le_beurre/Game.hpp 
	include/ou_est_le_beurre/Player.hpp 
	include/ou_est_le_beurre/globals.hpp
)

target_link_libraries(ouEstLeBeurre sfml-graphics sfml-audio ouEstLeBeurreLib)