
#include "tacs.h"
#include "hash.h"
#include "stdlib.h"
#include <stdio.h>

tac* createTac(int type, HASH_NODE *res, HASH_NODE *op1, HASH_NODE *op2){
	tac *n = (tac*) calloc(1, sizeof(tac));
	n->type = type;
	n->res = res;
	n->op1 = op1;
	n->op2 = op2;
	n->prev = NULL;
	n->next = NULL;	
	return n;
}

tac* tacJoin(tac* l1, tac* l2){
	tac* t;
	if(!l1) return l2;
	if(!l2) return l1;
	t = l2;
	while(t->prev){
		t = t->prev;	
	}
	t->prev = l1;
	return l2;
}

void printAllTacs(tac* l){
	tac* t;
	for(t = l; t; t = t->next)
		printTac(t);	
}

tac* rewindTac(tac* l){
	tac* t;
	for(t = l; t->prev; t = t->prev)
		t->prev->next = t;
	return t;
}

void printTac(tac* l){
	
	if(l->type == TAC_SYMBOL) return;
	
	fprintf(stderr, "TAC(");
	switch(l->type){
		case TAC_MOVE: fprintf(stderr, "MOVE(");break;
		case TAC_ADD: fprintf(stderr, "ADD(");break;
		case TAC_SUB: fprintf(stderr, "SUB(");break;
		case TAC_MUL: fprintf(stderr, "MUL(");break;
		case TAC_DIV: fprintf(stderr, "DIV(");break;
		case TAC_GREATER: fprintf(stderr, "GREAT(");break;
		case TAC_LESS: fprintf(stderr, "LESS(");break;
		case TAC_GE: fprintf(stderr, "GE(");break;
		case TAC_LE: fprintf(stderr, "LE(");break;
		case TAC_EQ: fprintf(stderr, "EQ(");break;
		case TAC_DIF: fprintf(stderr, "DIF(");break;
		case TAC_AND: fprintf(stderr, "AND(");break;
		case TAC_OR: fprintf(stderr, "OR(");break;
		case TAC_NOT: fprintf(stderr, "NOT(");break;
		case TAC_LABEL: fprintf(stderr, "LABEL(");break;
		case TAC_BEGINFUNC: fprintf(stderr, "BEGINFUNC(");break;
		case TAC_ARGFUNCCALL: fprintf(stderr, "ARGFUNCCALL(");break;
		case TAC_ENDFUNC: fprintf(stderr, "ENDFUNC(");break;
		case TAC_IF: fprintf(stderr, "IF(");break;
		case TAC_JUMP: fprintf(stderr, "JUMP(");break;
		case TAC_CALL: fprintf(stderr, "CALL(");break;
		case TAC_ARG: fprintf(stderr, "ARG(");break;
		case TAC_RETURN: fprintf(stderr, "RETORNA(");break;
		case TAC_OUTPUTLIST: fprintf(stderr, "OUTPUTLIST(");break;
		case TAC_ARR_ATTR: fprintf(stderr, "ARR_ATTR(");break;
		case TAC_ARRAY: fprintf(stderr, "ARRAY(");break;
		case TAC_PARAM: fprintf(stderr, "PARAM(");break;

		default: fprintf(stderr, "UNKNOWN TAC TYPE!(");break;
	}

	if(l->res)
		fprintf(stderr, "%s, ", l->res->text);
	else
		fprintf(stderr, "0, ");

	if(l->op1)
		fprintf(stderr, "%s, ", l->op1->text);
	else
		fprintf(stderr, "0, ");

	if(l->op2)
		fprintf(stderr, "%s", l->op2->text);
	else
		fprintf(stderr, "0");

	fprintf(stderr, "))\n");
}

tac* createTacs(AST *node, HASH_NODE *currentLoopLabel){
	if(!node) return NULL;

	tac* sons[MAX_SONS];
	if(node->type == AST_IFLOOP){
		currentLoopLabel = makeLabel();
	}
	for(int i = 0; i < MAX_SONS; i++)
		sons[i] = createTacs(node->son[i], currentLoopLabel);

	switch(node->type){
		case AST_SYMBOL: return createTac(TAC_SYMBOL, node->symbol, 0, 0);
		case AST_ADD: return createBinop(TAC_ADD, sons);
		case AST_SUB: return createBinop(TAC_SUB, sons);
		case AST_MUL: return createBinop(TAC_MUL, sons);
		case AST_DIV: return createBinop(TAC_DIV, sons);
		case AST_GREATER: return createBinop(TAC_GREATER, sons);
		case AST_LESS: return createBinop(TAC_LESS, sons);
		case AST_EQ: return createBinop(TAC_EQ, sons);
		case AST_GE: return createBinop(TAC_GE, sons);
		case AST_LE: return createBinop(TAC_LE, sons);
		case AST_DIF: return createBinop(TAC_DIF, sons);
		case AST_AND: return createBinop(TAC_AND, sons);
		case AST_OR: return createBinop(TAC_OR, sons);
		case AST_NOT: return createBinop(TAC_NOT, sons);

		case AST_ATTR: return tacJoin(sons[0], createTac(TAC_MOVE, node->symbol, sons[0]?sons[0]->res:0, 0));
		case AST_ARR_ATTR: return tacJoin(sons[0], tacJoin(sons[1], createTac(TAC_ARR_ATTR, node->symbol, sons[0]?sons[0]->res:0, sons[1]?sons[1]->res:0))); 
		case AST_OUTPUTINIT: 
		case AST_OUTPUTLIST: return tacJoin(tacJoin(sons[0], createTac(TAC_OUTPUTLIST, sons[0]?sons[0]->res:0, 0, 0)), sons[1]);
		case AST_RETURN: return tacJoin(sons[0], createTac(TAC_RETURN, sons[0]?sons[0]->res:0, 0, 0));
		case AST_IFTHEN:
		case AST_IF: return createIf(sons);
		case AST_IFLOOP: return createLoop(sons, currentLoopLabel);

		case AST_FUNC_CALL: return tacJoin(sons[0], createTac(TAC_CALL, makeTemp(), node->symbol, 0));
		case AST_ARGFUNCCALL: return tacJoin(sons[1], tacJoin(sons[0], createTac(TAC_ARGFUNCCALL, sons[0]?sons[0]->res:0, 0, 0)));
		case AST_ARRAY: return tacJoin(sons[0], createTac(TAC_ARRAY, makeTemp(), node->symbol, sons[0]?sons[0]->res:0));
		case AST_DECFUNC: return createFunction(createTac(TAC_SYMBOL, node->symbol, 0, 0), sons[1], sons[2]);
		case AST_PARAMINIT:
		case AST_PARAMLIST: return tacJoin(createTac(TAC_PARAM, node->symbol, 0, 0), sons[1]);

		default: return tacJoin(tacJoin(tacJoin(sons[0], sons[1]), sons[2]), sons[3]);
	}
}

tac* createBinop(int type, tac* sons[]){
	HASH_NODE * op1;
	HASH_NODE * op2;
	if(sons[0]) op1 = sons[0]->res; else op1 = 0;
	if(sons[1]) op2 = sons[1]->res; else op2 = 0;
	return tacJoin(sons[0], tacJoin(sons[1], createTac(type, makeTemp(), op1, op2)));
}

tac* createIf(tac* sons[]){
	HASH_NODE* ifLabel = makeLabel();
	tac* ifTac = tacJoin(sons[0], createTac(TAC_IF, ifLabel, sons[0]?sons[0]->res:0, 0));
	tac* ifLabelTac = createTac(TAC_LABEL, ifLabel, 0, 0);
	
	if(sons[2]){
		HASH_NODE* elseLabel = makeLabel();
		tac* elseLabelTac = createTac(TAC_LABEL, elseLabel, 0, 0);
		tac* elseJumpTac = createTac(TAC_JUMP, elseLabel, 0, 0);
		tac* ifElseTac = tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(ifTac, sons[1]), elseJumpTac), ifLabelTac), sons[2]), elseLabelTac);
		return ifElseTac;
	}else{
		return tacJoin(tacJoin(ifTac, sons[1]), ifLabelTac);
	}
}

tac* createLoop(tac* sons[], HASH_NODE *whileLabel){
	HASH_NODE* jumpLabel = makeLabel();

	tac* whileTac = createTac(TAC_IF, jumpLabel, sons[0]?sons[0]->res:0, 0);
	tac* whileLabelTac = createTac(TAC_LABEL, whileLabel, 0, 0);
	tac* jumpTac = createTac(TAC_JUMP, whileLabel, 0, 0);
	tac* jumpLabelTac= createTac(TAC_LABEL, jumpLabel, 0, 0);

	return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(whileLabelTac, sons[0]), whileTac), sons[1]), jumpTac), jumpLabelTac);
}

tac* createFunction(tac* symbol, tac* params, tac* code){
	return tacJoin(tacJoin(tacJoin(createTac(TAC_BEGINFUNC, symbol->res, 0, 0), params), code), createTac(TAC_ENDFUNC, symbol->res, 0, 0));
}
