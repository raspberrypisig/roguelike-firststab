include_directories(include)

add_executable(tutorial2c
    main.cpp
    src/Entity.cpp
    src/Engine.cpp
    src/Context.cpp
)

target_link_libraries(tutorial2c
    PRIVATE libtcod::libtcod
)

add_dependencies(tutorial2c copy_assets)
