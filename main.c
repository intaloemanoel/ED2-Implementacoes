#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "hash.h"

Cliente* inserir(Cliente* Hash){
    int cod;
    char nome[100];
    printf("A criar cliente");
    
    /*
    printf("-------- INSERIR CLIENTE --------\n");
    printf("Qual é o código do cliente?\n");
    printf("Código: ");
    scanf("%d", &cod);
    
    printf("Qual é o nome do cliente?\n");
    printf("Nome: ");
    scanf("%s", nome);
    */
    
    Cliente *c = cliente(1, "Ana");
    printf("Cliente criado");
    Hash = insere_cliente(c, Hash, tamanho);

    return Hash;
}

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
        printf("\n");

        Cliente *Hash = (Cliente*) malloc(tamanho * sizeof(Cliente));
        
        Hash = inicializa_tabela(Hash, tamanho);

        int menu = 1;
        int opcao;
        while(menu == 1){
            printf("-------- MENU --------\n");
            printf("O que você deseja fazer?\n");
            printf("1 - Inserir Cliente\n");
            printf("2 - Buscar Cliente\n");
            printf("3 - Deletar\n");
            printf("4 - Imprimir tabela hash\n");
            printf("Opção: ");
            scanf("%d", &opcao);
            printf("\n");

            if(opcao < 1 || opcao > 4){
                printf("%d não é valido. Por favor, utilize uma das opções acima.\n", opcao);
                continue;
            }

            switch (opcao)
            {
            case 1:
                Hash = inserir(Hash);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            }
        }
        
        //free hash
        libera_tabela(Hash, tamanho);
        fclose(out);    
    }



}