#
#  Bartlomiej Kunikowski
#
#  Very simple caesar cipher decrypter and crypter program
#
#  Copyright (c) 2020 BartekkPL
#
#  This library is released under the MIT Licence.
#  https://github.com/BartekkPL/caesar-cipher/blob/master/LICENSE
#
#  https://github.com/BartekkPL/caesar-cipher

cmake_minimum_required (VERSION 3.16)
project (caesar-cipher VERSION 1.0.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

message (STATUS "Start of execution CMake for Caesar Cipher (De)crypter in "
                "version ${PROJECT_VERSION}"
        )

set (CAESAR_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    )

add_executable(${PROJECT_NAME} ${CAESAR_SOURCES})
