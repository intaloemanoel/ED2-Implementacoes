# O alvo principal é o executável
all: main

# Compila o arquivo de origem C em um arquivo objeto
main: main.c cliente.o
	gcc -o impUm main.c cliente.o

cliente.o: cliente.c
	gcc -c -o cliente.o cliente.c

# Remove todos os arquivos temporários
clean:
	rm -f main
