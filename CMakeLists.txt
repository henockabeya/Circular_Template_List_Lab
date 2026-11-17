cmake_minimum_required(VERSION 4.3)
project(Circular_Template_List_Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(Circular_Template_List_Lab main.cpp
        LinkedList.h
        LinkedList.cpp
        Song.h
        Podcast.h
        Media.cpp
        Media.h
        Podcast.cpp
        Song.cpp)
