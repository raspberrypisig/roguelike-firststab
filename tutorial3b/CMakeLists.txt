include_directories(include)

add_executable(tutorial3b
    main.cpp
    src/Context.cpp
    src/Engine.cpp
    src/Entity.cpp
    src/Rectangle.cpp
    src/Map.cpp
    src/MapGenerator.cpp
)

target_link_libraries(tutorial3b
    PRIVATE libtcod::libtcod
)

add_dependencies(tutorial3b copy_assets)
