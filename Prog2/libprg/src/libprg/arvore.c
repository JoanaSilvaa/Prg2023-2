//
// Created by aluno on 08/12/23.
//
#include "../include/libprg/arvore.h"

//função que cria no para valores inteiros
no_t *criar_no(int valor){
    //aloca a memoria
    no_t *no = (no_t*) malloc(sizeof(no_t));
    //o novo no recebe o valor recebido por parametro da função
    no->valor = valor;
    //e os no da direita e da esquerda sao Nulos
    no->esquerda = no->direita = NULL;
    //retorna o no
    return no;
}
//função que cria no para valores da struct usuarios
no_t *criar_no_string(usuarios valor){
    //aloca a memoria
    no_t *no = (no_t*) malloc(sizeof(no_t));
    //o novo no recebe o valor recebido por parametro da função
    //assim como os demais valores da struct
    for (int i = 0; i < sizeof(no->valore); ++i) {
        no->valore[i] = valor.login[i];
        no->senha[i] = valor.senha[i];
    }
    for (int i = 0; i < sizeof(no->nome); ++i) {
        no->nome[i] = valor.nome[i];
    }
    //e os nós da direita e da esquerda sao Nulos
    no->esquerda = no->direita = NULL;
    //retorna o no
    return no;
}
//função que destri todos os nós e
void destruir_no_arv(no_t *no) {
    //enquanto os nos não forem Nulos
    if (no != NULL) {
    destruir_no_arv(no->esquerda);
    destruir_no_arv(no->direita);
    //desaloca um bloco de memória
    free(no);
    }
}
// todo nó é raiz de uma subárvore
no_t *inserir_valor(no_t *raiz, int valor){
    //quando encontrar a raiz nula cria novo no
    if (raiz == NULL) {
        return criar_no(valor);
    //se o valor passado como parametro para inserir for menor chama a função inserir novamente pelo no da esquerda
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    //se o valor passado como parametro para inserir for maior chama a função inserir pelo no da direita
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    //retorna a raiz
    return raiz;
}

// todo nó é raiz de uma subárvore
no_t *inserir_valor_string(no_t *raiz, struct usuarios valor){
    //quando encontrar a raiz nula cria novo no
    if (raiz == NULL) {
        return criar_no_string(valor);
    //se o valor passado como parametro para inserir for menor chama a função inserir novamente pelo no da esquerda
    //A função strcmp compara duas strings e devolve um valor inteiro que lhe diz qual das strings vem antes no código ASCII
    } else if (strcmp(valor.login, raiz->valore) < 0) {
        raiz->esquerda = inserir_valor_string(raiz->esquerda, valor);
    //se o valor passado como parametro para inserir for maior chama a função inserir pelo no da direita
    } else if (strcmp(valor.login, raiz->valore) > 0) {
        raiz->direita = inserir_valor_string(raiz->direita, valor);
    }
    //retorna a raiz
    return raiz;
}


bool busca(no_t *raiz, int valor){
    //se chegou na raiz nula e não encontrou o valor retorna falso
    if (raiz == NULL) return false;
    //se encontra o valor retorna verdadeiro
    if (valor == raiz->valor) return true;
    //se o valor passado como parametro para busca for menor que o valor da raiz, busca novamente pelo nó da esquerda
    if (valor < raiz->valor) return busca(raiz->esquerda, valor);
    //se nao busca novamente pelo nó da direita
    return busca(raiz->direita, valor);
}

int busca_string(no_t *raiz, usuarios valor){
    //se chegou na raiz nula e não encontrou o valor retorna que o usuario não foi encontrado
    if (raiz == NULL){
        printf("Usuario nao localizado");
        return 1;
    }
    //se encontra o valor verifica a senha
    //A função strcmp compara duas strings e devolve um valor inteiro que lhe diz qual das strings vem antes no código ASCII
    //e se for igual a 0, são iguais
    if (strcmp(valor.login,raiz->valore) == 0){
        //se encontra a senha retorna o nome
        //se não, senha invalida
        if(strcmp(valor.senha,raiz->senha) == 0){
            printf("Ola %s", raiz->nome);
            return 0;
        } else{
            printf("Senha invalida");
            return 0;
        }
    }
    //se o valor passado como parametro para busca for menor que o valor da raiz, busca novamente pelo nó da esquerda
    if (strcmp(valor.login,raiz->valore) < 0)return busca_string(raiz->esquerda, valor);

    //se nao busca novamente pelo nó da direita
    return busca_string(raiz->direita, valor);
}



