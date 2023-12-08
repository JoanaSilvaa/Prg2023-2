#include <stdio.h>
#include "Inteface.h"
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq;

    usuarios entradas;

    // a interface deve solicitar que o usuário digite o login, depois a senha, realizando a busca pelo usuário após
    // obter estes dois parâmetros.
    printf("Login: ");
    scanf("%s", entradas.login);
    printf("\n");
    printf("Senha: ");
    scanf("%s", entradas.senha);
    printf("\n");


//Abertura do arquivo e mensagem quando não é possivel abrir arquivo
    if ((arq = fopen("../database (1).dat", "r")) != NULL) {
        //leitura
    } else {
        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
        exit(EXIT_FAILURE);
    }


}
