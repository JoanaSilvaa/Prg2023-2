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
    }
}
int buscar_a(dicionario_t *dicionario, usuario entradas){
    int aux = 0;
    pessoa_t *p = buscar_hash_lista_encadeada(dicionario,entradas.login);
    if (p != 0) {
        if(aux == strncmp(entradas.senha, p->b, sizeof(entradas.senha))){
            printf("Ola %s\n",p->c);
        }
        else{
            printf("Senha invalida\n");
        }
    } else {
        printf("Login %s nao encontrado\n", entradas.login);
    }
}
