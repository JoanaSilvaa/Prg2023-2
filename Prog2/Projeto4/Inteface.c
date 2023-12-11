//
// Created by aluno on 08/12/23.
//

#include "Inteface.h"

void leitura_arv(FILE * arq,int i, no_t Raiz,usuarios entrada) {
    usuarios entradas;
    //enquanto o arquivo não estiver chego no fim
    while (!feof(arq)) {
        //Reposiciona o indicador de posição do fluxo em função do deslocamento
        //inciciada em 0
        fseek(arq, i, SEEK_SET);
        fread(&entradas, sizeof(entradas), 1, arq);
         inserir_valor_string(&Raiz,entradas);
        i = i + sizeof (entradas);
    }

    busca_s(&Raiz, entrada);

    if(buscar_arv(entrada,&Raiz) == 0){
        printf("Login nao encontrado");
    } else {
        if(strncmp(entradas.senha, entrada.senha, sizeof(entradas.senha)) == 0){
            printf("Ola %s", entradas.nome);
        } else{
            printf("Senha invalida");
        }
    }
    destruir_no_arv(&Raiz);
}

int buscar_arv(usuarios entradas, no_t *Raiz){
    int r =busca_string(Raiz, entradas);
    return r;
}
