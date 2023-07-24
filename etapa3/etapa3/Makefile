etapa3: clean main.o y.tab.o lex.yy.o decompiler.o hash.o ast.o
	gcc main.o lex.yy.o y.tab.o decompiler.o hash.o ast.o -o etapa3

main.o: main.c
	gcc -c main.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

decompiler.o: decompiler.c
	gcc -c decompiler.c

hash.o: hash.c
	gcc -c hash.c

ast.o: ast.c
	gcc -c ast.c

y.tab.c: parser.y
	yacc -d -v parser.y

lex.yy.c: scanner.l 
	flex --header-file=lex.yy.h scanner.l

entrega:
	tar cvzf etapa3.tgz .

clean:
	rm -f *.o etapa3 lex.yy.c lex.yy.h y.tab.c y.tab.h y.output etapa3.tgz
