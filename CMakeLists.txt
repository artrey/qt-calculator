cmake_minimum_required(VERSION 3.5)

project(calculator LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(calculator
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    base_calculator.h
    base_calculator.cpp
    advanced_calculator.h
    advanced_calculator.cpp
    advanced_calculator.ui
    basic_calculator.h
    basic_calculator.cpp
    basic_calculator.ui
    programmer_calculator.cpp
    programmer_calculator.h
    programmer_calculator.ui
)

target_link_libraries(calculator PRIVATE Qt5::Widgets)
