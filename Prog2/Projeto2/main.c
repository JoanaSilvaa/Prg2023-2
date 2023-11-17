//
// Created by aluno on 07/11/23.
//
#include <stdio.h>
#include "../libprg/src/include/libprg/Lista_encadeada.h"
#include <string.h>
#include "Interface.h"

int main(){
// inicio precisa ser um ponteiro
    no_t* inicio = NULL;
    no_t nome, nome2, nome3;
    nome.dados = 'k';
    nome2.dados = 'l';
    nome3.dados = 'j';

// adicionando
    Compara(&inicio,nome);
    Compara(&inicio,nome2);
    Compara(&inicio,nome3);

// listando
    imprime_string(&inicio);

    destruir(&inicio);
    return 0;
}
/*
int main() {
    //Declarações
    int i = 0;
    FILE *arq;
    Entrada entradas;
    no_t** inicio;

    //menu
    printf("Login: ");
    scanf("%s", entradas.loginn);
    printf("Senha: ");
    scanf("%s", entradas.senhaa);
    printf("\n");

    //abertura do arquivo
    if ((arq = fopen("../database (1).dat", "r")) != NULL){
        // Inicializando a leitura
        leitura(arq,i,entradas);
        //Após leitura
        erro();

    }
    else {
        //Impressão de erro se não abrir arquivo
        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}*/