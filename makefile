# O alvo principal é o executável
all: main

# Compila o arquivo de origem C em um arquivo objeto
main: main.c cliente.o compartimento_hash.o
	gcc -o impUm main.c cliente.o compartimento_hash.o

cliente.o: cliente.c
	gcc -c -o cliente.o cliente.c

compartimento_hash.o: compartimento_hash.c 
	gcc -c -o compartimento_hash.o compartimento_hash.c

# Remove todos os arquivos temporários
clean:
	rm -f main
