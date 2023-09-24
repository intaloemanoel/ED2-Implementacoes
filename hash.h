#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int pos_hash(int chave, int tamanho);

Cliente* inicializa_tabela(Cliente* Hash, int tamanho);

Cliente* insere_cliente(Cliente* cli, Cliente** Hash, int tamanho);

void libera_tabela(Cliente** Hash, int tamanho);

#endif