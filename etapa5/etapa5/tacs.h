#ifndef TAC_H
#define TAC_H

#include "ast.h"

#define TAC_SYMBOL 0
#define TAC_MOVE 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MUL 4
#define TAC_DIV 5
#define TAC_GREATER 6
#define TAC_LESS 7
#define TAC_GE 8
#define TAC_LE 9
#define TAC_EQ 10
#define TAC_DIF 11
#define TAC_AND 12
#define TAC_OR 13
#define TAC_NOT 14
#define TAC_LABEL 15
#define TAC_BEGINFUNC 16
#define TAC_ARGFUNCCALL 17
#define TAC_ENDFUNC 18
#define TAC_IF 19
#define TAC_JUMP 20
#define TAC_CALL 21
#define TAC_ARG 22
#define TAC_RETURN 23
#define TAC_OUTPUTLIST 24
#define TAC_ARR_ATTR 26
#define TAC_ARRAY 27
#define TAC_PARAM 28

typedef struct tac_struct{
	int type;
	HASH_NODE *res;
	HASH_NODE *op1;
	HASH_NODE *op2;
	struct tac_struct *prev;
	struct tac_struct *next; 
} tac;

tac* createTac(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2);
tac* tacJoin(tac* l1, tac* l2);
void printAllTacs(tac* l);
tac* rewindTac(tac* l);
void printTac(tac* l);
tac* createTacs(AST *node, HASH_NODE *currentLoopLabel);

tac* createBinop(int type, tac* sons[]);
tac* createIf(tac* sons[]);
tac* createLoop(tac* sons[], HASH_NODE *label);
tac* createFunction(tac* symbol, tac* params, tac* code);

#endif
