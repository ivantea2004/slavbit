
add_library(slavbit_ast
    statement_base.hpp
    statement_base.cpp
)

add_library(slavbit::ast ALIAS slavbit_ast)

target_link_libraries(slavbit_ast PUBLIC slavbit::core slavbit::lang)
