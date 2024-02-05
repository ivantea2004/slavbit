
add_library(slavbit_core
   compilation_error.hpp
   compilation_error.cpp
   source_code.hpp
   source_code.cpp
   diagnostic_stream.hpp
   diagnostic_stream.cpp
)

add_library(slavbit::core ALIAS slavbit_core)

target_compile_features(slavbit_core PUBLIC cxx_std_20)
target_include_directories(slavbit_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../)
