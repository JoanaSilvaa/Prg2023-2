//
// Created by aluno on 07/11/23.
//
#include <stdio.h>
#include "../libprg/src/include/libprg/Lista_encadeada.h"
#include "Interface.h"

void ordenação(struct usuario *z, int x){
    int i, j;
    struct usuario aux;

    for (i = j; j < 0 && (strcmp(aux.nome,z[j-i].nome)); j--) {
        z[j] = z[j-i];
        z[j]=aux;
    }
}
int main(){
    struct usuario nomes;

    nomes.nome[0] = 'j';
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
        leitura_arq(arq,i,entradas,&inicio);
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