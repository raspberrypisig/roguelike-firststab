include_directories(include)

add_executable(tutorial3
    main.cpp
    src/Context.cpp
    src/Engine.cpp
    src/Entity.cpp
)

target_link_libraries(tutorial3
    PRIVATE libtcod::libtcod
)

add_dependencies(tutorial3 copy_assets)
