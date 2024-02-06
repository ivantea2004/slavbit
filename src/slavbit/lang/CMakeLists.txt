
add_library(slavbit_lang
    identifier_base.hpp
    identifier_base.cpp
    scope_identifier.hpp
    scope_identifier.cpp
    scope.hpp
    scope.cpp
    type_identifier.hpp
    type_identifier.cpp
    function_identifier.hpp
    function_identifier.cpp
    variable_identifier.hpp
    variable_identifier.cpp

    type_base.hpp
    type_base.cpp
    named_type.hpp
    named_type.cpp
    function_type.hpp
    function_type.cpp

    global_scope.hpp
    global_scope.cpp

    operator.hpp
    operator.cpp
)

add_library(slavbit::lang ALIAS slavbit_lang)

target_link_libraries(slavbit_lang PUBLIC slavbit::core)
