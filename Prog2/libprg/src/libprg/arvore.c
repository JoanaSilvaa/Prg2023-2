//
// Created by aluno on 08/12/23.
//
#include "../include/libprg/arvore.h"

no_t *criar_no(int valor){
    no_t *no = (no_t*) malloc(sizeof(no_t));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

no_t *criar_no_string(char valor){
    no_t *no = (no_t*) malloc(sizeof(no_t));
    no->valore = valor;
    no->esquerda = no->direita = NULL;
    return no;
}
void destruir_no_arv(no_t *no) {
    if (no != NULL) {
    destruir_no_arv(no->esquerda);
    destruir_no_arv(no->direita);
    free(no);
    }
}
// todo nó é raiz de uma subárvore
no_t *inserir_valor(no_t *raiz, int valor){
    if (raiz == NULL) {
        return criar_no(valor);
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    return raiz;
}

// todo nó é raiz de uma subárvore
no_t *inserir_valor_string(no_t *raiz, char valor){
    if (raiz == NULL) {
        return criar_no_string(valor);
    } else if (strcmp(&valor, &raiz->valore) < 0) {
        raiz->esquerda = inserir_valor_string(raiz->esquerda, valor);
    } else if (strcmp(&valor, &raiz->valore) > 0) {
        raiz->direita = inserir_valor_string(raiz->direita, valor);
    }
    return raiz;
}


bool busca(no_t *raiz, int valor){
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca(raiz->esquerda, valor);
    return busca(raiz->direita, valor);
}

bool busca_string(no_t *raiz, char valor){
    if (raiz == NULL) return false;
    if (strcmp(&valor,&raiz->valore) == 0) return true;
    if (strcmp(&valor,&raiz->valore) < 0) return busca(raiz->esquerda, valor);
    return busca(raiz->direita, valor);
}