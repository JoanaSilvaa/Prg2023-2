//
// Created by sjoan on 04/11/2023.
//
#include "../include/libprg/Lista_encadeada.h"

void adicionar(no_t** inicio, int dado){
    no_t* novo = (no_t*) malloc(sizeof (no_t));
    novo->dado = dado;
    novo->proximo = *inicio;
    *inicio = novo;
}
// buscar por dados

//BUSCA NÃO ORDENADA
no_t* buscar(no_t** inicio, int dado){
    //no_t atual = *inicio;
    no_t* atuall = *inicio;
    while(atuall != NULL){
        printf("end: %p => %d\n",atuall,atuall->dado);
        if(atuall->dado == dado){
            printf("achou");
        }
        else{
            atuall = atuall->proximo;
        }
    }
}
bool remover(no_t** inicio, int dado){
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    while(atual != NULL){
        if (atual->dado == dado){
            if (anterior == NULL) {
                *inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}
void destruir(no_t** inicio){
    no_t* atual = *inicio;
    no_t* prox;
    while(atual != NULL){
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *inicio = NULL;
}
