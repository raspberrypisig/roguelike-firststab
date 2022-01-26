include_directories(include)

add_executable(tutorial3d
    main.cpp
    src/Context.cpp
    src/Engine.cpp
    src/Entity.cpp
    src/Rectangle.cpp
    src/Map.cpp
    src/MapGenerator.cpp
)

target_link_libraries(tutorial3d
    PRIVATE libtcod::libtcod
)

add_dependencies(tutorial3d copy_assets)
