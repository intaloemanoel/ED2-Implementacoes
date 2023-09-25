#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "hash.h"

void inserir(Cliente* Hash[], int tamanho){
    int cod;
    char nome[100];
    
    printf("-------- INSERIR CLIENTE --------\n");
    printf("Qual é o código do cliente?\n");
    printf("🔢 Código: ");
    scanf("%d", &cod);
    
    printf("Qual é o nome do cliente?\n");
    printf("✍🏻 Nome: ");
    scanf("%s", nome);

    Cliente* cli = (Cliente*)malloc(sizeof(Cliente));
    cli = cliente(cod, nome);
    printf("\nO seguinte cliente será inserido na tabela:\n");
    imprimir(cli);

    insere_cliente(cli, Hash, tamanho);
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
        printf("📏 Tamanho ");
        scanf("%d", &tamanho);

        Cliente* Hash[tamanho];
        inicializa_tabela(Hash, tamanho);

        int menu = 1;
        int opcao;
        while(menu == 1){
            printf("\n-------- MENU --------\n");
            printf("O que você deseja fazer?\n");
            printf("1 - ➕ Inserir Cliente\n");
            printf("2 - 🔍 Buscar Cliente\n");
            printf("3 - ❌ Remover Cliente\n");
            printf("4 - 🖨️ Imprimir tabela hash\n");
            printf("5 - 👋 Sair\n");
            printf("Opção: ");
            scanf("%d", &opcao);
            printf("\n");

            if(opcao < 1 || opcao > 6){
                printf("%d não é valido. Por favor, utilize uma das opções abaixo.\n", opcao);
                continue;
            }

            switch (opcao){
            case 1:
                inserir(Hash, tamanho);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                imprimir_tabela(Hash, tamanho);
                break;
            case 5:
                libera_tabela(Hash, tamanho);
                printf("🧹 Liberando a tabela hash...\n");
                printf("✅ Execução concluida\n");
                exit(1);
                break;
            }
        }

        fclose(out);    
    }



}