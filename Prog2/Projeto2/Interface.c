//
// Created by sjoan on 24/08/2023.
//

#include "Interface.h"

/*
//Leitura
void leitura(FILE * arq,int i, Entrada entradas){
    usuario fraseS;
    while (!feof(arq)) {
        fseek(arq, i, SEEK_SET);
        fread(&fraseS, sizeof(fraseS), 1, arq);

        int resultado = strncmp(fraseS.login, entradas.loginn, sizeof(fraseS.login));
        if(resultado==0){
            int resultado_Senha = strncmp(fraseS.senha, entradas.senhaa, sizeof(fraseS.senha));
            if(resultado_Senha==0){
                Saudacoes(fraseS);
                exit(EXIT_FAILURE);
            }
            else{
                senha_incorreta();
                exit(EXIT_FAILURE);
            }
        }
        else{
            i = i + sizeof (fraseS);
        }
    }
}

//Função que calcula o tempo em segundos
void tempo(struct timeval inicio, clock_t start){
    clock_t end;
    double cpu_time_used;
    struct timeval fim;
    gettimeofday(&fim, 0);

    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;

    printf("Tempo gasto: %f segundos.\n", tempo_total);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo gasto de CPU: %f segundos.\n", cpu_time_used);
}

//Funções com os prints
void Saudacoes(usuario nomes){  printf("Ola %s\n",nomes.nome);}
void erro(){    printf("Usuario nao localizado\n");}
void senha_incorreta(){ printf("senha incorreta...\n");}*/