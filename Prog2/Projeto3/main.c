#include <stdio.h>
#include "../libprg/src/include/libprg/tabela.h"
#include "Inteface.h"

int main(int argc, char **argv) {

    FILE *arq;
    usuario entradas;


    printf("Login: ");
    scanf("%s", entradas.login);
    printf("\n");
    printf("Senha: ");
    scanf("%s", entradas.senha);
    printf("\n");
    dicionario_t *dicionario = criar_dicionario(5);

    if (dicionario == NULL) {
        printf("Não foi possível reservar memória\n");
        exit(EXIT_FAILURE);
    }


    if ((arq = fopen("../database (1).dat", "r")) != NULL){
        //leitura

    }
    else {
        //Impressão de erro se não abrir arquivo
        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
        exit(EXIT_FAILURE);
    }
    fclose(arq);


    return 0;
}