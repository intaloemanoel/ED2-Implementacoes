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
    int interacao;

    int resultadoFuncaoHash;
    resultadoFuncaoHash = funcao_hash(cliente.cod, tabelaTemp.tamanho);

    Elemento* elementoAtual;
    Elemento* novoElemento;
    elementoAtual = &tabelaTemp.elementos[resultadoFuncaoHash];

    interacao = 0;
    while {
        if (elementoAtual->proximo == NULL && interacao == 0) {
            novoElemento = &Elemento {
                proximo: NULL;
                cliente: cliente
            };
            elementoAtual = novoElemento;
            break;
        } else if (elementoAtual->proximo == NULL && interacao > 0) {
             elementoAtual->proximo = &Elemento {
                proximo: NULL
                cliente: cliente
             };
             break;
        } else {
            elementoAtual = elementoAtual->proximo;
            interacao = interacao + 1;
        }
    }
    return tabelaTemp;
}

Elemento* cria_elemento (void) {
    return NULL;
}


/* inserção no início: retorna a lista atualizada */
Elemento* insere_elemento (Elemento* elemento, Cliente cliente) {
    Elemento* novoElemento = (Elemento*) malloc(sizeof(Elemento));
    novoElemento->cliente = cliente;
    novoElemento->proximo = elemento;
    return novoElemento;
}