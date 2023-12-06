//Baseado na analise do tempo, pude observar que ele se comporta de maneira diferente de acordo com o tamanho do dicionario
//testei 3 tamanhos de dicionarios, de 5, 50 e 5000 que me levaram a concluir que nesse caso o melhor caso foi o de 50, cujo
//o valor é mais proximo do numero de usarios do arquivo base.
// O pior caso foi o de 5, onde as listas encadeadas ficaram maiores, aumentando de forma inversamente proporcional.
//
//Para essa analise foi usado o sistema operacional do linux, mas como não foram feitas multiplos testes, não consegui
// ter um resultado muito preciso.
//
//Em vista disso, coloquei a função de tempo disponibilizada pelo Emerson no inicio do semestre, usando o sistema operacional
//do windows (sistema que utilizo no meu computador pessoal), nesse caso o tempo se comportou de maneira parecida quando falamos
//de melhor caso, mas de maneira totalmente equivocada quando falamos de analise no tempo realmente.

#include <stdio.h>
#include "../libprg/src/include/libprg/tabela.h"
#include "Inteface.h"
#include <sys/time.h>

int main(int argc, char **argv) {

    FILE *arq;
    usuario entradas;
    parametro entrada;
    dicionario_t *dicionario = criar_dicionario(1);
    int i = 0;

    //Quando forem enviados parâmetros adicionais (argc maior que 1), a aplicação não deve mais solicitar do usuário a
    // digitação do login e senha, fazendo a consulta e encerrando a aplicação assim que concluir este processo
    // (resultar em uma resposta após encontrar um login ou percorrer toda a lista sem encontrar,
    // encerrando o aplicativo ao fim da busca).
    if(argc > 1){
        clock_t start, end;
        double cpu_time_used;

        // Iniciando tomada de tempo
        start = clock();


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

        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tempo gasto de CPU: %f segundos.\n", cpu_time_used);
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