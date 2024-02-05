
add_library(slavbit_parser
    type.hpp
    type.cpp
)

add_library(slavbit::parser ALIAS slavbit_parser)

target_link_libraries(slavbit_parser PUBLIC slavbit::core slavbit::ast slavbit::lexer)
