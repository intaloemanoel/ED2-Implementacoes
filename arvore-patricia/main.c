#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "arvorePatricia.h"

void main(int argc, char** argv) {
    No* raiz;
    raiz = (No*)malloc(sizeof(No));

    raiz->chave = __UINT32_MAX__; //CHAVE PROIBIDA
    raiz->esquerda = raiz;
    raiz->direita = raiz;
    raiz->digito = -1;

    freeArvore(raiz);
}