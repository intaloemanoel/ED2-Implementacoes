#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

//Função de hashing
int pos_hash(int chave, int tamanho);

//Inicializa tabela com -1 no tamanho desejado
int inicializa_tabela(FILE* tabHash);

//Salva a tabela hash com um cliente na posicao desejada
void salvar_tabHash(FILE *out, int cli, int pos);

//Imprime toda a tabela hash
int imprime_tabela(FILE *tabHash);

//Retorna o valor que está na tabela Hash posicao do cursor
int ler_valorHash(FILE *tabHash);

//Verifica se o cliente existe atualmente na tabela hash
int busca_cliente_tabelaHash(FILE *tabHash, int cod, int hash, int tamanho);

//Insere um cliente novo na tabela Hash
void insere_cliente(FILE* tabHash, char nome[], int cod, int tamanho, int posCliente);

//Exclui um cliente na tabela Hash
void excluir_cliente(FILE* clientes, int cod, int tamanho, int posicao);

int compara_cliente_temporario(Cliente* cli, Cliente* cliTemp, int tamanho);

int buscar_pos_cliente(FILE *tabHash, int cod);

#endif