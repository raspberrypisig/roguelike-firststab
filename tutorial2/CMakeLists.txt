include_directories(include)

add_executable(tutorial2
    main.cpp
    src/Engine.cpp
    src/Entity.cpp
    src/Context.cpp
)

target_link_libraries(tutorial2
    PRIVATE libtcod::libtcod
)


add_dependencies(tutorial2 copy_assets)
