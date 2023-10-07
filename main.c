#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "compartimento_hash.h"

void le_clientes(FILE *in) {
    printf("\n\nLendo clientes do arquivo...\n\n");
    rewind(in);
    Cliente *cli;
    while ((cli = ler_cliente(in)) != NULL) {
        imprime(cli);
        free(cli);
    }
}

void get_arquivo_pos(FILE *in,int cod){
    printf("\n\nPegando pos de %d...\n\n", cod);
    rewind(in);

    int i = 0;
    Cliente *cli;
    while ((cli = ler_cliente(in)) != NULL) {
        if(cli->cod == cod){
            printf("\nSou a posicao: %d\n", i);
            imprime(cli);
            break;
        }
        else{
            i++;
            free(cli);
        }
    }
}

void main(int argc, char** argv) {
    //Declara ponteiro para arquivo
    FILE *outClientes;
    FILE *outTabHash;

    outClientes = fopen("clientes.dat", "r+b");
    outTabHash = fopen("tabHash.dat", "r+b");

    // Verifica se o arquivo clientes foi aberto com sucesso.
    if (outClientes == NULL) {
        // Se o arquivo não existir, ele será criado.
        outClientes = fopen("clientes.dat", "w+b");
        if (outClientes == NULL) {
            printf("Erro ao criar o arquivo de Clientes.\n");
            exit(1);
        }
    }

    // Verifica se o arquivo tabela Hash foi aberto com sucesso.
    if (outTabHash == NULL) {
        // Se o arquivo não existir, ele será criado.
        outTabHash = fopen("tabHash.dat", "w+b");
        if (outTabHash == NULL) {
            printf("Erro ao criar o arquivo de Tabela Hash.\n");
            exit(1);
        }
    }

    int tamanhoTabela = inicializa_tabela(outTabHash);


        /*
        Cliente *cli = cliente(1,"Alexia", -1, true);
        Cliente *cliUm = cliente(2,"Italo", 0, true);
        salvar_cliente(cli, out);
        salvar_cliente(cliUm, out);
        free(cli);
        free(cliUm);*/

        //le_clientes(out);
        //get_arquivo_pos(out, 2);
        
    fclose(outClientes);
    fclose(outTabHash); 
}

