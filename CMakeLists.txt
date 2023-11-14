cmake_minimum_required(VERSION 3.26)
project(WildCard)

set(CMAKE_CXX_STANDARD 17)

add_executable(WildCard main.cpp
        Card.cpp
        Card.h
        CardDeck.h
        Player.cpp
        Player.h)
