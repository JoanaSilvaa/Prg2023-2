//
// Created by sjoan on 24/08/2023.
//
#include "Interface.h"

//Leitura
void leitura(FILE * arq,int i, no_t *inicio, parametro entrada){
    tipo fraseS;
    while (!feof(arq)) {
        fseek(arq, i, SEEK_SET);
        fread(&fraseS, sizeof(fraseS), 1, arq);
        Compara(&inicio,fraseS);
        i = i + sizeof (fraseS);
    }
    if(buscar_lista_encadeada(&inicio,entrada.login) == -1){
        printf("Nao encontrado");
    } else{
        //verificar senha
    }
}

void leitura_imprime(FILE * arq,int i, no_t *inicio){
    tipo fraseS;
    while (!feof(arq)) {
        fseek(arq, i, SEEK_SET);
        fread(&fraseS, sizeof(fraseS), 1, arq);
        Compara(&inicio,fraseS);
        i = i + sizeof (fraseS);
    }
    imprime_string(&inicio);
}
void leitura_2(FILE * arq,int i, Entrada entradas){
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

//Funções com os prints
void Saudacoes(usuario nomes){  printf("Ola %s\n",nomes.nome);}
void erro(){    printf("Usuario nao localizado\n");}
void senha_incorreta(){ printf("senha incorreta...\n");}