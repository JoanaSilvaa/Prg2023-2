cmake_minimum_required(VERSION 3.23.2)
project(Prog2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Prog2 main2.c
        ../libprg/src/include/libprg/Fila_linear.h
        ../libprg/src/include/libprg/Lista_linear.h
        ../libprg/src/include/libprg/Pilha.h
        ../libprg/src/libprg/Pilha.c
        ../libprg/src/libprg/Fila_linear.c RPN.c RPN.h
        ../Projeto1/main.c)