Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(ustd_tests
  expected.tests.cpp
)

set_target_properties(ustd_tests PROPERTIES CXX_STANDARD 17)

target_link_libraries(ustd_tests PRIVATE Catch2::Catch2WithMain ustd)

