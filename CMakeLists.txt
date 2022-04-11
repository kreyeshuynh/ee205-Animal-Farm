cmake_minimum_required(VERSION 3.22)
project(ee205_lab10d_animal_farm_2
        VERSION 2.0
        DESCRIPTION "All animals are equal"
        LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(ee205_lab8d-animal-farm1-to-clion main.cpp catDatabase.cpp catDatabase.h addCats.cpp addCats.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h Cat.cpp Cat.h)