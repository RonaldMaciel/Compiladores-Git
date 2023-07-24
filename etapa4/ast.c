// Abstract Syntax Tree

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

AST *astCreate(int type, HASH_NODE *symbol, 
               AST *s0, AST *s1, AST *s2, AST *s3, int lineNumber){
    AST *newnode;
    newnode = (AST*) calloc(1, sizeof(AST));
    newnode->type = type;
    newnode->lineNumber = lineNumber;
    newnode->symbol = symbol;
    newnode->son[0] = s0;
    newnode->son[1] = s1;
    newnode->son[2] = s2;
    newnode->son[3] = s3;
    return newnode;
}

void astPrint(AST *node, int level){
    if (node == 0)
        return;

    printSpaces(level);
    fprintf(stderr, "ast(");

    switch(node->type){
        case AST_SYMBOL:          fprintf(stderr, "SYMBOL"); break;

        case AST_ATTR:            fprintf(stderr, "ATTR"); break;
        case AST_ARR_ATTR:        fprintf(stderr, "ARR_ATTR"); break;
        case AST_PARAMLIST:       fprintf(stderr, "PARAMLIST"); break;
        case AST_DECLARAT:        fprintf(stderr, "DECLARATION"); break;
        case AST_DECVAR:          fprintf(stderr, "DECVAR"); break;
        case AST_DECFUNC:         fprintf(stderr, "DECFUNC"); break;

        case AST_DECINT:          fprintf(stderr, "DECINT"); break;
        case AST_DECCHAR:         fprintf(stderr, "DECCHAR"); break;
        case AST_DECREAL:         fprintf(stderr, "DECREAL"); break;
        case AST_DECBOOL:         fprintf(stderr, "DECBOOL"); break;

        case AST_IF:              fprintf(stderr, "IF"); break;
        case AST_IFTHEN:          fprintf(stderr, "IF_THEN"); break;
        case AST_IFELSE:          fprintf(stderr, "IF_ELSE"); break;
        case AST_IFLOOP:          fprintf(stderr, "IF_LOOP"); break;
        
        case AST_INPUT:           fprintf(stderr, "INPUT"); break;    
        case AST_OUTPUT:          fprintf(stderr, "OUTPUT"); break;
        case AST_OUTPUTINIT:      fprintf(stderr, "OUTPUTINIT"); break;
        case AST_OUTPUTLIST:      fprintf(stderr, "OUTPUTLIST"); break;
        case AST_RETURN:          fprintf(stderr, "RETURN"); break;

        case AST_LE:              fprintf(stderr, "LE"); break;   
        case AST_GE:              fprintf(stderr, "GE"); break;
        case AST_EQ:              fprintf(stderr, "EQ"); break;        
        case AST_DIF:             fprintf(stderr, "DIF"); break;
        
        case AST_ARRAY:           fprintf(stderr, "ARRAY"); break;
        case AST_ARGINIT:         fprintf(stderr, "ARGINIT"); break;

        case AST_DECARRAY:       fprintf(stderr, "DECLARRAY"); break;
        case AST_INIT_ARRAY:      fprintf(stderr, "INIT_ARRAY"); break;
        case AST_FUNC_CALL:       fprintf(stderr, "FUNC_CALL"); break;
        case AST_BLOCO:           fprintf(stderr, "BLOCO"); break;

        case AST_ADD:             fprintf(stderr, "ADD"); break;
        case AST_SUB:             fprintf(stderr, "SUB"); break;
        case AST_MUL:             fprintf(stderr, "MUL"); break;
        case AST_DIV:             fprintf(stderr, "DIV"); break;

        case AST_AND:             fprintf(stderr, "AND"); break;
        case AST_OR:              fprintf(stderr, "OR"); break;
        case AST_NOT:             fprintf(stderr, "NOT"); break;
        case AST_LESS:            fprintf(stderr, "LESS"); break;
        case AST_GREATER:         fprintf(stderr, "GREATER"); break;

        case AST_ARGFUNCCALL:     fprintf(stderr, "ARGFUNCCALL"); break;
        case AST_ARGFUNCCALLLIST: fprintf(stderr, "ARGFUNCCALLLIST"); break;

        case AST_PROGRAM:         fprintf(stderr, "PROGRAMA"); break;
        case AST_PARENTESES:      fprintf(stderr, "PARENTESES"); break;

        case AST_COMMANDOLIST:    fprintf(stderr, "COMMANDOLIST"); break;
        case AST_ARGVEC:          fprintf(stderr, "ARGVEC"); break;
        case AST_ARR_ELEMENT:     fprintf(stderr, "ARR_ELEMENT"); break;
        default: fprintf(stderr,   "<< CARACTER NAO DEFINIDO >>"); break;
    }

    fprintf(stderr,")");
    if (node->symbol != 0){
        fprintf(stderr, " %s", node->symbol->text);
    }
    
    fprintf(stderr, "\n");
    
    for (int i=0; i < MAX_SONS; i++) {
        if (node->son[i]!=0){
            astPrint(node->son[i], level+1);
        }
    }
}

void printSpaces(int numSpaces){
    for (int i=0; i < numSpaces; i++)
        fprintf(stderr, "  ");
}
