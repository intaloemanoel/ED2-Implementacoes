#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int quantidadeChave = 0;
int quantidadeColisao = 0;
int aux;

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

int hash2(int chave, int tamanho){ // Segunda função de hash
    return 7 - (chave % 7);
}

int tentativaLinear(int hash, int i, int tamanho){
    return ((hash + i) % tamanho);
}

int tentativaQuadratica(int hash, int i, int tamanho){
    return ((hash + (i*i)) % tamanho); 
}

int dispersaoDupla(int hash, int hash2, int i, int tamanho){
    return (hash + (i * hash2) % tamanho);
}

int buscaTabela(int *Hash, int chave, int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(Hash[i] == chave){
            return 0;
        }
    }
    return -1;
}

int buscarChave(int *Hash, int chave, int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(Hash[i] == chave){
            return i;
        }           
    }
    return -1;
}

void excluirChave(int *Hash, int tamanho){
    aux = rand() % tamanho + 1;
    if (Hash[aux] != -1){
        Hash[aux] = -1;
        printf("\nChave aleatoria excluida da posicao %d", aux);
        quantidadeChave--;
    }     
}

int retornarColisoes(){
    return quantidadeColisao;
}

float calcular_fatorDeCarga(int tamanho){
    return (float)quantidadeChave/tamanho;
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
                printf("\nChave registrada: %d", Hash[tentLin]);
                printf("\nPosicao da chave: %d\n\n", tentLin);
                quantidadeChave++;
                        
                return;
            }
            else{
                printf("\nColisao da chave %d na posicao %d\n", chave, tentLin);
                quantidadeColisao++;
                i++;
            }

            if(i >= tamanho){
                i = 0;
                resetTabela++;
            }
        }

        printf("\nOVERFLOW NA TABELA\n");
    }
    else{ 
        printf("\nA chave ja esta presente na tabela hash.\n");
    }

}

void inserirTentativaQuadratica(int *Hash, int chave, int tamanho){
    int hashing = hash(chave, tamanho); // Aplica a função de hash padrão e  recebe um endereço

    if(buscaTabela(Hash, chave, tamanho) == -1){ // A função de busca retorna -1 quando percorre toda a tabela e não encontra o valor.
        int i = 0;
        int resetTabela = 0;

        while(resetTabela <= 2){                
            int tentQuad = tentativaQuadratica(hashing, i, tamanho); // Aplica a tentativa e recebe um endereço

            if(Hash[tentQuad] == -1){ // Achou um endereço vazio
                Hash[tentQuad] = chave; // Aplica a chave
                printf("\nChave %d registrada na posicao %d\n", Hash[tentQuad], tentQuad);
                quantidadeChave++;
                return;
            }
            else{ // Se o endereço já estiver ocupado
                printf("\nColisao da chave %d na posicao %d\n", chave, tentQuad);
                quantidadeColisao++;
                i++;
            }

            if(i >= tamanho){
                i = 0;
                resetTabela++;
            }
        }

        printf("\nOVERFLOW NA TABELA\n");
    }
    else{ // A função de busca retornou 0 --> encontrou na tabela
        printf("\nA chave ja esta presente na tabela hash.\n");
    }
}


void inserirDispersaoDupla(int *Hash, int chave, int tamanho){
    int hashing = hash(chave, tamanho); // Aplica a função de hash padrão e  recebe um endereço
    int hashingDupla = hash2(chave, tamanho); 

    if(buscaTabela(Hash, chave, tamanho) == -1){ // A função de busca retorna -1 quando percorre toda a tabela e não encontra o valor.
        int i = 0;
        int resetTabela = 0;

        while(resetTabela <= 2){                
            int DispDupla = dispersaoDupla(hashing, hashingDupla, i, tamanho);
            if (DispDupla > tamanho)
                break;;                

            if(Hash[DispDupla] == -1){ // Achou um endereço vazio
                Hash[DispDupla] = chave; // Aplica a chave
                printf("\nChave registrada: %d", Hash[DispDupla]);
                printf("\nPosicao da chave: %d\n\n", DispDupla);
                quantidadeChave++;
                return;
            }
            else{ // Se o endereço já estiver ocupado
                printf("\nColisao da chave %d na posicao %d\n", chave, DispDupla);
                quantidadeColisao++;
                i++;
            }

            if(i >= tamanho){
                i = 0;
                resetTabela++;
            }
        }

        printf("OVERFLOW NA TABELA\n");
        return;
    }
    else{ // A função de busca retornou 0 --> encontrou na tabela
        printf("A chave ja esta presente na tabela hash.\n");
    }
}

