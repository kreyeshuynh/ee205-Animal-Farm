cmake_minimum_required(VERSION 3.22)
project(ee205-Animal-Farm
        VERSION 3.0
        DESCRIPTION "All animals are equal"
        LANGUAGES CXX )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(ee205-Animal-Farm main.cpp Cat.cpp Cat.h Animal.cpp Animal.h config.h Weight.cpp Weight.h Color.h Node.cpp Node.h SinglyLinkedList.cpp SinglyLinkedList.h List.cpp List.h Gender.h Mammal.cpp Mammal.h)