
add_library(slavbit_lang
    identifier_base.hpp
    identifier_base.cpp
)

add_library(slavbit::lang ALIAS slavbit_lang)

target_link_libraries(slavbit_lang PUBLIC slavbit::core)
