
add_subdirectory(core)
add_subdirectory(lang)
add_subdirectory(lexer)
add_subdirectory(ast)
add_subdirectory(parser)

add_executable(slavbit
    main.cpp
)

target_link_libraries(slavbit PRIVATE slavbit::parser slavbit::ast)
