CC = gcc -Wall
OBJETS = simplexe.o probleme.o pivot.o

simplexe : $(OBJETS)
	$(CC) -o simplexe $(OBJETS)

simplexe.o: simplexe.c simplexe.h probleme.h
	$(CC) -c simplexe.c
	
probleme.o: probleme.c probleme.h
	$(CC) -c probleme.c

pivot.o: pivot.c pivot.h
	$(CC) -c pivot.c

clean:
	rm simplexe $(OBJETS)
