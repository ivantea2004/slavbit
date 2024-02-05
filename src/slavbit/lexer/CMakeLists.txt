
add_library(slavbit_lexer
    token.hpp
    token.cpp
    token_stream.hpp
    token_stream.cpp
    control_sign.hpp
    control_sign.cpp
)

add_library(slavbit::lexer ALIAS slavbit_lexer)

target_link_libraries(slavbit_lexer PUBLIC slavbit::core slavbit::lang)
