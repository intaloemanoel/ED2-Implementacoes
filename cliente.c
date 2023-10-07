#include "cliente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

// Imprime funcionario
void imprime(Cliente *cli) {
    printf("\n**********************************************");
    printf("\nFuncionario de Codigo: ");
    printf("%d", cli->cod);
    printf("\nNome: ");
    printf("%s", cli->nome);
    printf("\nPROXIMO CLIENTE: ");
    printf("%d", cli->prox);
    printf("\nSTATUS: ");
    printf("%d", cli->status);
    printf("\n**********************************************\n");
}

// Salva cliente no arquivo out, na posicao atual do cursor
void salvar_cliente(Cliente *cli, FILE *out) {
    fwrite(&cli->cod, sizeof(int), 1, out);
    fwrite(cli->nome, sizeof(char), sizeof(cli->nome), out);
    fwrite(&cli->prox, sizeof(int), 1, out);
    fwrite(&cli->status, sizeof(bool), 1, out);
}


// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
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

void le_clientes(FILE *in) {
    printf("\n\nLendo clientes do arquivo...\n\n");
    rewind(in);
    Cliente *cli;
    while ((cli = ler_cliente(in)) != NULL) {
        imprime(cli);
        free(cli);
    }
}

int get_arquivo_pos(FILE *in,int cod){
    printf("\nPegando pos de %d...\n", cod);
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

// Retorna tamanho do clientepai em bytes
int tamanho() {
    return sizeof(int)
            + sizeof(char) * 100 
            + sizeof(int)
            + sizeof(bool);
}