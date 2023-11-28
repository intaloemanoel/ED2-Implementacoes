#include <stdio.h>
#include <stdlib.h>
#include "arvorePatricia.h"

void main(int argc, char** argv) {
    struct No* raiz = criaNo("RAIZ");
    raiz->esquerda = criaNo("0");
    raiz->direita = criaNo("1");
    raiz->esquerda->esquerda = criaNo("0");
    raiz->esquerda->direita = criaNo("1");
    raiz->direita->direita = criaNo("1");
    raiz->direita->esquerda = criaNo("0");

    imprimeArvore(raiz, 0);

    free(raiz->esquerda->direita);
    free(raiz->direita->esquerda);
    free(raiz->esquerda->esquerda);
    free(raiz->direita->direita);
    free(raiz->esquerda);
    free(raiz->direita);
    free(raiz);
}