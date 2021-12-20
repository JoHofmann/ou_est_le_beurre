# --- add headers for IDE support ---
message(${ouEstLeBeurre_SOURCE_DIR})
set(HEADER_LIST "${ouEstLeBeurre_SOURCE_DIR}/include/ou_est_le_beurre/")

# --- add libraries ---
add_library(ouEstLeBeurreLib
        Game.cpp
        GameObjects/Player.cpp
        GameObjects/Textbox.cpp
        GameObjects/GameObject.cpp
        utils.cpp
        StateMachine/State.cpp
        StateMachine/TestState.cpp
        ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(ouEstLeBeurreLib PUBLIC ../include)

target_link_libraries(ouEstLeBeurreLib PUBLIC sfml-graphics sfml-audio)

# This depends on (header only) boost
#target_link_libraries(quaternionDmp PRIVATE Boost::boost)

# All users of this library will need at least C++11
target_compile_features(ouEstLeBeurreLib PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})


