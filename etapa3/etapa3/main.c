/* Autor: Ronald de Souza Maciel - 00281987 */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "decompiler.h"

extern FILE *yyin;
extern FILE* file();
extern int yyparse();

extern int isRunning();
extern int getLineNumber();
extern int getNumberOfErrors();

extern void initMe();
extern void hashPrint();

extern AST *root;

FILE* initFile(char *file, char *modes) {
    FILE *fileInput;
    if ((fileInput = fopen(file, modes)) == NULL) {
        perror("Error opening ffile");
        exit(2);
    }
    return fileInput;
}

int main(int argc, char** argv) {

    if (argc < 3) {
        printf("Call program with: ./etapa3 sample.txt output.txt\n");
        exit(1);
    }
    
    initMe();

    FILE *inputFile = initFile(argv[1], "r");
    FILE *outputFile = initFile(argv[2], "w");
    yyin = inputFile;
    
    yyparse();

    hashPrint();
    astPrint(root, 0);
    decompileRoot(root, outputFile);

  printf("Number of lines: %d\n\n", getLineNumber());
  printf("Number of errors: %d\n\n", getNumberOfErrors());

  fprintf(stderr, "Compilation Completed Successfully!\n\n");
  
  return 0;
}