#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "compartimento_hash.h"

//Função de hashing
int pos_hash(int chave, int tamanho){
    return chave % tamanho;
}

//Inicializa tabela com -1 no tamanho desejado
int inicializa_tabela(FILE* tabHash){
    printf("🔄️ Carregando arquivo tabela Hash...\n");
    rewind(tabHash);

    int cliCod;
    int tamanhoTabela;
    
    if (0 != fread(&cliCod, sizeof(int), 1, tabHash)) {
        printf("Reutilizando tabela Hash do diretório atual:\n");
        tamanhoTabela = imprime_tabela(tabHash);
        return tamanhoTabela;
    }
    else{
        printf("Criando nova tabela Hash\n");
        printf("Qual será o tamanho da tabela hash?\n");
        printf("📏 Tamanho ");
        scanf("%d", &tamanhoTabela);
    

        int cliNull = -1;
        for(int i = 0; i < tamanhoTabela; i++){
            fwrite(&cliNull, sizeof(int), 1, tabHash);
        }

        printf("\nTabela Hash inicializada com tamanho %d\n", tamanhoTabela);
    }

    return tamanhoTabela;
}

//Salva a tabela hash com um cliente na posicao desejada
void salvar_tabHash(FILE *out, int cli, int pos){
    rewind(out);
    
    fseek(out, pos * sizeof(int), SEEK_SET);
    
    fwrite(&cli, sizeof(int), 1, out);
}

//Imprime toda a tabela hash
int imprime_tabela(FILE *tabHash){
    rewind(tabHash);

    int cliCod;
    int tamanhoTabela = 0;
    while ((cliCod = ler_valorHash(tabHash)) != -2) {
        printf("[%d]: %d \n", tamanhoTabela, cliCod);
        tamanhoTabela++;
    }

    return tamanhoTabela;
}

//Retorna o valor que está na tabela Hash posicao do cursor
int ler_valorHash(FILE *tabHash) {
    int cliCod;

    if (0 >= fread(&cliCod, sizeof(int), 1, tabHash)) {
        return -2;
    }

    return cliCod;
}

//Verifica se o cliente existe atualmente na tabela hash
int busca_cliente_tabelaHash(FILE *clientes, int cod){
    rewind(clientes);

    int i = 0;
    Cliente *cli;
    while ((cli = ler_cliente(clientes)) != NULL) {
        if(cli->cod == cod){
            if(cli->status == false){
                free(cli);
                //Cliente existe e esta atualmente na tabela hash
                return cod;
            }
            else{
                free(cli);
                //Cliente existe no arquivo mas foi liberado
                return -2;
            }
        }
        else{
            i++;
            free(cli);
        }
    }

    //Nao existe entao retorna -1
    return -1;
}

//Insere um cliente novo na tabela Hash
void insere_cliente(FILE* tabHash, FILE* clientes, char nome[], int cod, int tamanho, int posCliente){
    int posHash = pos_hash(cod, tamanho);

    rewind(tabHash);
    fseek(tabHash, posHash * sizeof(int), SEEK_SET); //cursor do tabHash na posHash
    
    int cliPos = ler_valorHash(tabHash);
    if(cliPos == -1){
        //Está livre entao é só inserir
        Cliente* cli = (Cliente*)malloc(sizeof(Cliente));
        cli = cliente(cod, nome, -1, false);
        salvar_cliente(cli, clientes, posCliente);

        int newClientePos = arquivo_pos(clientes, cod);

        printf("✅ Cliente %d:%s inserido na posicao %d do arquivo Cliente e esta na posicao %d da tabela Hash\n", cli->cod, cli->nome, newClientePos, posHash);

        salvar_tabHash(tabHash, newClientePos, posHash);
        free(cli);
    }
    else if(cliPos == -2){
        //Está lendo fora do arquivo
        printf("❌ ERRO: Não foi possivel ler o arquivo de tabela Hash\n");
        exit(1);
    }
    else{
        Cliente* cli = (Cliente*)malloc(sizeof(Cliente));
        cli = cliente(cod, nome, -1, false);
        salvar_cliente(cli, clientes, posCliente);

        bool exit = true;
        while(exit == true){
            fseek(clientes, cliPos * tamanho_cliente(), SEEK_SET);
            Cliente *cliTemp = ler_cliente(clientes);

            if(cliTemp->prox == -1){
                int newClientePos = arquivo_pos(clientes, cod);
                cliTemp->prox = newClientePos;
                salvar_cliente(cliTemp, clientes, cliPos);
                printf("✅ Cliente %d:%s inserido na posicao %d do arquivo Cliente e é o próximo cliente do cliente %d da posição %d da tabela Hash\n", cli->cod, cli->nome, newClientePos, cliTemp->cod, posHash);
                exit = false;
            }
            else{
                cliPos = cliTemp->prox;
            }

            free(cliTemp);
        }
    }
}

//Exclui um cliente na tabela Hash
void excluir_cliente(FILE* tabHash, FILE* clientes, int cod, int tamanho){
    int posHash = pos_hash(cod, tamanho);

    rewind(tabHash);
    fseek(tabHash, posHash * sizeof(int), SEEK_SET); //cursor do tabHash na posHash

    int atual = ler_valorHash(tabHash);
    int anterior = -1;
    Cliente* pCli;
    Cliente* cliAtual;

    bool exit = true;
    while(exit == true){
        fseek(clientes, atual * tamanho_cliente(), SEEK_SET);
        pCli = ler_cliente(clientes);

        if(pCli->cod != cod){  
            anterior = atual;
            atual = pCli->prox;
        }
        else{
            break;
        }
    }

    if(anterior == -1){
        fseek(clientes, atual * tamanho_cliente(), SEEK_SET);
        cliAtual = ler_cliente(clientes);
        cliAtual->status = true; //Libera cliente no arquivo cliente
        salvar_cliente(cliAtual, clientes, atual);

        salvar_tabHash(tabHash, cliAtual->prox, posHash);
        printf("✅ O cliente de código %d foi excluido\n", cliAtual->cod);
        free(cliAtual);
        return;
    }
    else{
        fseek(clientes, atual * tamanho_cliente(), SEEK_SET);
        cliAtual = ler_cliente(clientes);
        cliAtual->status = true; //Libera cliente no arquivo cliente
        salvar_cliente(cliAtual, clientes, atual);

        fseek(clientes, anterior * tamanho_cliente(), SEEK_SET);
        Cliente* cliTemp = ler_cliente(clientes);
        cliTemp->prox = cliAtual->prox;
        salvar_cliente(cliTemp, clientes, anterior);

        salvar_tabHash(tabHash, anterior, posHash);
        printf("✅ O cliente de código %d foi excluido\n", cliAtual->cod);
        free(cliAtual);
        free(cliTemp);
    }

    free(pCli);
}
