#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "arvorePatricia.h"

bool buscar(No* raiz, char* chave){
    printf("Iniciando busca da chave: %s\n", chave);

    No* busca = buscarChave(raiz, chave, 0);
    
    if(busca == NULL){
        printf("Não foi encontrado na Árvore.\n");
        return false;
    }
    else if(strcmp(busca->chave,chave) == 0){
        printf("Chave %s foi encontrada na Árvore.\n", chave);
        return true;
    }

    return false;
}

void main(int argc, char** argv) {
    // Raiz da árvore
    No* raiz;
    raiz = (No*)malloc(sizeof(No));

    raiz->chave = "-1"; //CHAVE PARA RAIZ
    raiz->ehFim = false;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    raiz->digito = 0;

    printf("-------- ÁRVORE PATRÍCIA --------\n");
    printf("-------- ALEXIA ASSUMPÇÃO, ÍTALO EMANOEL E GUILHERME LOBO--------\n");

    // menu
    int menu=0;
    int opcao;
    while(menu==0) {
        printf("\n-------- MENU --------\n");
        printf("O que você deseja fazer?\n");
        printf("1 - ➕ Inserir Chave\n");
        printf("2 - 🔍 Buscar Chave\n");
        printf("3 - 🖨️ Imprimir Árvore\n");
        printf("4 - 👋 Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        printf("\n");

        if(opcao < 1 || opcao > 4){
            printf("%d não é valido. Por favor, utilize uma das opções abaixo.\n", opcao);
                continue;
        }

        char chave[10];

        switch (opcao) {
            case 1:
                printf("Por favor diga a chave que deseja inserir: ");
                scanf("%s", chave);
                printf("\n");

                bool existe = buscar(raiz, chave);
                
                if(existe == false){
                    inserirChave(raiz, chave);
                }
                break;
            case 2:
                printf("Por favor diga a chave que deseja buscar: ");
                scanf("%s", chave);
                
                buscar(raiz, chave);

                break;
            case 3:
                imprimeArvore(raiz, 0);
                break;
            case 4:
                printf("\nA árvore Patricia resultante é: \n");
                transformarPatricia(&raiz);
                imprimeArvore(raiz, 0);
                printf("Limpando a memória...\n");
                menu = 1;
                break;
        }
    }

    liberaArvore(raiz);
}