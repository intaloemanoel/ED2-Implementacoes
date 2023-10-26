# O alvo principal é o executável
all: main

# Compila o arquivo de origem C em um arquivo objeto
main: main.c tabelaHash.o
	gcc -o impTres main.c tabelaHash.o

compartimento_hash.o: tabelaHash.c 
	gcc -c -o tabelaHash.o tabelaHash.c
