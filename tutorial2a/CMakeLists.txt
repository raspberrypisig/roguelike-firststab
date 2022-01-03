include_directories(include)

add_executable(tutorial2a
    main.cpp
    src/Entity.cpp
    src/Engine.cpp
    src/Context.cpp
)

target_link_libraries(tutorial2a
    PRIVATE libtcod::libtcod
)

add_dependencies(tutorial2a copy_assets)
