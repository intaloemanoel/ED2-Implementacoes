#ifndef ARVOREPATRICIA_H
#define ARVOREPATRICIA_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct No {
    //Cada vértice v possui um rótulo r(v) que será usado para “cortar caminho”
    char rotulo[50];
    bool fimDaPalavra;
    struct No *esquerda;
    struct No *direita;
} No;

// Cria No. Lembrar de usar free(No)
No* criaNo(char rotulo[50]);

//Busca a chave desejada na árvore
bool buscaArvore(No *raiz, char chave[50]);

//Insere novo Nó na árvore
No* insereChave(No *raiz, char novaChave[50]);

//Exclui chave desejada da árvore
void excluiChave(No *raiz, char chave[50]);

//Imprime No
void imprimeNo(No *node);

//Imprime árvore com base no Nó
void imprimeArvore(No* raiz, int space);

// Retorna tamanho do No em bytes
int tamanho_no();

#endif