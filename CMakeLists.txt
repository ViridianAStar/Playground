cmake_minimum_required(VERSION 4.1)
project(Playground)

set(CMAKE_CXX_STANDARD 23)

add_executable(Playground main.cpp
        Tree_Like/automaton_like_trie.cpp
        Tree_Like/automaton_like_trie.h
        includes.h)
