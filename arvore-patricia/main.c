#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "arvorePatricia.h"

No* buscar(No* raiz, char* chave){
    No* busca;

    busca = buscarChave(raiz, chave, 0);
    
    if(strcmp(busca->chave,chave) == 0){
        printf("Chave %s foi encontrada na Árvore.\n", chave);
        return busca;
    }
    else{
        printf("Não foi encontrado na Árvore.\n");
        return NULL;
    }

    return NULL;
}

No* inserir(No* raiz, char* chave){
    int inicia = 0;
    No* busca;
    while (inicia == 0)
    {
        busca = buscarChave(raiz, chave, 0);

        if(strcmp(busca->chave, chave) == 0){
            printf("Chave %s foi encontrada na Árvore.\n", chave);
            return busca;
        }
        else{
            printf("Não foi encontrado na Árvore. Iniciando inserção...\n");
        }

        int i = 0;
        if (strcmp(busca->chave, "-1") != 0) { //Raiz
            while(pegaDigito(chave, i) == pegaDigito(busca->chave, i)){
                i++; //Pegar onde o digito difere entre a chave e o caminho encontrado
            }
        }

        busca = inserirChave(busca, chave, i);
    }
}

void main(int argc, char** argv) {
    // Raiz da árvore
    No* raiz;
    raiz = (No*)malloc(sizeof(No));

    raiz->chave = "-1"; //CHAVE PARA RAIZ
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

                inserir(raiz, chave);

                //inserirChave(raiz, chave, 0);
                break;
            case 2:
                printf("Por favor diga a chave que deseja buscar: ");
                scanf("%s", chave);
                printf("\n");
                
                buscar(raiz, chave);

                break;
            case 3:
                imprimeArvore(raiz, 0);
                break;
            case 4:
                printf("Limpando a memória...\n");
                menu = 1;
                break;
        }
    }

    liberaArvore(raiz);
}