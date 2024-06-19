cmake_minimum_required(VERSION 3.20)

project(breakpad_example LANGUAGES C CXX)

find_package(unofficial-breakpad CONFIG REQUIRED)

set(SOURCES src/main.cpp)
add_executable(breakpad_example ${SOURCES})
target_link_libraries(breakpad_example
  PRIVATE
    unofficial::breakpad::libbreakpad
    unofficial::breakpad::libbreakpad_client
)
