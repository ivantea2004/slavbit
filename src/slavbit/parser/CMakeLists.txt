
add_library(slavbit_parser
    type.hpp
    type.cpp

    expectable.hpp
    expectable.cpp
    unexpected_token_error.hpp
    unexpected_token_error.cpp
    undeclared_error.hpp
    undeclared_error.cpp
    unexpected_identifier_error.hpp
    unexpected_identifier_error.cpp
)

add_library(slavbit::parser ALIAS slavbit_parser)

target_link_libraries(slavbit_parser PUBLIC slavbit::core slavbit::ast slavbit::lexer)
