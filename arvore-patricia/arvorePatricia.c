#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "arvorePatricia.h"

#define COUNT 10

// cria novo no
No* criarNo(char* chave, int digito){
    No* novo = (No*) malloc(sizeof(No));

    novo->chave = chave;
    novo->digito = digito;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

// realiza busca na arvore, utiliza recursividade
No* buscarChave(No* raiz, char* chave, int digitoAnterior){
    if(raiz == NULL){
        return NULL;
    }

    if(raiz->digito <= digitoAnterior){ //Folha
        return raiz;
    }

    if(chave[raiz->digito] == 0) { //Percorrer a esquerda
        return buscarChave(raiz->esquerda, chave, raiz->digito);
    }
    else{ //Percorrer a direita
        return buscarChave(raiz->direita, chave, raiz->digito);
    }
}

// insere a chave, utiliza estrategia recursiva
No* inserirChave(No* raiz, No* pai, No* novo, int digitoDiferente){
    if((raiz->digito >= digitoDiferente) || (raiz->digito <= pai->digito)){ //Chegou em folha ou quebra da inserção
        if(novo->chave[digitoDiferente] == 1){
            novo->esquerda = raiz;
            novo->direita = novo;

            return novo;
        }

        novo->esquerda = novo;
        novo->direita = raiz;
        return novo;
    }

    if(novo->chave[raiz->digito] == 0) {
        raiz->esquerda = insereRecursivo(raiz->esquerda, novo, digitoDiferente, raiz);
    }

    raiz->direita = insereRecursivo(raiz->direita, novo, digitoDiferente, raiz);
    return raiz;
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
    printf("%s\n", raiz->digito);
 
    // Imprime filho esquerdo
    imprimeArvore(raiz->esquerda, espaco);
}

// libera memória utilizada pela arvore
void liberaArvore(No* arvore) {
    freeArvore(arvore->esquerda);
    freeArvore(arvore->direita);
    free(arvore);
}