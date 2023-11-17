//
// Created by aluno on 07/11/23.
//
#include <stdio.h>
#include "../libprg/src/include/libprg/Lista_encadeada.h"
#include <string.h>
#include "Interface.h"

int compara_letra(struct tipo Nome, no_t *inicio){
    if(strncmp(Nome.dados, inicio->dados, sizeof(*inicio)) < 0) {
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
// inicio precisa ser um ponteiro
    no_t* inicio = NULL;
    struct tipo nome, nome2;
    nome.dados[0] = 'n';
    nome.dados[1] = 'o';
    nome.dados[2] = 'm';
    nome.dados[3] = 'e';

    nome2.dados[0] = 'v';
    nome2.dados[1] = 'b';
    nome2.dados[2] = 'h';
    nome2.dados[3] = 'a';

    for (int n = 0; n < 2 ; n++)
        if (strncmp (nome.dados,"nome",4) == 0)
        {
            printf ("Achou %s\n",nome.dados);
        } else {
            printf("Não achou\n");
        }

    int r = strncmp(nome.dados, nome2.dados, 4);
    printf("%d\n", r);

    if (strncmp(nome.dados, nome2.dados, 4) < 0) {
            printf("%s\n", nome.dados);
    } else if (strncmp(nome.dados, nome2.dados, 4) > 0) {
            printf("%s\n", nome2.dados);
    } else {
        printf("São iguais\n");
    }

    //Compara(&inicio, nome);
   // Compara(&inicio, nome2);

// listando
    //imprime_string(&inicio);

    //destruir(&inicio);
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