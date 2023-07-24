etapa1: main.o hash.o lex.yy.o
	gcc -o etapa1 main.o hash.o lex.yy.o
	
main.o: main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c
	
lex.yy.c: scanner.l
	flex --header-file=lex.yy.h scanner.l

clean:
	rm -f *.o lex.yy.c lex.yy.h etapa1
