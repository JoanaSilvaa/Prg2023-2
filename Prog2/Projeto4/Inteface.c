//
// Created by aluno on 08/12/23.
//

#include "Inteface.h"
#include "../libprg/src/include/libprg/arvore.h"

void leitura_tabela_hash(FILE * arq,int i) {
  //criar arvore
    usuarios entradas;
    //enquanto o arquivo não estiver chego no fim
    while (!feof(arq)) {
        //Reposiciona o indicador de posição do fluxo em função do deslocamento
        //inciciada em 0
        fseek(arq, i, SEEK_SET);
        fread(&entradas, sizeof(entradas), 1, arq);
        //inserir na arvore
    }
    //buscar na arvore
}