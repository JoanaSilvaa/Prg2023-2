//
// Created by aluno on 07/11/23.
//
#include <stdio.h>
#include "../libprg/src/include/libprg/Lista_encadeada.h"
#include <string.h>
#include "Interface.h"


void erro(){    printf("Usuario nao localizado\n");}

void leitura(FILE * arq,int i, Entrada entradas, no_t *inicio){
    tipo fraseS;
    while (!feof(arq)) {
        fseek(arq, i, SEEK_SET);
        fread(&fraseS, sizeof(fraseS), 1, arq);
        Compara(&inicio,fraseS);
    }
}

int main() {
    //Declarações
    int i = 0;
    FILE *arq;
    Entrada entradas;
    no_t *inicio = NULL;

    //menu
    printf("Login: ");
    scanf("%s", entradas.loginn);
    printf("Senha: ");
    scanf("%s", entradas.senhaa);
    printf("\n");

    //abertura do arquivo
    if ((arq = fopen("../database (1).dat", "r")) != NULL){
        // Inicializando a leitura
        leitura(arq, i, entradas, inicio);
        //void leitura(FILE * arq,int i, Entrada entradas, no_t *inicio)
        imprime_string(&inicio);
        //Após leitura
        erro();

    }
    else {
        //Impressão de erro se não abrir arquivo
        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}