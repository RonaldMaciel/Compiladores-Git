FLAGS = -g
SRC = main.c lex.yy.c y.tab.c decompiler.c hash.c ast.c tacs.c

etapa: clean lex.yy.c y.tab.c
	gcc $(FLAGS) $(SRC) -o etapa5

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l 
	lex scanner.l 

test:
	./etapa5 input.txt output.txt
	./etapa5 output.txt output2.txt
	diff output.txt output2.txt

entrega:
	tar cvzf etapa5.tgz .

clean: 
	rm -f etapa5 lex.yy.c y.tab.c y.tab.h etapa5.tgz *.o out*.txt
