//
// Created by aluno on 08/12/23.
//

#ifndef PRG2023_2_ARVORE_H
#define PRG2023_2_ARVORE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} no_t;

no_t *criar_no(int valor);
void destruir_no_arv(no_t *no);
no_t *inserir_valor(no_t *raiz, int valor);
no_t *inserir_valor_string(no_t *raiz, char valor);
bool busca(no_t *raiz, int valor);

#endif //PRG2023_2_ARVORE_H
