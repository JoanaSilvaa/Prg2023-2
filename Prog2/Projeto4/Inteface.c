#include "Inteface.h"

//função leitura do arquivo, recebe como parametro o arquivo, um inteiro que vai conter a posiação
//que o indicador vai caminhar, a raiz iniciada com "JOANA"
void leitura_arv(FILE * arq,int i, no_t Raiz,usuarios entrada) {
    usuarios entradas;
    //enquanto o arquivo não estiver chego no fim
    while (!feof(arq)) {
        //Reposiciona o indicador de posição do fluxo em função do deslocamento
        //inciciada em 0
        fseek(arq, i, SEEK_SET);
        fread(&entradas, sizeof(entradas), 1, arq);
        //E insere a struct contendo todas as informações lida no arquivo
         inserir_valor_string(&Raiz,entradas);
         //inteiro contabiliza as informações lidas e atribui o valor da posição que vai deslocar
         i = i + sizeof (entradas);
    }
    //função que busca a entrada digitada pelo usuario
    buscar_arv(entrada,&Raiz);

    //função que destroi a arvore
    destruir_no_arv(&Raiz);

    //fecha o arquivo

}

int buscar_arv(usuarios entradas, no_t *Raiz){
    int r = busca_string(Raiz, entradas);
    return r;
}
