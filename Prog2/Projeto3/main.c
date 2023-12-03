#include <stdio.h>
#include "../libprg/src/include/libprg/tabela.h"
#include "Inteface.h"

int main(int argc, char **argv) {

    FILE *arq;
    usuario entradas;
    parametro entrada;
    dicionario_t *dicionario = criar_dicionario(50);
    int i = 0;

    //Quando forem enviados parâmetros adicionais (argc maior que 1), a aplicação não deve mais solicitar do usuário a
    // digitação do login e senha, fazendo a consulta e encerrando a aplicação assim que concluir este processo
    // (resultar em uma resposta após encontrar um login ou percorrer toda a lista sem encontrar,
    // encerrando o aplicativo ao fim da busca).
    if(argc > 1){
        entrada.login= argv[1];
        entrada.senha= argv[2];

        //Mensagem em casos que não é possivel alocar memoria
        if (dicionario == NULL) {
            printf("Não foi possível reservar memória\n");
            exit(EXIT_FAILURE);
        }
        //Abertura do arquivo e mensagem quando não é possivel abrir arquivo
        if ((arq = fopen("../database (1).dat", "r")) != NULL) {
            leitura_tabela_hash(arq, i, dicionario);
        } else {
            fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
            exit(EXIT_FAILURE);
        }
        //busca no dicionario pelo ponteiro
        buscar_b(dicionario, entrada);

    }
    else {
        // a interface deve solicitar que o usuário digite o login, depois a senha, realizando a busca pelo usuário após
        // obter estes dois parâmetros.
        printf("Login: ");
        scanf("%s", entradas.login);
        printf("\n");
        printf("Senha: ");
        scanf("%s", entradas.senha);
        printf("\n");

        //Mensagem em casos que não é possivel alocar memoria
        if (dicionario == NULL) {
            printf("Não foi possível reservar memória\n");
            exit(EXIT_FAILURE);
        }
        //Abertura do arquivo e mensagem quando não é possivel abrir arquivo
        if ((arq = fopen("../database (1).dat", "r")) != NULL) {
            leitura_tabela_hash(arq, i, dicionario);
        } else {
            fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
            exit(EXIT_FAILURE);
        }

        //busca no dicionario pelo que foi digitado
        buscar_a(dicionario, entradas);

    }

    //fechamento do arquivo
    fclose(arq);
    //desstruição da tabela Hash
    destruir_dicionario_lista_encadeada(dicionario);

    return 0;
}