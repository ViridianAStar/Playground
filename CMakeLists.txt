cmake_minimum_required(VERSION 4.1)
project(Playground)

set(CMAKE_CXX_STANDARD 23)

add_executable(Playground main.cpp
        Tree_Like/trie_tree_wordlike.cpp
        Tree_Like/trie_tree_wordlike.h
        Tree_Like/node_specs/ttw_node.cpp
        Tree_Like/node_specs/ttw_node.h)
