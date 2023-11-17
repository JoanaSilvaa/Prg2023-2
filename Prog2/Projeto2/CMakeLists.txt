cmake_minimum_required(VERSION 3.23.2)
project(Prog2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Prog2 main.c
        ../libprg/src/include/libprg/Fila_linear.h
        ../libprg/src/include/libprg/Lista_linear.h
        ../libprg/src/include/libprg/Pilha.h
        ../libprg/src/libprg/Pilha.c
        ../libprg/src/libprg/Fila_linear.c
        ../libprg/src/libprg/Lista_encadeada.c
        ../libprg/src/include/libprg/Lista_encadeada.h
        ../libprg/src/libprg/ContingSort.c
        ../libprg/src/include/libprg/Lista_encadeada.h
        Interface.h
        ../libprg/src/include/libprg/Lista_encadeada.h
)
