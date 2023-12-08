//
// Created by aluno on 08/12/23.
//

#ifndef PROG2_INTEFACE_H
#define PROG2_INTEFACE_H

#include "Inteface.h"
#include "../libprg/src/include/libprg/arvore.h"

typedef struct usuarios{
    char login;
    char nome;
    char senha;
}usuarios ;

void leitura_arv(FILE * arq,int i, no_t Raiz);
void buscar_arv(usuarios entradas, no_t *Raiz);

#endif //PROG2_INTEFACE_H
