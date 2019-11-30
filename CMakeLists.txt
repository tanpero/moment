cmake_minimum_required (VERSION 3.0)
project (moment)

add_subdirectory (deps/date)
add_subdirectory (deps/fmt)

aux_source_directory (src/util SRC_UTIL_DIR)

add_library (moment STATIC
${SRC_UTIL_DIR}
    "src/moment.hh"
    "src/moment.cc"
)

set_property (TARGET moment PROPERTY CXX_STANDARD 17)

target_include_directories (moment PUBLIC src deps/fmt/include deps/date/include)

# Tests
# ==================================================
add_executable (moment-test tests/main.cc)
target_include_directories (moment-test PUBLIC src)


add_executable (moment.util-test tests/test-util.cc)
target_include_directories (moment.util-test PUBLIC src)

target_link_libraries (moment-test moment)
target_link_libraries (moment.util-test moment)
