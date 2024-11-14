cmake_minimum_required(VERSION 3.22)
project(ControlGPIO)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SOURCES
    "main.cpp"
    "classes/Led/led.cpp"
    "classes/command/command.cpp"
    "classes/server/Server.cpp"
)

set(HEADERS
    "configrations.hpp"
    "classes/Led/led.hpp"
    "classes/command/command.hpp"
    "classes/server/Server.hpp"
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
