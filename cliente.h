#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Cliente {
    int cod;
    char nome[100];
    struct Cliente *proximo;
} Cliente;

// Imprime funcionario
void imprimir(Cliente *cli);

// Cria funcionario. Lembrar de usar free(funcionario)
Cliente *cliente(int cod, char *nome);

// Salva funcionario no arquivo out, na posicao atual do cursor
void salvar(Cliente *cli, FILE *out);

// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
Cliente *ler(FILE *in);

// Retorna tamanho do funcionario em bytes
int tamanho();

void sobrescreve_cliente_no_arquivo(FILE *out, int posicao, cliente* cliente) ;

#endif