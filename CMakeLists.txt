cmake_minimum_required(VERSION 3.10)
project(TradingTestHarness)

set(CMAKE_CXX_STANDARD 17)

# Include Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(trading_tests tests/test_engine.cpp)
target_link_libraries(trading_tests gtest_main)
include(GoogleTest)
gtest_discover_tests(trading_tests)
