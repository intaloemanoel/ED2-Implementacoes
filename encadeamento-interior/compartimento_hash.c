#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    Cliente* cli;
    
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
            cli = (Cliente*)malloc(sizeof(Cliente));
            cli = cliente(-1, "", i, 0);
            salvar_cliente(cli, tabHash, i);
        }

        printf("\nTabela Hash inicializada com tamanho %d\n", tamanhoTabela);
    }

    return tamanhoTabela;
}

//Imprime toda a tabela hash
int imprime_tabela(FILE *tabHash){
    rewind(tabHash);

    Cliente* cli;
    int tamanhoTabela = 0;
    while ((cli = ler_cliente(tabHash)) != NULL) {
        imprime(cli);
        tamanhoTabela++;
    }

    return tamanhoTabela;
}

//Retorna o valor que está na tabela Hash posicao do cursor
int ler_valorHash(FILE *tabHash) {
    Cliente* cli = ler_cliente(tabHash);

    if (cli == NULL) {
        free(cli);
        return -2;
    }

    free(cli);
    return cli->cod;
}

//Verifica se o cliente existe atualmente na tabela hash
int busca_cliente_tabelaHash(FILE *tabHash, int cod, int hash, int tamanho){
    rewind(tabHash);
    
    tamanho -= 1;
    int i = 0;
    int canExit = 0;
    int loopTabela = 0;
    Cliente *cli;
    while(loopTabela < 2){
        while ((cli = ler_cliente(tabHash)) != NULL) {
                int flagTemp = cli->flag;

                if(flagTemp == 0 && canExit == 1) {
                    free(cli);
                    //Cliente nao existe na tabela, mas sua pos hash esta ocupada, sera inserido na primeira posicao vazia
                    return i;
                }

                if(cli->cod == cod && flagTemp == 1){
                    free(cli);
                    //Cliente ja existe e esta atualmente na tabela hash
                    return -2;
                }
                else{
                    if(i == hash) {
                        if(flagTemp == 0) {
                            free(cli);
                            //Cliente nao existe na tabela e posicao esta liberada
                            return -1;
                        }
                        canExit = 1;
                    }
                    i++;
                    free(cli);
                }
            }

        loopTabela++;
        rewind(tabHash);
        i = 0;
    }

    //Nao existe entao retorna -3
    return -3;
}
// Verifica se cliente e cliente temporario posuem mesmo hash, se o prox esta com a posicao padrão e se esta ocipado
// retorna 1 se sim e 0 se nao
int compara_cliente_temporario(Cliente* cli, Cliente* cliTemp, int tamanho) {
    int hashTemp = pos_hash(cliTemp->cod, tamanho);
    int hashCli = pos_hash(cli->cod, tamanho);

    if((hashCli == hashTemp) && cliTemp->prox == hashTemp && cliTemp->flag == 1){
        return 1;
    }
    return 0;
}

//Insere um cliente novo na tabela Hash
void insere_cliente(FILE* tabHash, char nome[], int cod, int tamanho, int posCliente){
    int posHash = pos_hash(cod, tamanho);

    rewind(tabHash);
    fseek(tabHash, posHash * tamanho_cliente(), SEEK_SET); //cursor do tabHash na posHash
    
    int cliPos = ler_valorHash(tabHash);

    Cliente* cli = (Cliente*)malloc(sizeof(Cliente));
    cli = cliente(cod, nome, posCliente, 1);
    salvar_cliente(cli, tabHash, posCliente);

    if(cliPos == -1){
        //Está livre entao é só inserir
        int newClientePos = arquivo_pos(tabHash, cod);

        printf("✅ Cliente %d:%s inserido na posicao %d da Tabela Hash!\n", cli->cod, cli->nome, newClientePos);
        free(cli);
    }
    else if(cliPos == -2){
        //Está lendo fora do arquivo
        printf("❌ ERRO: Não foi possivel ler o arquivo de Tabela Hash\n");
        exit(1);
    }
    else{
        Cliente *cliTemp;
        fseek(tabHash, 0 * tamanho_cliente(), SEEK_SET); //cursor do tabHash na posicao inicial do arquivo
        int canExit =0;
        int posicao = 0;
        while(((cliTemp = ler_cliente(tabHash)) != NULL) && canExit == 0 ){
            if(compara_cliente_temporario(cli, cliTemp, tamanho) == 1){
                Cliente* cliToUpdate = cliente(cliTemp->cod, cliTemp->nome, posCliente, cliTemp->flag);
                imprime(cliToUpdate);
                salvar_cliente(cliToUpdate, tabHash, posicao);
                printf("✅ Cliente %d:%s inserido na posicao %d do arquivo TabHash e é o próximo cliente do cliente %d da posição %d da tabela Hash\n", cli->cod, cli->nome, posCliente, cliToUpdate->cod, posHash);
                canExit = 1;
            }
            posicao++;

            free(cliTemp);
        }
    }
}

//Busca a posicao do cliente
int buscar_pos_cliente(FILE *tabHash, int cod){
    rewind(tabHash);

    int posicao = 0;
    int canExit = 0;
    Cliente *cli;
    while ((cli = ler_cliente(tabHash)) != NULL) {
        if (cli->cod == cod) {
            return posicao;
        }
        posicao++;
        free(cli);
    }

    //Nao existe entao retorna -1
    return -1;
}



//Exclui um cliente na tabela Hash
void excluir_cliente(FILE* tabHash, int cod, int tamanho, int posCliente){
    int posHash = pos_hash(cod, tamanho);

    rewind(tabHash);

    fseek(tabHash, posCliente * tamanho_cliente(), SEEK_SET);
    Cliente* pCli = ler_cliente(tabHash);
    Cliente* pCliToUpdate = cliente(pCli->cod, pCli->nome, pCli->prox, 0);
    salvar_cliente(pCliToUpdate, tabHash, posCliente);
    printf("Cliente de código %d que estava na posicao %d excluido com sucesso!", cod, posCliente);

    free(pCliToUpdate);
    free(pCli);
}
