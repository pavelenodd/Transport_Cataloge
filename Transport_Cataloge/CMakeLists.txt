cmake_minimum_required(VERSION 3.5)

project(Transport_Cataloge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Transport_Cataloge
    main.cpp
    geo.h
    input_reader.cpp
    input_reader.h
    stat_reader.cpp
    stat_reader.h
    transport_catalogue.cpp
    transport_catalogue.h
    )
