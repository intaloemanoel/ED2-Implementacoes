#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "arvorePatricia.h"

#define COUNT 10

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
    printf("%s\n", raiz->rotulo);
 
    // Process left child
    imprimeArvore(raiz->esquerda, space);
}