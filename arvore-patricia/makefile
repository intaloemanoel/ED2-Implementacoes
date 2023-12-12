# O alvo principal é o executável
all: main

# Compila o arquivo de origem C em um arquivo objeto
main: main.c arvorePatricia.o
	gcc -o impQuatro main.c arvorePatricia.o

arvorePatricia.o: arvorePatricia.c 
	gcc -c -o arvorePatricia.o arvorePatricia.c

clean:
	rm -f *.o
