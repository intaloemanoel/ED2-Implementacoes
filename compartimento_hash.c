#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "compartimento_hash.h"

int pos_hash(int chave, int tamanho){
    return chave % tamanho;
}

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
        printf("-------- TABELA HASH - ENCADEAMENTO EXTERNO --------\n");
        printf("-------- ALEXIA ASSUMPÇÃO, ÍTALO EMANOEL E GUILHERME --------\n");
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

int ler_valorHash(FILE *tabHash) {
    int cliCod;

    if (0 >= fread(&cliCod, sizeof(int), 1, tabHash)) {
        return -2;
    }

    return cliCod;
}

int ler_nPos(FILE *tabHash, int pos) {
    printf("\nLendo cliente %d do arquivo...\n", pos);

    fseek(tabHash, pos * tamanho(), SEEK_SET); //cursor do tabHash na pos
    //PAREI AQUIII 
    //AGORA É LER 
}

int buscar_cliente(FILE *tabHash, int tamanho, int tabHashPos, int clientePos){
    rewind(tabHash);

    Cliente* pCli;
    CLIENTE POS NOVO = ler_cliente(tabHash, tabHashPos); 
    IF(CLIENTE POS NOVO = CLIENTE POS){
        EXISTE NA PRIMEIRA POS
    }
    VASCULHAR OS PRÓXIMOS DESTE PRIMEIRO E VER SE TEM O CLIENTEPOS

    /*
    Cliente* pCli = Hash[posHash];
    while (pCli != NULL){
        if(pCli->cod == codigo){
            return pCli;
        }

        pCli = pCli->proximo;
    }*/

    int cliCod;
    int tamanhoTabela = 0;
    while ((cliCod = ler_valorHash(tabHash)) != -2) {
        printf("[%d]: %d \n", tamanhoTabela, cliCod);
        tamanhoTabela++;
    }

    //Cliente não está na tabela Hash
    return -1;
}

void insere_cliente(Cliente* cliente, FILE* in, int tamanho){
    //alexia comments: (linha de baixo) calcula a posicao hash, nao entendi o pq de fazer isso na main entao trouuxe pra ca
    int posHash = pos_hash(cliente->cod, tamanho);
    int posHashTemp;
    int posicao = 0;
    rewind(in);


    Cliente *clienteTemp;
    //alexia comments: (linha de baixo) estou considerando que iniciamos a leitura no inicio do arquivo
    //alexia comments: (linha de baixo) lemos o primeiro cliente
    while ((clienteTemp = ler_cliente(in)) != NULL) {
        //alexia comments: (linha de baixo) verificamos se o posHash do que queremos adicionar é igual ao do que acabamos de ler
        //alexia comments: pq  disso? para vermos se esse cliente tem haver com o que queremos criar
        posHashTemp = pos_hash(clienteTemp->cod, tamanho);
        if (pos_hash == posHashTemp) {
            //alexia comments: sendo um cliente que tem haver com o que queremos adicionar, vericamos se esse ja tem proximo demarcado
            if (clienteTemp->prox == -1) {
                //alexia comments: ele vem para essa linha caso nao tenha, com isso
                //alexia comments: (linha de baixo) setamos o ponteiro do arquivo para o inicio do cliente que encontra nessa posicao
                fseek(in, tamanho() * posicao, SEEK_SET);
                //alexia comments: (linha de baixo) colocamos o prox do cliente que lemos para passar a apontar para nosso novo cliente
                clienteTemp->prox =
                //alexia comments:(linha de baixo) salvamos esse cleinte que lemos novamente, porem dessa vez ele apontara para nosso mais novo cliente
                salvar_cliente(clienteTemp, in);
            }
        }
        posicao = posicao + 1;
    }
    //alexia comments: (linha de baixo) adicionamos o novo cliente no final do arquivo
    salvar_cliente(cliente, in);
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