//
// Created by aluno on 07/11/23.
//
#include <stdio.h>
#include "../libprg/src/include/libprg/Lista_encadeada.h"
#include <string.h>
#include "Interface.h"

int main(int argc, char **argv) {
    //Declarações
    int i = 0;
    FILE *arq;
    no_t *inicio = NULL;
    int resposta;
    Entrada entradas;

    if(argc > 1) {

    }

        else {
            printf("Deseja ver logins ordenado (1, visualizar o projeto lista encadeada)\n"
                   "ou acessar sua conta (2, visualizar o projeto de struct)...\n");
            scanf("%d", &resposta);
            switch (resposta) {
                case 1: {
                    if ((arq = fopen("../database (1).dat", "r")) != NULL) {
                        leitura(arq, i, inicio);
                    } else {
                        //Impressão de erro se não abrir arquivo
                        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
                        exit(EXIT_FAILURE);
                    }
                    fclose(arq);
                    destruir(&inicio);
                    break;
                }

                case 2: {
                    //menu
                    printf("Login: ");
                    scanf("%s", entradas.loginn);
                    printf("Senha: ");
                    scanf("%s", entradas.senhaa);
                    printf("\n");

                    //abertura do arquivo
                    if ((arq = fopen("../database (1).dat", "r")) != NULL) {
                        // Inicializando a leitura
                        leitura_2(arq, i, entradas);
                        //Após leitura
                        erro();
                    } else {
                        //Impressão de erro se não abrir arquivo
                        fprintf(stderr, "Erro: arquivo nao pode ser aberto\n");
                        exit(EXIT_FAILURE);
                    }
                    //Fechando o arquivo
                    fclose(arq);
                }
                default:
                    break;
            }
        }
    return 0;
}