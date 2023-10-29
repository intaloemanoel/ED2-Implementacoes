#ifndef TABELAHASH_H
#define TABELAHASH_H

//Imprime a tabela Hash
void imprimir_tabela(int *Hash, int tamanho);

//Função de Hash default
int hash(int chave, int tamanho);

//Função de Hash para Dispersão Dupla
int hash2(int chave, int tamanho);

//Função de hash por tentativa linear
int tentativaLinear(int hash, int i, int tamanho);

//Função de hash por tentativa linear
int tentativaQuadratica(int hash, int i, int tamanho);

//Busca a chave na tabela
int buscaTabela(int *Hash, int chave, int tamanho);

//Busca a chave na tabela
int buscarChave(int *Hash, int chave, int tamanho);

//Calcular o fator de carga
float calcular_fatorDeCarga();

//Insere na tabela por meio da tentativa linear
void inserirTentativaLinear(int *Hash, int chave, int tamanho);

//Insere na tabela por meio da tentativa quadrática
void inserirTentativaQuadratica(int *Hash, int chave, int tamanho);

//Insere na tabela por meio da Dispersão Dupla
void inserirDispersaoDupla(int *Hash, int chave, int tamanho);

// Retorna a quantidade de colisões
int retornarColisoes();

//Excluir chave aleatória
void excluirChave(int *Hash, int tamanho);



#endif