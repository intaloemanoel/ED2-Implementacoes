#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "compartimento_hash.h"

int pos_hash(int chave, int tamanho){
    return chave % tamanho;
}

int inicializa_tabela(FILE* tabHash){
    printf("🔄️ Carregando arquivo tabela Hash...\n");
    rewind(tabHash);

    int cliCod;
    int tamanhoTabela;
    
    if (0 != fread(&cliCod, sizeof(int), 1, tabHash)) {
        printf("Reutilizando tabela Hash do diretório atual:\n");
        tamanhoTabela = imprime_tabela(tabHash);
        return tamanhoTabela;
    }
    else{
        printf("-------- TABELA HASH - ENCADEAMENTO EXTERNO --------\n");
        printf("-------- ALEXIA ASSUMPÇÃO, ÍTALO EMANOEL E GUILHERME --------\n");
        printf("Qual será o tamanho da tabela hash?\n");
        printf("📏 Tamanho ");
        scanf("%d", &tamanhoTabela);
    

        int cliNull = -1;
        for(int i = 0; i < tamanhoTabela; i++){
            fwrite(&cliNull, sizeof(int), 1, tabHash);
        }

        printf("\nTabela Hash inicializada com tamanho %d\n", tamanhoTabela);
    }

    return tamanhoTabela;
}

int imprime_tabela(FILE *tabHash){
    rewind(tabHash);

    int cliCod;
    int tamanhoTabela = 0;
    while ((cliCod = ler_valorHash(tabHash)) != -2) {
        printf("[%d] %d \n", tamanhoTabela, cliCod);
        tamanhoTabela++;
    }

    return tamanhoTabela;
}

int ler_valorHash(FILE *tabHash) {
    int cliCod;

    if (0 >= fread(&cliCod, sizeof(int), 1, tabHash)) {
        return -2;
    }

    return cliCod;
}