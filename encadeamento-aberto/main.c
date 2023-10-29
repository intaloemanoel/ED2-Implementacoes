#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabelaHash.h"


void main(int argc, char **argv)
{
    int tamanho, chave, chave_procurada;
    float fator = 0.0, fatorNovo;
    clock_t start, end;
    double tempoGasto;

    printf("-------- TABELA HASH - ENDEREÇAMENTO ABERTO --------\n");
    printf("-------- ALEXIA ASSUMPÇÃO, ÍTALO EMANOEL E GUILHERME LOBO --------\n");
    printf("Qual sera o tamanho da tabela hash?\n");
    printf("📏 Tamanho: ");
    scanf("%d", &tamanho);
    printf("\nQual sera o fator de carga? ");
    scanf("%f", &fator);
    
    
    int *Hash = malloc(tamanho * sizeof(int));

    for(int i = 0; i <= tamanho; i++){ // Preenche a tabela com vazios -1
        Hash[i] = -1;
    }

    int menu = 1;
    int opcao;

    while (menu == 1)
    {  
        printf("\n\n------------------------ MENU ------------------------\n");
        printf("O que voce deseja fazer?\n");
        printf("1 - 🔵 Inserir chaves aleatorias ate se aproximar do Fator de Carga utilizando a Tentativa Linear\n");
        printf("2 - 🟢 Inserir chaves aleatorias ate se aproximar do Fator de Carga utilizando a Tentativa Quadratica\n");
        printf("3 - 🔴 Inserir chaves aleatorias ate se aproximar do Fator de Carga utilizando a Dispersao Dupla\n");
        printf("4 - Buscar uma chave\n");
        printf("5 - 🖨️ Imprimir tabela hash\n");
        printf("6 - Excluir chaves aleatoriamente para um novo fator de carga\n");
        printf("7 - 👋 Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao < 1 || opcao > 7)
        {
            printf("%d não eh valido. Por favor, utilize uma das opções abaixo.\n", opcao);
            continue;
        }

        switch (opcao)
        {

// ------------ Tentativa Linear --------------------

        case 1:
            start = clock();
            while (calcular_fatorDeCarga(tamanho) < fator){
                chave = rand() % (tamanho*100) + 1;
                inserirTentativaLinear(Hash, chave,tamanho);
                //printf("Fator de Carga pela funcao: %f", calcular_fatorDeCarga(quantidadeChave, tamanho));
            }
            
            end = clock();
            tempoGasto = (double)(end - start) / CLOCKS_PER_SEC;

            printf("\n\n-----------------------------------------------\n");
            printf("Fator de Carga final: %f\n", calcular_fatorDeCarga(tamanho));
            printf("Numero de colisoes: %d\n", retornarColisoes());
            printf("Tempo gasto: %f segundos", tempoGasto);
            printf("-----------------------------------------------\n");
            break;

// -------------- Tentativa Quadrática ------------------

        case 2:
            start = clock();
            while (calcular_fatorDeCarga(tamanho) < fator){
                chave = rand() % (tamanho*100) + 1;
                inserirTentativaQuadratica(Hash, chave,tamanho);
                //printf("Fator de Carga pela funcao: %f", calcular_fatorDeCarga(quantidadeChave, tamanho));
            }

            end = clock();
            tempoGasto = (double)(end - start) / CLOCKS_PER_SEC;

            printf("\n\n-----------------------------------------------\n");
            printf("Fator de Carga final: %f\n", calcular_fatorDeCarga(tamanho));
            printf("Numero de colisoes: %d\n", retornarColisoes());
            printf("Tempo gasto: %f segundos", tempoGasto);

            printf("-----------------------------------------------\n");
            break;

// ----------- Dispersão Dupla ---------------------

        case 3:
            start = clock();
            while (calcular_fatorDeCarga(tamanho) < fator){    
                chave = rand() % (tamanho*100) + 1;
                inserirDispersaoDupla(Hash, chave, tamanho);
            }

            end = clock();
            tempoGasto = (double)(end - start) / CLOCKS_PER_SEC;
            printf("\n\n-----------------------------------------------\n");
            printf("Fator de Carga final: %f\n", calcular_fatorDeCarga(tamanho));
            printf("Numero de colisoes: %d\n", retornarColisoes());
            printf("Tempo gasto: %f segundos", tempoGasto);
            printf("-----------------------------------------------\n");
            break;

// --------------------------------

        case 4:
            printf("\nQual a chave que sera buscada? \n");
            scanf("%d", &chave_procurada);
            if (buscarChave(Hash, chave_procurada, tamanho) == -1)
                printf("Esta chave nao existe");
            else
                printf("A chave foi encontrada na posicao: %d\n", buscarChave(Hash, chave_procurada, tamanho));               
            break;
        case 5:
            imprimir_tabela(Hash, tamanho);
            printf("\nNumero de colisoes: %d\n", retornarColisoes());
            printf("Fator de Carga final: %f\n", calcular_fatorDeCarga(tamanho));
            break;

        case 6:
            printf("\nQual o novo Fator de carga?\n");
            scanf("%f", &fatorNovo);
            while (calcular_fatorDeCarga(tamanho) > fatorNovo*1.05){
                excluirChave(Hash, tamanho);
            }
            break;

        case 7:
            free(Hash);
            printf("🧹 Liberando a tabela hash...\n");
            printf("✅ Execução concluida\n");
            exit(1);
            break;
        }

    }
}