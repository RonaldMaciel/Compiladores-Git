/* Autor: Ronald de Souza Maciel - 00281987 */

#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern FILE* file();
extern int yyparse();

extern int isRunning();
extern int getLineNumber(void);

extern void initMe();
extern void hashPrint();

int main(int argc, char** argv) {

  int token;

  if (argc < 2) {
    fprintf(stderr, "Call program with: ./etapa2 filename.txt\n");
    return 1;
  }

  if (0 == (yyin = fopen(argv[1], "r"))) {
        printf("Failed to open file %s \n", argv[1]);
        return 2;
    }

  initMe();

  yyparse();
    
  printf("\nHash table: \n");
  hashPrint();
  fprintf(stderr, "Successully compiled!\n");
  
  return 0;
}