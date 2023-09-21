#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

void insereCliente(FILE *out){
    printf("Inserindo cliente no arquivo...");
    
    Cliente *c1 = cliente(1, "Teste");
    salvar(c1, out);
    free(c1);
}

void le_cliente(FILE *in) {
    printf("\n\nLendo clientes do arquivo...\n\n");
    rewind(in);
    Cliente *c;
    while ((c = ler(in)) != NULL) {
        imprimir(c);
        free(c);
    }
}

void main(int argc, char** argv) {
    FILE *out;

    if ((out = fopen("cliente.dat", "w+b")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    } else {
        
        insereCliente(out);
        le_cliente(out);

        fclose(out);    
    }



}