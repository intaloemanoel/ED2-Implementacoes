#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "hash.h"

void main(int argc, char** argv) {
    FILE *out;
    FILE *outHash;

    if ((out = fopen("cliente.dat", "w+b")) == NULL || (outHash = fopen("tabHash.dat", "w+b")) == NULL) {
        printf("Erro ao abrir os arquivos\n");
        exit(1);
    } else {
        int tamanho;

        printf("-------- TABELA HASH - ENCADEAMENTO EXTERNO --------\n");
        printf("-------- ALEXIA ASSUMPÇÃO, ÍTALO EMANOEL E GUILHERME --------\n");
        printf("Qual será o tamanho da tabela hash?\n");
        printf("Tamanho ");
        scanf("%d", &tamanho);

        Cliente *Hash;
        Hash = (Cliente*) malloc(tamanho * sizeof(Cliente));
        
        //free hash
        free(Hash);
        fclose(out);    
    }



}