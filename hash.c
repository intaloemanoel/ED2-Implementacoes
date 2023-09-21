#include "hash.h"
#include <string.h>
#include <stdlib.h>

int funcao_hash(int chave, int tamanho){
    return chave % tamanho;
}

TabelaHash* cria_tabela(int tamanho){
    TabelaHash* tabela = (TabelaHash*) malloc(sizeof(TabelaHash));

    tabela->tamanho = tamanho;
    tabela->clientes = (Cliente*) malloc(sizeof(Cliente) * tamanho);

    for(int i = 0; i < tamanho; i++){
        tabela[i].chave = -1; //-1 significa que nao tem um registro na posicao i do vetor.
    }

    return tabela;
}