#ifndef TABELAHASH_H
#define TABELAHASH_H

//Imprime a tabela Hash
void imprimir_tabela(int *Hash, int tamanho);

//Função de Hash default
int hash(int chave, int tamanho);

//Função de hash por tentativa linear
int tentativaLinear(int hash, int i, int tamanho);

//Busca a chave na tabela
int buscaTabela(int *Hash, int chave, int tamanho);

//Insere na tabela por meio da tentativa linear
void inserirTentativaLinear(int *Hash, int chave, int tamanho);

#endif