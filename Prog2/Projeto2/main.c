//
// Created by aluno on 07/11/23.
//
#include <stdio.h>
#include "../libprg/src/include/libprg/Lista_encadeada.h"

int main(){
// inicio precisa ser um ponteiro
    no_t* inicio = NULL;
// adicionando
    adicionar_ordenada(&inicio, 1);
    adicionar_ordenada(&inicio, 5);
    adicionar_ordenada(&inicio, 3);
// removendo
    remover(&inicio, 2);
// listando

    imprime(&inicio);

    buscar(&inicio, 1);

    destruir(&inicio);

    return 0;
}