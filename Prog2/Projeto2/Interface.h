//
// Created by joana on 24/08/2023.
//

#ifndef UNTITLED27_INTERFACE_H
#define UNTITLED27_INTERFACE_H

//Inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

//Estruturas
typedef struct usuario{
    char login[10];
    char senha[10];
    char nome[30];
} usuario;

typedef struct entrada{
    char loginn[10];
    char senhaa[10];
} Entrada;

//Definições das funções
void leitura(FILE * arq,int i, Entrada entradas);
//void tempo(struct timeval inicio, clock_t start);
void Saudacoes(usuario nomes);
void erro();
void senha_incorreta();

#endif //UNTITLED27_INTERFACE_H