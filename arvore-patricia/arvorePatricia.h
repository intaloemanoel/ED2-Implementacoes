#ifndef ARVOREPATRICIA_H
#define ARVOREPATRICIA_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef int Item;
typedef char byte;
typedef byte *Chave;

const int bitsPalavra = 32;
const int bitsDigito = 8;
const int digitosPalavra = bitsPalavra / bitsDigito;
const int Base = 1 << bitsDigito;

typedef struct No {
    Chave chave;
    Item conteudo;
    int digito;
    struct No *esquerda;
    struct No *direita;
} No;

typedef No* Arvore;

// Cria No. Lembrar de usar free(No)
No* novoNo(Chave chave, Item conteudo, int digito);

int pegaDigito(int chave, int digito);

//Busca a chave desejada na árvore
No* busca(Arvore raiz, Chave chave);

//Busca a chave desejada na árvore
No* buscaR(Arvore raiz, Chave chave, int digitoAnterior);

//Insere novo Nó na árvore
void inserir(Arvore raiz, Chave chave, Item conteudo);

//Insere novo Nó na árvore
Arvore insereR(Arvore raiz, No* novo, int digitoDif, No* pai);

//Imprime árvore com base no Nó
void imprimeArvore(No* raiz, int space);

// Libera a memória utilizada pra armazenar a árvore
void freeArvore(Arvore arvore);

#endif