#include <stdio.h>
#include "Inteface.h"
#include <stdlib.h>
#include <string.h>

int main() {
    /*
    FILE *arq;
    int i =0;

    usuarios entradas;
    no_t *Raiz = criar_no_string('joana');

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
        leitura_arv(arq,i,*Raiz);
    } else {
        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
        exit(EXIT_FAILURE);
    }
    buscar_arv(entradas,Raiz);*/

    no_t *Raiz = criar_no_string('joana');

    inserir_valor_string(Raiz, 'bruno');
    inserir_valor_string(Raiz, 'jruo');
    inserir_valor_string(Raiz, 'orun');

    int r = busca_string(Raiz,'joana');
    printf("%d\n", r);

    r = busca_string(Raiz,'bruno');
    printf("%d\n", r);
    r = busca_string(Raiz,'jruo');
    printf("%d\n", r);
    r = busca_string(Raiz,'joana');
    printf("%d\n", r);

    destruir_no_arv(Raiz);


    r = busca_string(Raiz,'joana');
    printf("%d\n", r);

}
