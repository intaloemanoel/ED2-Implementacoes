#ifndef HASH_H
#define HASH_H

#include "cliente.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct TabelaHash {
    int tamanho;
    Cliente* clientes;
} TabelaHash;

typedef struct Elemento {
    Elemento* proximo;
    Cliente cliente;
} Elemento;

int funcao_hash(int chave, int tamanho);

TabelaHash* cria_tabela(int tamanho);
TabelaHash* insere_cliente_na_tabela_hash(Cliente cliente);


#endif