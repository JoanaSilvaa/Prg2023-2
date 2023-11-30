#include <stdio.h>
#include "../libprg/src/include/libprg/tabela.h"
#include "Inteface.h"

int main(int argc, char **argv) {

    FILE *arq;
    usuario entradas;
    int i = 0;

    printf("Login: ");
    scanf("%s", entradas.login);
    printf("\n");
    printf("Senha: ");
    scanf("%s", entradas.senha);
    printf("\n");
    dicionario_t *dicionario = criar_dicionario(50);

    if (dicionario == NULL) {
        printf("Não foi possível reservar memória\n");
        exit(EXIT_FAILURE);
    }


    if ((arq = fopen("../database (1).dat", "r")) != NULL){
        leitura_tabela_hash(arq, i, dicionario);
    }
    else {
        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
        exit(EXIT_FAILURE);
    }

    if(buscar_hash_lista_encadeada(dicionario,entradas.login) != 0){

    }
    else{
        printf("Login %s ao encontrado\n",entradas.login);
    }
    fclose(arq);


    return 0;
}