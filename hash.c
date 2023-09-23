#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "hash.h"

int posicao_hash(int chave, int tamanho){
    return chave % tamanho;
}

Cliente* inicializaTabela(int tamanho){
    

    for(int i = 0; i < tamanho; i++){
    	Hash[i].proximo = NULL;
    }

    return Hash;
}