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

// cria novo no
No* criarNo(Chave chave, Item conteudo, int digito){
    No* novo;
    novo = (No*) malloc(sizeof(No));
    novo->chave = chave;
    novo->conteudo = conteudo;
    novo->digito = digito;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// identifica o digito que a no representa
int identificaDigito(int chave, int digito){
    return (int)((chave >>
    (bitsDigito * (digitosPalavra - 1 - digito))) & (Base - 1));
}

// realiza a busca de uma chave na arvore
No* buscarChave(Arvore raiz, Chave chave){
    No* noEncontrado = buscaRecursiva(raiz->esquerda, chave, -1);
    return noEncontrado->chave = chave ? noEncontrado : NULL;
}

// realiza busca na arvore, utiliza recursividade
No* buscaRecursiva(Arvore raiz, Chave chave, int digitoAnterior){
    if(raiz->digito <= digitoAnterior){
        return raiz;
    }

    if(identificaDigito(chave, raiz->digito) == 0) {
        return buscaRecursiva(raiz->esquerda, chave, raiz->digito);
    }

    return buscaRecursiva(raiz->direita, chave, raiz->digito);
}

// insere chave na arvore
void inserirChave(Arvore raiz, Chave chave, Item conteudo){
    int i=0;
    No* aux = buscaRecursiva(raiz->esquerda, i, -1);
    if(aux->chave == chave) {
        return;
    }
        
    for(i = 0; identificaDigito(chave, i) == identificaDigito(aux->chave, i); i++){
        No* novo = criarNo(chave, conteudo, i);
        raiz->esquerda = insereRecursivo(raiz->esquerda, novo, i, raiz);
    }
}

// insere a chave, utiliza estrategia recursiva
Arvore insereRecursivo(Arvore raiz, No* novo, int digitoDif, No* pai){
   
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
void liberaArvore(Arvore arvore) {
    freeArvore(arvore->esquerda);
    freeArvore(arvore->direita);
    free(arvore);
}


// quando andar pra esesquerda é 0
// direita é 1
int buscaChave(char[10] chave, Arvore raiz) {
    char zero = "0";
    char um = "1";
    No* noDaVez = raiz;
    for(int index=0; index<10; index++) {
        if(noDaVez->conteudo == chave && noDaVez->esquerda == NULL && noDaVez->direita==NULL) {
            // encontrou
            return 1;
        } 
        if(chave[index] == zero && noDaVez->posicao == index+1) {
            noDaVez = noDaVez->esquerda;
            continue;
        }
        if (chave[index] == um && noDaVez->posicao == index+1) {
            noDaVez = noDaVez->direita;
            continue;
        }
    }
    // nao encontrei
    return 0;
}

void insereChaveNaArvore(char[10] chave, Arvore raiz) {
    char zero = "0";
    char um = "1";
    No* noDaVez = raiz;
    for(int index=0; index<10; index++) {
        if(noDaVez->conteudo == chave && noDaVez->esquerda == NULL && noDaVez->direita==NULL) {
            // encontrou
            printf("ja se encontra na arvore");
            break;
        }
        if (noDaVez->esquerda == NULL && noDaVez->direita == NULL && noDaVez->conteudo == "") {
            noDaVez->conteudo = chave;
            break;
        }
        if(chave[index] == zero && noDaVez->posicao == index+1) {
            noDaVez = noDaVez->esquerda;
            continue;
        }
        if (chave[index] == um && noDaVez->posicao == index+1) {
            noDaVez = noDaVez->direita;
            continue;
        }
    }

}
