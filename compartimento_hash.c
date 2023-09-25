#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "compartimento_hash.h"

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

Cliente* buscar_cliente(Cliente* Hash[], int codigo, int tamanho){
    int posHash = pos_hash(codigo, tamanho);

    Cliente* pCli = Hash[posHash];
    while (pCli != NULL){
        if(pCli->cod == codigo){
            return pCli;
        }

        pCli = pCli->proximo;
    }

    return NULL;
}

void remover_cliente(Cliente* Hash[], int codigo, int tamanho){
    int posHash = pos_hash(codigo, tamanho);

    Cliente* cli = buscar_cliente(Hash, codigo, tamanho);

   if(cli != NULL){
        printf("\n✅ Cliente de código %d foi encontrado:\n", codigo);
        imprimir(cli);

        Cliente* pCli = Hash[posHash];
        Cliente* anterior = NULL;

        while (pCli != NULL){
            if(pCli->cod != codigo){
                anterior = pCli;
                pCli = pCli->proximo;
            } else{
                break;
            }
        }

        if(anterior == NULL){
            Hash[posHash] = pCli->proximo;
            return;
        } else{
            anterior->proximo = pCli->proximo;
        }
        
        free(pCli);
        printf("\n✅ Cliente excluído\n");
    }
    else{
        printf("❌ ERRO NA REMOÇÃO: Não foi encontrado este cliente na tabela.");
        return;
    }
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