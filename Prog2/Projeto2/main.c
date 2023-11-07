//
// Created by aluno on 07/11/23.
//
#include <stdio.h>
#include "../libprg/src/include/libprg/Lista_encadeada.h"

int main(){
// inicio precisa ser um ponteiro
    no_t* inicio = NULL;
// adicionando
    adicionar(&inicio, 1);
    adicionar(&inicio, 2);
    adicionar(&inicio, 3);
// removendo
    remover(&inicio, 2);
// listando
    no_t* atual = inicio;
    while(atual != NULL){
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\nend: %p = %d *\n",&inicio,inicio->dado);
    buscar(&inicio, 1);


    destruir(&inicio);

    return 0;
}