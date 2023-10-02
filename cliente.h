#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdlib.h>
#include <stdio.h>

// Definicao do cliente
typedef struct Cliente {
    int cod;
    char nome[100];
    struct Cliente *proximo;
} Cliente;

// Imprime cliente
void imprimir(Cliente *cli);

// Cria cliente
Cliente *cliente(int cod, char *nome);

// Salva cliente no arquivo out, na posicao atual do cursor
void salvar(Cliente *cli, FILE *out);

// Le um cliente do arquivo in na posicao atual do cursor
// Retorna um ponteiro para cliente lido do arquivo
Cliente *ler(FILE *in);

// Retorna tamanho do cliente em bytes
int tamanho();

void sobrescreve_cliente_no_arquivo(FILE *out, int posicao, cliente* cliente);

#endif