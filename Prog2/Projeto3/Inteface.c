//
// Created by lenit on 28/11/2023.
//

#include "Inteface.h"


void leitura_tabela_hash(FILE * arq,int i,dicionario_t *d){
    usuario usuarios;
    //enquanto o arquivo não estiver chego no fim
    while (!feof(arq)) {
        //Reposiciona o indicador de posição do fluxo em função do deslocamento
        //inciciada em 0
        fseek(arq, i, SEEK_SET);
        fread(&usuarios, sizeof(usuarios), 1, arq);
        //cria o no
        pessoa_t *p = malloc(sizeof(pessoa_t));
        //atribui a infomação ao no
        p->a= strdup(usuarios.login);
        p->b = strdup(usuarios.senha);
        p->c = strdup(usuarios.nome);
        //insere na tabela pela chave
        inserir_Lista_encadeada(d, p->a, p);
        //incrementa o i, que é usado como indicador
        i = i + sizeof (usuarios);
    }
}
void buscar_a(dicionario_t *dicionario, usuario entradas){
    //cria um inteiro auxiliar
    int aux = 0;
    //busca a chave na tabela hash se não encontrar a chave printa que o login não foi encontrado
    pessoa_t *p = buscar_hash_lista_encadeada(dicionario,entradas.login);
    if (p != 0) {
        //compara a senha associada a chave com a senha digitada, se errada imprime erro
        //se correta da as saldações
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
//faz a mesma coisa que o a só que com os parametros digitados via linha de comando
void buscar_b(dicionario_t *dicionario, parametro entradas){
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
