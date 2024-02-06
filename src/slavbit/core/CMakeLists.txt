
add_library(slavbit_core
   assert.hpp
   assert.cpp
   source_code.hpp
   source_code.cpp
   line_iterator.hpp
   line_iterator.cpp
   location.hpp
   location.cpp
   diagnostic_stream.hpp
   diagnostic_stream.cpp
   diagnostic_message.hpp
   diagnostic_message.cpp
   code_error.hpp
   code_error.cpp
   syntax_error.hpp
   syntax_error.cpp
   lexical_error.hpp
   lexical_error.cpp
   unexpected_end_error.hpp
   unexpected_end_error.cpp
)

add_library(slavbit::core ALIAS slavbit_core)

target_compile_features(slavbit_core PUBLIC cxx_std_20)
target_include_directories(slavbit_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../)
