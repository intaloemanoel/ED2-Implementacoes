#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "hash.h"

int pos_hash(int chave, int tamanho){
    return chave % tamanho;
}

void inicializa_tabela(Cliente* Hash[], int tamanho){
    for(int i = 0; i < tamanho; i++){
    	Hash[i] = NULL;
    }
}

void insere_cliente(Cliente* cli, Cliente* Hash[], int tamanho){
    int posHash = pos_hash(cli->cod, tamanho);

    if(Hash[posHash] == NULL){
        Hash[posHash] = cli;
    } else{
        Cliente *temp = Hash[posHash];

        while(temp->proximo != NULL){
            temp = temp->proximo;
        }

        temp->proximo = cli;
    }

    printf("Cliente foi inserido na posicao %d \n", posHash);
}

void libera_tabela(Cliente* Hash[], int tamanho){
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

void imprimir_tabela(Cliente* Hash[], int tamanho) {
    printf("\nTabela Hash:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%d]: ", i);

        Cliente* temp = Hash[i];
        while (temp) {
            printf("[%d | %s] -> ", temp->cod, temp->nome);
            temp = temp->proximo;
        }

        printf("NULL\n");
    }
}