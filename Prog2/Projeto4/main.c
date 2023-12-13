 #include <stdio.h>
#include "Inteface.h"
#include <stdlib.h>

// importada através de funcionalidade fetch content do CMake (estratégia do Professor Emerson).

int main() {

    FILE *arq;
    int i = 0;

    //Criação de um char, para usar como raiz
    struct usuarios teste1;
    teste1.login[0] = 'j';
    teste1.login[1] = 'o';
    teste1.login[2] = 'a';
    teste1.login[3] = 'n';
    teste1.login[4] = 'a';


    //declarando uma struct para receber as entradas
    usuarios entradas;
    //criando a Raiz
    no_t *Raiz = criar_no_string(teste1);

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
        //inicia a leitura do arquivo na interface.c
        leitura_arv(arq,i,*Raiz,entradas);
    } else {
        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
        exit(EXIT_FAILURE);
    }
}