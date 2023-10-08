#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "compartimento_hash.h"

void inserir(FILE *tabHash, FILE *clientes, int tamanho){
    int cod;
    char nome[100];
    
    printf("-------- INSERIR CLIENTE --------\n");
    printf("Qual é o código do cliente que deseja inserir?\n");
    printf("🔢 Código: ");
    scanf("%d", &cod);
    
    printf("Qual é o nome do cliente que deseja inserir?\n");
    printf("✍️ Nome: ");
    scanf("%s", nome);

    int existeCliente = busca_cliente_tabelaHash(clientes, cod);

    if(existeCliente == -1){
        insere_cliente(tabHash, clientes, nome, cod, tamanho, -1);
    }
    else if(existeCliente == -2){
        int posCliente = arquivo_pos(clientes, cod);
        insere_cliente(tabHash, clientes, nome, cod, tamanho, posCliente);
    }
    else{
        printf("\n❌ ERRO: Já existe cliente com este código na tabela Hash.\n");
    }
    
}

void buscar(FILE* clientes){
    int cod;

    printf("-------- BUSCAR CLIENTE --------\n");
    printf("Qual é o código do cliente que deseja buscar?\n");
    printf("🔢 Código: ");
    scanf("%d", &cod);

    int resultadoBusca = busca_cliente_tabelaHash(clientes, cod);

    if(resultadoBusca == -1){
        printf("❌ O cliente de código %d não existe\n", cod);
    }
    else if(resultadoBusca == -2){
        printf("🚩 O cliente de código %d existe no arquivo de Clientes mas não existe na tabela Hash\n", cod);
        arquivo_pos(clientes, cod);
    }
    else{
        printf("✅ O cliente de código %d existe na tabela Hash\n", cod);
        arquivo_pos(clientes, cod);
    }
}

void excluir(FILE *tabHash, FILE *clientes, int tamanho){
    int cod;
    
    printf("-------- EXCLUIR CLIENTE --------\n");
    printf("Qual é o código do cliente que deseja excluir?\n");
    printf("🔢 Código: ");
    scanf("%d", &cod);

    int existeCliente = busca_cliente_tabelaHash(clientes, cod);

    if(existeCliente == -1){
        printf("\n ERRO: Não existe cliente com este código na tabela Hash.\n");
    }
    else{
        excluir_cliente(tabHash, clientes, cod, tamanho);
    }
    
}

void main(int argc, char** argv) {
    //Declara ponteiro para arquivo
    FILE *outClientes;
    FILE *outTabHash;

    outClientes = fopen("clientes.dat", "r+b");
    outTabHash = fopen("tabHash.dat", "r+b");

    printf("-------- TABELA HASH - ENCADEAMENTO EXTERNO --------\n");
    printf("-------- ALEXIA ASSUMPÇÃO, ÍTALO EMANOEL E GUILHERME LOBO--------\n");

    // Verifica se o arquivo clientes foi aberto com sucesso.
    if (outClientes == NULL) {
        // Se o arquivo não existir, ele será criado.
        outClientes = fopen("clientes.dat", "w+b");
        if (outClientes == NULL) {
            printf("❌ Erro ao criar o arquivo de Clientes.\n");
            exit(1);
        }
    }

    // Verifica se o arquivo tabela Hash foi aberto com sucesso.
    if (outTabHash == NULL) {
        // Se o arquivo não existir, ele será criado.
        outTabHash = fopen("tabHash.dat", "w+b");
        if (outTabHash == NULL) {
            printf("❌ Erro ao criar o arquivo de Tabela Hash.\n");
            exit(1);
        }
    }

    int tamanhoTabela = inicializa_tabela(outTabHash);

    int menu = 1;
        int opcao;
        while(menu == 1){
            printf("\n-------- MENU --------\n");
            printf("O que você deseja fazer?\n");
            printf("1 - ➕ Inserir Cliente\n");
            printf("2 - 🔍 Buscar Cliente\n");
            printf("3 - ❌ Remover Cliente\n");
            printf("4 - 🖨️ Imprimir tabela hash\n");
            printf("5 - 🖨️ Imprimir clientes\n");
            printf("6 - 👋 Sair\n");
            printf("Opção: ");
            scanf("%d", &opcao);
            printf("\n");

            if(opcao < 1 || opcao > 6){
                printf("%d não é valido. Por favor, utilize uma das opções abaixo.\n", opcao);
                continue;
            }

            switch (opcao){
            case 1:
                inserir(outTabHash, outClientes, tamanhoTabela);
                break;
            case 2:
                buscar(outClientes);
                break;
            case 3:
                excluir(outTabHash, outClientes, tamanhoTabela);
                break;
            case 4:
                imprime_tabela(outTabHash);
                break;
            case 5:
                ler_clientes(outClientes);
                break;
            case 6:
                printf("✅ Execução concluida\n");
                fclose(outClientes);
                fclose(outTabHash); 
                exit(1);
                break;
            }
        }
}
