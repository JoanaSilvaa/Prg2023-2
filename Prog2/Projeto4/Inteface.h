//
// Created by aluno on 08/12/23.
//

#ifndef PROG2_INTEFACE_H
#define PROG2_INTEFACE_H

#include <string.h>
#include "../libprg/src/include/libprg/arvore.h"

//As declações das bibliotecas foram feitas todas na arvore.c e importadas


//Declaração das funções
void leitura_arv(FILE * arq,int i, no_t Raiz,usuarios entrada);
int buscar_arv(usuarios entradas, no_t *Raiz);


#endif //PROG2_INTEFACE_H
