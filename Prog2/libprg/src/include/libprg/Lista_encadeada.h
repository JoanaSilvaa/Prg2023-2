//
// Created by sjoan on 04/11/2023.
//

#ifndef PROG2_LISTA_ENCADEADA_H
#define PROG2_LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no{
    int dado;
    struct no* proximo;
} no_t;

void adicionar(no_t** inicio, int dado);
bool remover(no_t** inicio, int dado);
void destruir(no_t** inicio);
int buscar(no_t** inicio, int dado);
no_t* imprime(no_t** inicio);
int tamanho_no_t (no_t** inicio);


int adicionar_ordenada(no_t** inicio, int dado);
int remover_ordenada(no_t** inicio, int dado);

void tempo(clock_t start,struct timeval inicio);
void countingSort(int aux[], int n);
#endif //PROG2_LISTA_ENCADEADA_H
