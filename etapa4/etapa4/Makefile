FLAGS = -g
SRC = main.c lex.yy.c y.tab.c decompiler.c hash.c ast.c semantic.c

etapa: clean lex.yy.c y.tab.c
	gcc $(FLAGS) $(SRC) -o etapa4

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l 
	lex scanner.l 

entrega:
	tar cvzf etapa4.tgz .

clean: 
	rm -f etapa4 lex.yy.c lex.yy.h y.tab.c y.tab.h etapa4.tgz *.o