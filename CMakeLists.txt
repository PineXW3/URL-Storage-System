cmake_minimum_required(VERSION 3.31)
project(URL_Storage C)

set(CMAKE_C_STANDARD 23)

add_executable(URL_Storage main.c
        linked_list.h
        linked_list.c
        hashtable.h
        hashtable.c
        storage.h
        storage.c
)
