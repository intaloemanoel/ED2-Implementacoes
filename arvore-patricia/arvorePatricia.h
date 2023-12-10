#ifndef ARVOREPATRICIA_H
#define ARVOREPATRICIA_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct No {
    char* chave;
    int digito;
    struct No *esquerda;
    struct No *direita;
} No;

int pegaDigito(char* chave, int digito);

// Cria No. Lembrar de usar free(No)
No* criarNo(char* chave, int digito);

//Busca a chave desejada na árvore
No* buscarChave(No* raiz, char* chave, int digitoAnterior);

//Insere novo Nó na árvore
No* inserirChave(No* raiz, char* chave, int digitoDiferente);

//Imprime árvore com base no Nó
void imprimeArvore(No* raiz, int space);

// Libera a memória utilizada pra armazenar a árvore
void liberaArvore(No* raiz);

#endif