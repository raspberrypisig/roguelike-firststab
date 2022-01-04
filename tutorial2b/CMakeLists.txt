include_directories(include)

add_executable(tutorial2b
    main.cpp
    src/Entity.cpp
    src/Engine.cpp
    src/Context.cpp
)

target_link_libraries(tutorial2b
    PRIVATE libtcod::libtcod
)

add_dependencies(tutorial2b copy_assets)
