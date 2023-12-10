#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "arvorePatricia.h"

#define COUNT 10

int pegaDigito(char* chave, int digito){
   return ((int)chave[digito] - '0');
}

// cria novo no
No* criarNo(char* chave, int digito){
    No* novo = (No*) malloc(sizeof(No));

    novo->chave = chave;
    novo->digito = digito;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No* buscarChave(No* raiz, char* chave, int digitoAnterior){
    if(raiz == NULL){
        return NULL;
    }

    printf("Heeeey");
    printf("RAIZ->DIGITO: %d :: STRLEN: %d\n", raiz->digito, (int)(strlen(chave) - 1));
    int chaveLenght = (int)(strlen(chave) - 1);
    printf("ChaveLen declarada");
    if(raiz->digito == 2){
        printf("entrei");
        if(strcmp(raiz->chave, chave) == 0){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                printf("NESTE CU");
                return raiz;
            }
        }
    }

    printf("Heeeeeeeey");
    //printf("Digito %d é %d\n", raiz->digito, pegaDigito(chave, raiz->digito));

    if(pegaDigito(chave, raiz->digito) == 0) { //Percorrer a esquerda
        //printf("Chave [%d] = %s || %s", digitoAnterior, raiz->esquerda->chave, chave);
        return buscarChave(raiz->esquerda, chave, raiz->digito);
    }
    else if(pegaDigito(chave, raiz->digito) == 1){ //Percorrer a direita
        //printf("Chave [%d] = %s || %s", digitoAnterior, raiz->direita->chave, chave);
        return buscarChave(raiz->direita, chave, raiz->digito);
    }
    else{
        return NULL;
    }
}

// Teste inserção binária
No* inserirChave(No* raiz, char* chave, int digitoDiferente){
    if(raiz == NULL){
        return raiz = criarNo(chave, digitoDiferente);
    }

    if(pegaDigito(chave, digitoDiferente) == 0){
        return raiz->esquerda = inserirChave(raiz->esquerda, chave, digitoDiferente + 1);
    }
    else{
        return raiz->direita = inserirChave(raiz->direita, chave, digitoDiferente + 1);
    }
}

// Imprime arvore
void imprimeArvore(No* raiz, int espaco) {
    // Base 
    if (raiz == NULL) {
        return;
    }

    espaco += COUNT;
 
    // Imprime o filho da direita
    imprimeArvore(raiz->direita, espaco);
 
    // Imprime primeiro no apos o espaco
    printf("\n");
    for (int i = COUNT; i < espaco; i++) {
        printf(" ");
    }    

    if(raiz->digito == 0){
        printf("RAIZ\n");
    }
    else
    {
        printf("%d\n", raiz->digito);
    }

    // Imprime filho esquerdo
    imprimeArvore(raiz->esquerda, espaco);
}

// libera memória utilizada pela arvore
void liberaArvore(No* arvore) {
    if(arvore != NULL){
        liberaArvore(arvore->esquerda);
        liberaArvore(arvore->direita);
        free(arvore);
    }
}