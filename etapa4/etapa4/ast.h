// Abstract Syntax Tree

#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS 4

#include "hash.h"

#define AST_SYMBOL 1
#define AST_ATTR 2
#define AST_ARR_ATTR 3
#define AST_PARAMLIST 4
#define AST_PARAMINIT 5
#define AST_DECLARAT 6 
#define AST_DECVAR 7
#define AST_DECFUNC 8 

#define AST_DECCHAR 9
#define AST_DECINT 10
#define AST_DECREAL 11
#define AST_DECBOOL 12

#define AST_IF 13
#define AST_IFTHEN 14
#define AST_IFELSE 15
#define AST_IFLOOP 16

#define AST_INPUT 17
#define AST_OUTPUT 18
#define AST_OUTPUTINIT 19
#define AST_OUTPUTLIST 20
#define AST_RETURN 21

#define AST_LE 22 
#define AST_GE 23
#define AST_EQ 24
#define AST_DIF 25

#define AST_ARRAY 26 
#define AST_ARGINIT 27 

#define AST_DECARRAY 28
#define AST_INIT_ARRAY 29
#define AST_FUNC_CALL 30 

#define AST_BLOCO 31

#define AST_ADD 32
#define AST_SUB 33
#define AST_MUL 34
#define AST_DIV 35

#define AST_AND 36
#define AST_OR 37
#define AST_NOT 38
#define AST_LESS 39
#define AST_GREATER 40 

#define AST_ARGFUNCCALL 41
#define AST_ARGFUNCCALLLIST 42

#define AST_PROGRAM 43
#define AST_PARENTESES 44

#define AST_COMMANDOLIST 45
#define AST_ARGVEC 46
#define AST_ARR_ELEMENT 47


typedef struct astnode{
    int type;
    int datatype;
    int lineNumber;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
}AST;

AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3, int lineNumber);
void astPrint(AST *node, int level);
void printSpaces(int numSpaces);

#endif
