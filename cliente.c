#include "cliente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Cria cliente. Lembrar de usar free(cliente)
Cliente *cliente(int cod, char *nome, int prox, bool status){
    Cliente *cli = (Cliente *) malloc(sizeof(Cliente));

    if (cli){
        memset(cli, 0, sizeof(Cliente));
    }

    cli->cod = cod;
    strcpy(cli->nome, nome);
    cli->prox = prox;
    cli->status = status;
    return cli;
}

// Imprime cliente
void imprime(Cliente *cli) {
    printf("\n**********************************************");
    printf("\nCliente de Codigo: %d", cli->cod);
    printf("\nNome: %s", cli->nome);
    printf("\nPROXIMO CLIENTE: %d", cli->prox);
    printf("\nSTATUS: %d", cli->status);
    printf("\n**********************************************\n");
}

// Salva cliente no arquivo out, na posicao atual do cursor
void salvar_cliente(Cliente *cli, FILE *out, int pos) {
    if(pos == -1){
        //Salvar no final do arquivo
        fseek(out, 0, SEEK_END);
    }
    else{
        //Sobrescrever o arquivo na posicao pos
        fseek(out, pos * tamanho_cliente(), SEEK_SET);
    }
    
    fwrite(&cli->cod, sizeof(int), 1, out);
    fwrite(cli->nome, sizeof(char), sizeof(cli->nome), out);
    fwrite(&cli->prox, sizeof(int), 1, out);
    fwrite(&cli->status, sizeof(bool), 1, out);
}


// Le um cliente do arquivo in na posicao atual do cursor
// Retorna um ponteiro para cliente lido do arquivo
Cliente *ler_cliente(FILE *in) {
    Cliente *cli = (Cliente *) malloc(sizeof(Cliente));

    if (0 >= fread(&cli->cod, sizeof(int), 1, in)) {
        free(cli);
        return NULL;
    }
    
    fread(cli->nome, sizeof(char), sizeof(cli->nome), in);
    fread(&cli->prox, sizeof(int), 1, in);
    fread(&cli->status, sizeof(bool), 1, in);
    return cli;
}

//Le todos os clientes do arquivo
void ler_clientes(FILE *in) {
    printf("\nLendo clientes do arquivo...\n");
    rewind(in);

    Cliente *cli;

    int i = 0;
    while ((cli = ler_cliente(in)) != NULL) {
        printf("\nPosicao %d no arquivo cliente.dat", i);
        imprime(cli);
        free(cli);
        i++;
    }
}

//Pega a posicao do cliente no arquivo
int arquivo_pos(FILE *in, int cod){
    rewind(in);

    int i = 0;
    Cliente *cli;
    while ((cli = ler_cliente(in)) != NULL) {
        if(cli->cod == cod){
            printf("\nCliente %d está na posicao %d\n", cod, i);
            imprime(cli);
            free(cli);
            return i;
        }
        else{
            i++;
            free(cli);
        }
    }

    return -1;
}

// Retorna tamanho do cliente em bytes
int tamanho_cliente() {
    return sizeof(int)
            + sizeof(char) * 100 
            + sizeof(int)
            + sizeof(bool);
}