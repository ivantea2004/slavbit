
add_library(slavbit_core
    diagnostic.hpp
    diagnostic.cpp
)

add_library(slavbit::core ALIAS slavbit_core)

target_compile_features(slavbit_core PUBLIC cxx_std_20)
