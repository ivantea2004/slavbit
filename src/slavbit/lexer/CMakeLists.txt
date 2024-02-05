
add_library(slavbit_lexer
    token.hpp
    token.cpp
)

add_library(slavbit::lexer ALIAS slavbit_lexer)

target_link_libraries(slavbit_lexer PUBLIC slavbit::core)
