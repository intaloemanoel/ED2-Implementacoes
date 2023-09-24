#include "hash.h"
#include <string.h>
#include <stdlib.h>

int funcao_hash(int chave, int tamanho){
    return chave % tamanho;
}

// vou ficar devendo essa tambem mas podemos pegar no trabalho de alc ou metodos
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

TabelaHash* insere_cliente_na_tabela_hash(TabelaHash* tabelaHash, Cliente cliente) {
    TabelaHash tabelaTemp;
    tabelaTemp = *tabelaHash;

    int resultadoFuncaoHash;
    resultadoFuncaoHash = funcao_hash(cliente.cod, tabelaTemp.tamanho);

    Elemento* elementoAtual;
    elementoAtual = &tabelaTemp.elementos[resultadoFuncaoHash];

    while {
        if ((*elementoAtual).proximo == NULL) {
            (*elementoAtual).proximo = &Elemento {
                proximo: NULL;
                cliente: cliente
            };
            break;
        } else {
            elementoAtual = (*elementoAtual).proximo;
        }
    }
    return tabelaTemp;
}