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

no_t *criar_no_string(usuarios valor){
    no_t *no = (no_t*) malloc(sizeof(no_t));
    for (int i = 0; i < sizeof(no->valore); ++i) {
        no->valore[i] = valor.login[i];
        no->senha[i] = valor.senha[i];
    }
    for (int i = 0; i < sizeof(no->nome); ++i) {
        no->nome[i] = valor.nome[i];
    }
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
no_t *inserir_valor_string(no_t *raiz, struct usuarios valor){
    if (raiz == NULL) {
        return criar_no_string(valor);
    } else if (strcmp(valor.login, raiz->valore) < 0) {
        raiz->esquerda = inserir_valor_string(raiz->esquerda, valor);
    } else if (strcmp(valor.login, raiz->valore) > 0) {
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

int busca_string(no_t *raiz, usuarios valor){
    if (raiz == NULL){
        printf("Usuario nao localizado");
        return 1;
    }
    if (strcmp(valor.login,raiz->valore) == 0){
        if(strcmp(valor.senha,raiz->senha) == 0){
            printf("Ola %s", raiz->nome);
            return 0;
        } else{
            printf("Senha invalida");
            return 0;
        }
    }
    if (strcmp(valor.login,raiz->valore) < 0)
        return busca_string(raiz->esquerda, valor);

    return busca_string(raiz->direita, valor);
}



