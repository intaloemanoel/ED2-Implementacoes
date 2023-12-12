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
No* criarNo(char* chave, int digito, bool ehFim){
    No* novo = (No*) malloc(sizeof(No));

    novo->chave = chave;
    novo->digito = digito;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->ehFim = ehFim;

    return novo;
}

No* buscarChave(No* noh, char* chave, int digitoAnterior){
    if(noh == NULL){
        return NULL;
    }

    if(chave[noh->digito] == '\0'){
        if(noh->ehFim == true){ //achou uma chave
            if(strcmp(noh->chave, chave) == 0){
                return noh;
            }
            return NULL;
        }
    }

    if(pegaDigito(chave, noh->digito) == 0) { //Percorrer a esquerda
        return buscarChave(noh->esquerda, chave, noh->digito);
    }
    else if(pegaDigito(chave, noh->digito) == 1){ //Percorrer a direita
        return buscarChave(noh->direita, chave, noh->digito);
    }
    else{
        return NULL;
    }
}

void inserirChave(No* raiz, char* chave){
    No* noh = raiz;

    for (int i = 0; i < strlen(chave); i++) {
        int digito = pegaDigito(chave, i);
        
        if(noh->ehFim == true){
            printf("ERRO: Inserção Inválida! Tentando inserir uma palavra que contém uma palavra final no meio.\n");
            return;
        }

        if(digito == 0){
            if(noh->esquerda == NULL){
                if(chave[i + 1] == '\0'){
                    noh->esquerda = criarNo(chave, i + 1, true);
                    printf("Chave %s inserida com sucesso\n", chave);
                    return;
                }

                noh->esquerda = criarNo(chave, i + 1, false);
            }
            
            noh = noh->esquerda;
        }
        else if (digito == 1){
            if(noh->direita == NULL){
                if(chave[i + 1] == '\0'){
                    noh->direita = criarNo(chave, i + 1, true);
                    printf("Chave %s inserida com sucesso\n", chave);
                    return;
                }

                noh->direita = criarNo(chave, i + 1, false);
            }
            
            noh = noh->direita;
        }
    }
}


void transformarPatricia(No** noh){
    if((*noh) == NULL){
        return;
    }

    int novoDigito;
    if((*noh)->digito > 0){ //Tira a raiz
        No* copia;
        if((*noh)->esquerda != NULL & (*noh)->direita == NULL){
            copia = (*noh)->esquerda;
            novoDigito = (*noh)->digito + 1;

            (*noh) = (*noh)->esquerda;
            (*noh)->esquerda = copia->esquerda;
            (*noh)->direita = copia->direita;

            (*noh)->digito = novoDigito;
        }
        if((*noh)->esquerda == NULL & (*noh)->direita != NULL){
            copia = (*noh)->direita;
            novoDigito = (*noh)->digito + 1;

            (*noh) = (*noh)->direita;
            (*noh)->direita = NULL;
            (*noh)->esquerda = copia->esquerda;
            (*noh)->direita = copia->direita;

            (*noh)->digito = novoDigito;
            
        }
    }
    
    transformarPatricia(&(*noh)->esquerda);
    transformarPatricia(&(*noh)->direita);
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
        if(raiz->ehFim == true){
            printf("PALAVRA\n");
        }
        else{
            printf("%d\n", raiz->digito);
        }
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