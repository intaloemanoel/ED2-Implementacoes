#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "arvorePatricia.h"

#define COUNT 10

/*
No* criaNo(char rotulo[50]){
    No *node = (No *) malloc(sizeof(No));

    if (node){
        memset(node, 0, sizeof(No));
    }

    strcpy(node->rotulo, rotulo);
    node->fimDaPalavra = false;
    node->esquerda = NULL;
    node->direita = NULL;

    return node;
}*/

No* novoNo(Chave chave, Item conteudo, int digito){
    No* novo;
    novo = (No*) malloc(sizeof(No));
    novo->chave = chave;
    novo->conteudo = conteudo;
    novo->digito = digito;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

int pegaDigito(int chave, int digito){
    return (int)((chave >>
    (bitsDigito * (digitosPalavra - 1 - digito))) & (Base - 1));
}

No* busca(Arvore raiz, Chave chave){
    No* alvo;
    alvo = buscaR(raiz->esquerda, chave, -1);
    return alvo->chave = chave ? alvo : NULL;
}

No* buscaR(Arvore raiz, Chave chave, int digitoAnterior){
    if(raiz->digito <= digitoAnterior){
        return raiz;
    }

    if(pegaDigito(chave, raiz->digito) == 0)
        return buscaR(raiz->esquerda, chave, raiz->digito);

    return buscaR(raiz->direita, chave, raiz->digito);
}

void inserir(Arvore raiz, Chave chave, Item conteudo){
    int i;
    No* aux = buscaR(raiz->esquerda, i, -1);
    if(aux->chave == chave)
        return;

    for(i = 0; pegaDigito(chave, i) == pegaDigito(aux->chave, i); i++){
        No* novo = novoNo(chave, conteudo, i);
        raiz->esquerda = insereR(raiz->esquerda, novo, i, raiz);
    }
}

Arvore insereR(Arvore raiz, No* novo, int digitoDif, No* pai){
    if((raiz->digito >= digitoDif) || (raiz->digito <= pai->digito)){
        if(pegaDigito(novo->chave, digitoDif) == 1){
            novo->esquerda;
            novo->direita;
        }
        else{
            novo->esquerda = novo;
            novo->direita = raiz;
        }
        return novo;
    }

    if(pegaDigito(novo->chave, raiz->digito) == 0)
        raiz->esquerda = insereR(raiz->esquerda, novo, digitoDif, raiz);

    raiz->direita = insereR(raiz->direita, novo, digitoDif, raiz);
}


// Imprime cliente
//https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void imprimeArvore(No* raiz, int space)
{
    // Base case
    if (raiz == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    imprimeArvore(raiz->direita, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%s\n", raiz->digito);
 
    // Process left child
    imprimeArvore(raiz->esquerda, space);
}

void freeArvore(Arvore arvore){
    freeArvore(arvore->esquerda);
    freeArvore(arvore->direita);
    free(arvore);
}