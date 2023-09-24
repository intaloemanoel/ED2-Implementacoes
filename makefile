# O alvo principal é o executável
all: main

# Compila o arquivo de origem C em um arquivo objeto
main: main.c cliente.o hash.o
	gcc -o impUm main.c cliente.o hash.o

cliente.o: cliente.c
	gcc -c -o cliente.o cliente.c

hash.o: hash.c 
	gcc -c -o hash.o hash.c

# Remove todos os arquivos temporários
clean:
	rm -f main
