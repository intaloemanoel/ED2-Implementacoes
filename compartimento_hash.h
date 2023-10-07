#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

int pos_hash(int chave, int tamanho);

int inicializa_tabela(FILE* tabHash);

int imprime_tabela(FILE *tabHash);

int ler_valorHash(FILE *tabHash);

int ler_nPos(FILE *tabHash);


#endif