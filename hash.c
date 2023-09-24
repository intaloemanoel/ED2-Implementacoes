#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "hash.h"

int pos_hash(int chave, int tamanho){
    return chave % tamanho;
}

Cliente* inicializa_tabela(Cliente* Hash, int tamanho){
    for(int i = 0; i < tamanho; i++){
    	Hash[i].proximo = NULL;
    }

    return Hash;
}

Cliente* insere_cliente(Cliente* cli, Cliente** Hash, int tamanho){
    int posHash = pos_hash(cli->cod, tamanho);

    if(Hash[posHash]){
        Hash[posHash] = cli;
    } else{
        Cliente *temp = Hash[posHash];

        while(temp->proximo){
            temp = temp->proximo;
        }

        temp->proximo = cliente;
    }

    printf("Cliente foi inserido na posicao %d", posHash);

    return Hash;
}

libera_tabela(Cliente** Hash, int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(Hash[i]){
            Cliente* temp = Hash[i];
            Cliente* tempDois;

            while(temp){
                tempDois = temp;
                temp = temp->proximo;
                free(tempDois);
            }
        }
    }
}