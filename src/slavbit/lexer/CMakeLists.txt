
add_library(slavbit_lexer
    token.hpp
    token.cpp
    token_stream.hpp
    token_stream.cpp
    control_sign.hpp
    control_sign.cpp

    unexpected_char_error.hpp
    unexpected_char_error.cpp
)

add_library(slavbit::lexer ALIAS slavbit_lexer)

target_link_libraries(slavbit_lexer PUBLIC slavbit::core slavbit::lang)
