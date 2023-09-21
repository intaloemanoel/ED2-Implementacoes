#ifndef HASH_H
#define HASH_H

#include "cliente.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct TabelaHash {
    int tamanho;
    Cliente* clientes;
} TabelaHash;

int funcao_hash(int chave, int tamanho);

TabelaHash* cria_tabela(int tamanho);

#endif