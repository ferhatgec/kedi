#!/usr/bin/env sh

clang++ -I../../include/ user_infos.cpp  -o user_info

# valgrind ./user_info
