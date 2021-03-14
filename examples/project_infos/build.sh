#!/usr/bin/env sh

clang++ -I../../include/ project_infos.cpp  -o project_info

# valgrind ./project_info