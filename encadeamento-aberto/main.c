#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

void main(int argc, char **argv)
{
    int tamanho;

    printf("-------- TABELA HASH - ENDEREÇAMENTO ABERTO --------\n");
    printf("-------- ALEXIA ASSUMPÇÃO, ÍTALO EMANOEL E GUILHERME --------\n");
    printf("Qual será o tamanho da tabela hash?\n");
    printf("📏 Tamanho ");
    scanf("%d", &tamanho);

    int *Hash = malloc(tamanho * sizeof(int));

    for(int i = 0; i <= tamanho; i++){
        Hash[i] = -1;
    }

    int menu = 1;
    int opcao;
    while (menu == 1)
    {
        printf("\n-------- MENU --------\n");
        printf("O que você deseja fazer?\n");
        printf("1 - 🔵 Inserir/Excluir aleatoriamente com fator de carga 0,7\n");
        printf("2 - 🟢 Inserir/Excluir aleatoriamente com fator de carga 0,8\n");
        printf("3 - 🔴 Inserir/Excluir aleatoriamente com fator de carga 0,9\n");
        printf("4 - 🖨️ Imprimir tabela hash\n");
        printf("5 - 👋 Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao < 1 || opcao > 6)
        {
            printf("%d não é valido. Por favor, utilize uma das opções abaixo.\n", opcao);
            continue;
        }

        switch (opcao)
        {
        case 1:
            inserirTentativaLinear(Hash, 6,tamanho);
            inserirTentativaLinear(Hash, 13,tamanho);
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            imprimir_tabela(Hash, tamanho);
            break;
        case 5:
            free(Hash);
            printf("🧹 Liberando a tabela hash...\n");
            printf("✅ Execução concluida\n");
            exit(1);
            break;
        }
    }
}