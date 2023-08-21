#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"
#include <string.h>
#include <stdbool.h>

int semanticVerification(AST* root);
void setIdentifierTypes(AST* node);
void setNodeTypes(AST *node);
void checkUndeclared();
void checkUsage(AST* node);
void checkOutput(AST *node);

bool checkEveryVecElement(AST * node, int datatype);
int isDatatypeCompatible(int datatype1, int datatype2);
int isInteger(int datatype);
int isCharacter(char datatype1);
int isNumerical(int datatype);
int isRelationalOp(int nodetype);
int isAritmeticOp(int nodetype);
int isLogicalOp(int nodetype);
int greaterDatatype(int type1, int type2);
void validateFunction(AST * node);
AST *findFunctionDeclaration(char * name, AST * node);
int checkNumberOfArguments(AST * node, AST * declaration);
int getNumberOfArguments(AST * node);
void compareCalledArguments(AST * node, AST * declaration);
void isReturnCompatible(AST * node, int datatype);
void checkReturns(AST *node);

#endif
