#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "compartimento_hash.h"

void inserir(FILE *tabHash, FILE *cliente, int tamanho){
    int cod;
    char nome[100];
    
    printf("-------- INSERIR CLIENTE --------\n");
    printf("Qual é o código do cliente que deseja inserir?\n");
    printf("🔢 Código: ");
    scanf("%d", &cod);
    
    printf("Qual é o nome do cliente que deseja inserir?\n");
    printf("✍️ Nome: ");
    scanf("%s", nome);

    //alexia comments: começando pelo o que eu entendi que vc esta fazendo

    //Verificar se o cliente já está inserido
    int tabHashPos = pos_hash(cod, tamanho); //Pegar a posição na tabela Hash
    //alexia comments: na linha abaixo vc verifica se o cliente ja esta na tabela, ao meu ver, se ja esta nao precisamos inserir
    int clientePos = get_arquivo_pos(tabHash, cod); //Pegar a posição no arquivo de clientes

    //alexia comments: se a funcao da linha 24 nao encontra o cliente na tabela hash ele retorna -1 por isso do if
    //alexia comments: se for -1 nao esta na tabela e vamos inserir, caso contrario ja esta na tabela
    if (clientePos == -1) {
        //alexia comments: (linha de baixo) inicia o ponteiro do novo cliente
        Cliente* cli = (Cliente*)malloc(sizeof(Cliente));
        //alexia comments: (linha de baixo) cria o cliente
        cli = cliente(cod, nome, -1, false);
        printf("\nO seguinte cliente será inserido na tabela:\n");
        imprime(cli);
        //alexia comments:(linha de baixo) inicia o fluxo de inserir o novo cliente
        insere_cliente(cli, tabHash, tamanho;)

    } else {
        printf("\n❌ ERRO: Já existe cliente com este código.\n");
    }


    /*
    if(cliente != -1){
        Cliente* cli = (Cliente*)malloc(sizeof(Cliente));
        cli = cliente(cod, nome);
        printf("\nO seguinte cliente será inserido na tabela:\n");
        imprimir(cli);

        insere_cliente(cli, Hash, tamanho, out, outHash);
    } else{
        printf("\n❌ ERRO: Já existe cliente com este código.\n");
    }*/
    
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

            if(opcao < 1 || opcao > 6){
                printf("%d não é valido. Por favor, utilize uma das opções abaixo.\n", opcao);
                continue;
            }

            switch (opcao){
            case 1:
                inserir(outClientes, tamanhoTabela);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("✅ Execução concluida\n");
                fclose(outClientes);
                fclose(outTabHash); 
                exit(1);
                break;
            }
        }
}

/*
        Cliente *cli = cliente(1,"Alexia", -1, true);
        Cliente *cliUm = cliente(2,"Italo", 0, true);
        salvar_cliente(cli, out);
        salvar_cliente(cliUm, out);
        free(cli);
        free(cliUm);*/

        //le_clientes(out);
        //get_arquivo_pos(out, 2); */

