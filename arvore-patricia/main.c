#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "arvorePatricia.h"


void main(int argc, char** argv) {
    // setup 
    No* raiz;
    raiz = (No*)malloc(sizeof(No));

    raiz->chave = __UINT32_MAX__; //CHAVE PROIBIDA
    raiz->esquerda = raiz;
    raiz->direita = raiz;
    raiz->digito = -1;

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
        printf("3 - 👋 Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        printf("\n");

        if(opcao < 1 || opcao > 3){
            printf("%d não é valido. Por favor, utilize uma das opções abaixo.\n", opcao);
                continue;
        }

        switch (opcao) {
            case 1:
                int item;
                printf("Por favor diga a chave que deseja inserir: ");
                scanf("%d", &item);
                printf("\n");
                // void inserir(Arvore raiz, Chave chave, Item conteudo);
                inserir(raiz, &item, item);
                break;
            case 2:
            int item;
                printf("Por favor diga a chave que deseja buscar: ");
                scanf("%d", &item);
                printf("\n");
                buscar(raiz, item);
                break;
            case 3:
                freeArvore(raiz);
                break;
        }
    }
}