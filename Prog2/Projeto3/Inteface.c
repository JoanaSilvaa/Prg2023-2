//
// Created by lenit on 28/11/2023.
//

#include "Inteface.h"

void leitura_tabela_hash(FILE * arq,int i,dicionario_t *d){
    usuario usuarios;
    while (!feof(arq)) {
        fseek(arq, i, SEEK_SET);
        fread(&usuarios, sizeof(usuarios), 1, arq);
        pessoa_t *p = malloc(sizeof(pessoa_t));
        p->a= strdup(usuarios.login);
        p->b = strdup(usuarios.senha);
        p->c = strdup(usuarios.nome);
        inserir_Lista_encadeada(d, p->a, p);
        i = i + sizeof (usuarios);
        //imprimir_pessoa(d, usuarios.login);
    }
}