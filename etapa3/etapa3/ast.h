// Abstract Syntax Tree

#ifndef AST_HEADER
#define AST_HEADER

#define MAX_SONS 4

#include "hash.h"

enum{
    AST_SYMBOL,

    AST_ATTR,
    AST_ARR_ATTR,
    AST_PARAMLIST,
    AST_PARAMINIT,
    AST_DECLARAT,
    AST_DECVAR,
    AST_DECFUNC,

    AST_DECINT,
    AST_DECCHAR,
    AST_DECREAL,
    AST_DECBOOL,

    AST_IF,
    AST_IFTHEN,
    AST_IFELSE,
    AST_IFLOOP,

    AST_INPUT,
    AST_OUTPUT,
    AST_OUTPUTINIT,
    AST_OUTPUTLIST,
    AST_RETURN,

    AST_LE,
    AST_GE,
    AST_EQ,
    AST_DIF,

    AST_ARRAY,
    AST_ARGINIT,

    AST_DECARRAY,
    AST_INIT_ARRAY,
    AST_FUNC_CALL,

    AST_BLOCO,

    AST_ADD,
    AST_SUB,
    AST_MUL,
    AST_DIV,

    AST_AND,
    AST_OR,
    AST_NOT, 
    AST_LESS,
    AST_GREATER,

    AST_ARGFUNCCALL,
    AST_ARGFUNCCALLLIST,

    AST_PROGRAM,
    AST_PARENTESES,

    AST_COMMANDOLIST,
    AST_ARGVEC,
    AST_ARR_ELEMENT,

};

typedef struct astnode
{
    int type;
    HASH_NODE *symbol;
    struct astnode *son[MAX_SONS];
}AST;

AST *astCreate(int type, HASH_NODE *symbol, AST *s0, AST *s1, AST *s2, AST *s3);
void astPrint(AST *node, int level);
void printSpaces(int numSpaces);

#endif
