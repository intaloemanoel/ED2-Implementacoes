#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "arvorePatricia.h"

No* buscar(No* raiz, char* chave){
    No* busca;

    if(chave[0] == 0){ //Percorre o lado esquerdo
        busca = buscarChave(raiz->esquerda, chave, -1);
    }
    else{
        busca = buscarChave(raiz->direita, chave, -1);
    }
    
    if (busca == NULL)
    {
        printf("Não foi encontrado na Árvore.\n");
        free(busca);
        return NULL;
    }
    
    if(busca->chave == chave){
        printf("Chave %s foi encontrada na Árvore.\n", chave);
        return busca;
    }

    free(busca);
    return NULL;
}

No* inserir(No* raiz, char* chave){
    No* busca = buscar(raiz, chave);

    if(busca != NULL){
        printf("ERRO: Chave já existente na árvore!\n");
    }

    int i = 0;
    while(chave[i] == busca->chave[i]){
        i++; //Pegar onde o digito difere entre a chave e o caminho encontrado
    }

    No* novo = criarNo(chave, i);
    //raiz->esquerda = inserirChave(raiz->esquerda, novo, i, raiz);
    
    free(busca);
    free(novo);
}



void main(int argc, char** argv) {
    // Raiz da árvore
    No* raiz;
    raiz = (No*)malloc(sizeof(No));

    raiz->chave = __UINT32_MAX__; //CHAVE PARA RAIZ
    raiz->esquerda = NULL;
    raiz->direita = NULL;
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
                char* chave;
                printf("Por favor diga a chave que deseja inserir: ");
                scanf("%d", &chave);
                printf("\n");

                inserir(raiz, chave);
                //inserirChave(raiz, &chave);
                break;
            case 2:
                char* chave;
                printf("Por favor diga a chave que deseja buscar: ");
                scanf("%d", &chave);
                printf("\n");
                
                buscar(raiz, chave);

                break;
            case 3:
                printf("Limpando a memória...");
                menu = 1;
                break;
        }
    }

    liberaArvore(raiz);
}