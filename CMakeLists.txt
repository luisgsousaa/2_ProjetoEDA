cmake_minimum_required(VERSION 3.27)
project(2_ProjetoEDA)

set(CMAKE_CXX_STANDARD 17)

add_executable(2_ProjetoEDA main.cpp
        estruturas.h
        estruturas.cpp
        funcoes.h
        funcoes.cpp
        ficheiros.h
        ficheiros.cpp
        simulacao.h
        simulacao.cpp)
