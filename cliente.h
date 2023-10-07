#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Cliente {
    int cod;
    char nome[100];
    int prox;
    bool status;
} Cliente;

// Cria cliente. Lembrar de usar free(cliente)
Cliente *cliente(int cod, char *nome, int prox, bool status);

// Imprime Cliente
void imprime(Cliente *cli);

// Salva cliente no arquivo out, na posicao atual do cursor
void salvar_cliente(Cliente *cli, FILE *out);

// Le um cliente do arquivo in na posicao atual do cursor
// Retorna um ponteiro para cliente lido do arquivo
Cliente *ler_cliente(FILE *in);

// Retorna tamanho do cliente em bytes
int tamanho();

#endif