#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "compartimento_hash.h"

void inserir(FILE *tabHash, int tamanho){
    int cod;
    char nome[100];
    
    printf("-------- INSERIR CLIENTE --------\n");
    printf("Qual é o código do cliente que deseja inserir?\n");
    printf("🔢 Código: ");
    scanf("%d", &cod);
    
    printf("Qual é o nome do cliente que deseja inserir?\n");
    printf("✍️ Nome: ");
    scanf("%s", nome);

    int hash = pos_hash(cod, tamanho);
    int existeCliente = busca_cliente_tabelaHash(tabHash, cod, hash);

    if(existeCliente == -1){
        insere_cliente(tabHash, nome, cod, tamanho, hash);
    }
    else if (existeCliente == -2 || existeCliente == -3) {
        printf("\n❌ ERRO: Já existe cliente com este código na tabela Hash.\n");
    }
    else{
        insere_cliente(tabHash, nome, cod, tamanho, existeCliente);
    }
    
}

void buscar(FILE* clientes, int tamanho){
    int cod;

    printf("-------- BUSCAR CLIENTE --------\n");
    printf("Qual é o código do cliente que deseja buscar?\n");
    printf("🔢 Código: ");
    scanf("%d", &cod);

    int hash = pos_hash(cod, tamanho);

    int resultadoBusca = busca_cliente_tabelaHash(clientes, cod, hash);

    if(resultadoBusca == -2){
        printf("✅ O cliente de código %d existe!\n", cod);
        arquivo_pos(clientes, cod);
    }
    else{
        printf("❌ O cliente de código %d não existe\n", cod);
    }
}

void excluir(FILE *clientes, int tamanho){
    int cod;
    
    printf("-------- EXCLUIR CLIENTE --------\n");
    printf("Qual é o código do cliente que deseja excluir?\n");
    printf("🔢 Código: ");
    scanf("%d", &cod);

    int hash = pos_hash(cod, tamanho);

    int existeCliente = busca_cliente_tabelaHash(clientes, cod, hash);
    printf("existe Cliente: %d\n", existeCliente);

    if(existeCliente == -1){
        printf("\n ERRO: Não existe cliente com este código na tabela Hash.\n");
    }
    else{
        excluir_cliente(clientes, cod, tamanho);
    }
    
}

void main(int argc, char** argv) {
    //Declara ponteiro para arquivo
    FILE *outTabHash;

    outTabHash = fopen("tabHash.dat", "r+b");

    printf("-------- TABELA HASH - ENCADEAMENTO INTERIOR SEM TRATAMENTO DE COLISAO --------\n");
    printf("-------- ALEXIA ASSUMPÇÃO, ÍTALO EMANOEL E GUILHERME LOBO--------\n");

    // Verifica se o arquivo tabHash foi aberto com sucesso.
    if (outTabHash == NULL) {
        // Se o arquivo não existir, ele será criado.
        outTabHash = fopen("tabHash.dat", "w+b");
        if (outClienoutTabHashtes == NULL) {
            printf("❌ Erro ao criar o arquivo da Tabela Hash.\n");
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
            printf("5 - 👋 Sair\n");
            printf("Opção: ");
            scanf("%d", &opcao);
            printf("\n");

            if(opcao < 1 || opcao > 5){
                printf("%d não é valido. Por favor, utilize uma das opções abaixo.\n", opcao);
                continue;
            }

            switch (opcao){
            case 1:
                inserir(outTabHash, tamanhoTabela);
                break;
            case 2:
                buscar(outTabHash, tamanhoTabela);
                break;
            case 3:
                excluir(outTabHash, tamanhoTabela);
                break;
            case 4:
                imprime_tabela(outTabHash);
                break;
            case 5:
                printf("✅ Execução concluida\n");
                fclose(outTabHash);
                exit(1);
                break;
            }
        }
}
