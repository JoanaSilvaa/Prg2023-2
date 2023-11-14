//
// Created by aluno on 07/11/23.
//
#include <stdio.h>
#include "../libprg/src/include/libprg/Lista_encadeada.h"
#include "Interface.h"

int main() {

    //Declarações
    int i = 0;
    FILE *arq;
    entrada entradas;
    clock_t start;

    //menu
    printf("Login: ");
    scanf("%s", entradas.loginn);
    printf("Senha: ");
    scanf("%s", entradas.senhaa);
    printf("\n");

    //abertura do arquivo
    if ((arq = fopen("../database (1).dat", "r")) != NULL){
                // Inicializando a leitura
        Leitura(arq,i,entradas);
        //Após leitura
        erro();

    }
    else {
        //Impressão de erro se não abrir arquivo
        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
        exit(EXIT_FAILURE);
    }
    //Fechando o arquivo
    fclose(arq);
    return 0;
}