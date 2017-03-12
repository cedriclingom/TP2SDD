#compilateur

CC = gcc

#Profileur

VG = valgrind

#Option

CFLAGS = -ansi -pedantic -Wall -Wextra -g -O2
LDFLAGS = -lm

#liste des fichiers objets

OBJ = main.o pile.o truc.o


#Règle d'éxécution
exe : main
	./main

#Regle de production de l'exécutable

main : $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS) $(LDFLAGS)


#Règle de production des fichiers objets


main.o: main.c pile.h
	$(CC) -c main.c $(CFLAGS) $(LDFLAGS)

pile.o: pile.c pile.h 
	$(CC) -c pile.c $(CFLAGS) $(LDFLAGS)

truc.o: truc.c truc.h
	$(CC) -c truc.c $(CFLAGS) $(LDFLAGS)

#Regle pour nettoyer

clean :
	rm $(OBJ) *.*~

#Regle d'utilisation de valgrind

valgrind:
	$(VG) ./main

