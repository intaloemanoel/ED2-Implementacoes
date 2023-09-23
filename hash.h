#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int posicao_hash(int chave, int tamanho);

Cliente* inicializa_tabela(int tamanho);

#endif