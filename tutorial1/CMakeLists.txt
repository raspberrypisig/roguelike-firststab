include_directories(include)

add_executable(tutorial1
    main.cpp
    src/Engine.cpp
)

target_link_libraries(tutorial1
    PRIVATE libtcod::libtcod
)