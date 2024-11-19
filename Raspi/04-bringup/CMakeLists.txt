cmake_minimum_required(VERSION 3.18)
project(DHT11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SOURCES
    "main.cpp"
    "csv/csv.cpp"
)

set(HEADERS
    "csv/csv.hpp"
    "read/read.hpp"
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
