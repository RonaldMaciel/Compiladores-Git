/* Autor: Ronald de Souza Maciel - 00281987 */

#include <stdio.h>
#include "hash.h"
#include <stdlib.h>
#include "decompiler.h"
#include "semantic.h"
#include "ast.h"

extern char *yytext;
extern FILE *yyin;
extern int yylex();
extern int isRunning();
extern void initMe();
extern void hashPrint();
extern int yyparse();
extern int getLineNumber();
extern int checkSemantic();
extern int getNumberOfErrors();
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
        printf("Call program with: ./etapa4 sample.txt output.txt\n");
        exit(1);
    }
    
    initMe();

    FILE *inputFile = initFile(argv[1], "r");
    FILE *outputFile = initFile(argv[2], "w");
    yyin = inputFile;
    
    yyparse();

    // hashPrint();
    astPrint(root, 0);
    decompileRoot(root, outputFile);
    checkSemantic();

    printf("Number of lines: %d\n\n", getLineNumber());
    printf("Number of errors: %d\n\n", getNumberOfErrors());

    fprintf(stderr, "Compilation Completed Successfully!\n\n");
    
  return 0;
}