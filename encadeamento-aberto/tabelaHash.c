#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

void imprimir_tabela(int *Hash, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("[%d]: %d\n", i, Hash[i]);
    }
}

void printHash(int *Hash, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("[%d]: %d\n", i, Hash[i]);
    }
}

int hash(int chave, int tamanho){
    return chave % tamanho;
}

int tentativaLinear(int hash, int i, int tamanho){
    return ((hash + i) % tamanho);
}

int buscaTabela(int *Hash, int chave, int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(Hash[i] == chave){
            return 0;
        }
    }

    return -1;
}

void inserirTentativaLinear(int *Hash, int chave, int tamanho){
    int hashing = hash(chave, tamanho);

    if(buscaTabela(Hash, chave, tamanho) == -1){
        int i = 0;
        int resetTabela = 0;

        while(resetTabela <= 2){
            int tentLin = tentativaLinear(hashing, i, tamanho);

            if(Hash[tentLin] == -1){
                Hash[tentLin] = chave;
                return;
            }
            else{
                printf("Colisão da chave %d na posicao %d!!\n", chave, tentLin);
                i++;
            }

            if(i >= tamanho){
                i = 0;
                resetTabela++;
            }
        }

        printf("OVERFLOW NA TABELA\n");
    }
    else{
        printf("A chave já está presente na tabela hash.\n");
    }

}
