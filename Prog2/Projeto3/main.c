//
// Created by aluno on 21/11/23.
//
#include <stdio.h>
#include "../libprg/src/include/libprg/tabela.h"

int main(int argc, char **argv) {

    dicionario_t *dicionario = criar_dicionario(5);

    if (dicionario == NULL) {
        printf("Não foi possível reservar memória\n");
        exit(EXIT_FAILURE);
    }

    pessoa_t *p = malloc(sizeof(pessoa_t));
    // https://en.cppreference.com/w/c/string/byte/strdup
    // strdup reserva memória para fazer a cópia da string. Presente no padrão C23
    p->cpf = strdup("123");
    p->nome = strdup("Juca");
    p->email = strdup("juca@example.ogr");
    inserir(dicionario, p->cpf, p);
    imprimir_pessoa(dicionario, "123");
    destruir_dicionario(dicionario);

    return 0;
}