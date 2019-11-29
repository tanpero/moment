cmake_minimum_required (VERSION 3.0)
project (moment)

add_sublibrary (deps/date)
add_sublibrary (deps/fmt)

add_library (moment STATIC
    "src/moment.hh"
    "src/moment.cc"
    "tests/main.cc"
)

set_property (TARGET moment PROPERTY CXX_STANDARD 17)

target_include_directories (moment PUBLIC src)

add_executable(moment-test test/main.cc)
target_include_directories (moment-test PUBLIC src)
target_link_libraries (moment-test moment)
