add_executable(tutorial0
    main.cpp
)

target_link_libraries(tutorial0
    PRIVATE libtcod::libtcod
)