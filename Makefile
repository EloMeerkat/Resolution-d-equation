CC=gcc
CFLAGS=-I. -lm
DEPS = fonctions.h methodes.h
OBJ = main.o fonctions.o methodes.o

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)