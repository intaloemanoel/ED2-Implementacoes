#include "cliente.h"
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

// Imprime cliente
void imprimir(Cliente *cli) {
    printf("**********************************************");
    printf("\nCliente de código ");
    printf("%d", cli->cod);
    printf("\nNome: ");
    printf("%s", cli->nome);
    printf("\n**********************************************\n");
}

// Cria cliente. Lembrar de usar free(cli)
Cliente *cliente(int cod, char *nome) {
    Cliente *cli = (Cliente *) malloc(sizeof(Cliente));

    //inicializa espaço de memória com ZEROS
    if (cli){
        memset(cli, 0, sizeof(Cliente));
    }

    //copia valores para os campos de cliente
    cli->cod = cod;
    strcpy(cli->nome, nome);

    return cli;
}

// Salva cliente no arquivo out, na posicao atual do cursor
void salvar(Cliente *cli, FILE *out) {
    fwrite(&cli->cod, sizeof(int), 1, out);

    //func->nome ao invés de &func->nome, pois string já é ponteiro
    fwrite(cli->nome, sizeof(char), sizeof(cli->nome), out);
}

// Le um cliente do arquivo in na posicao atual do cursor
// Retorna um ponteiro para o cliente lido do arquivo
Cliente *ler(FILE *in) {
    Cliente *cli = (Cliente *) malloc(sizeof(Cliente));

    if (0 >= fread(&cli->cod, sizeof(int), 1, in)) {
        free(cli);
        return NULL;
    }

    fread(cli->nome, sizeof(char), sizeof(cli->nome), in);
    return cli;
}

// Retorna tamanho do cliente em bytes
int tamanho() {
    return sizeof(int)  //cod
            + sizeof(char) * 100; //nome
}

Cliente cria_cliente(int cod, char* nome) {
    Cliente cliente;
    cliente.cod = cod;
    cliente.nome = *nome;

    return cliente;
}
