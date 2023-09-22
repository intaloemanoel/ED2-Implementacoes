#include "hash.h"
#include <string.h>
#include <stdlib.h>

int funcao_hash(int chave, int tamanho){
    return chave % tamanho;
}

TabelaHash* cria_tabela(int tamanho){
    TabelaHash* tabela;
    struct elemento *tabela[10];
    tabela = (TabelaHash*) malloc(sizeof(TabelaHash));
    //???????????????? me perdi aqui

    for(int i = 0; i < tamanho; i++){
        tabela[i] = NULL;//-1 significa que nao tem um registro na posicao i do vetor.
    }

    return tabela;
}