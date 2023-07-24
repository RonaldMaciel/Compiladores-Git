#include <stdio.h>
#include "semantic.h"
#include "ast.h"

int SemanticErrors = 0;
AST *ROOT;

int semanticVerification(AST * root){
    ROOT = root;
				
	setIdentifierTypes(root); 
    setNodeTypes(root);
	checkUndeclared();
	checkUsage(root);
    checkReturns(root);

    return SemanticErrors;
}

void setIdentifierTypes(AST *node){
    if(node == NULL) return;
	
    switch (node->type){
    case AST_DECVAR:
        if(node->symbol->type != SYMBOL_IDENTIFIER){
            printf("Semantic ERROR in line %d: Variable %s redeclaration.\n", node->lineNumber, node->symbol->text);
            SemanticErrors++;
        } else {
            node->symbol->type = SYMBOL_VAR;
            if(node->son[0]->type == AST_DECCHAR) node->symbol->datatype = DATATYPE_CHAR;
            else if(node->son[0]->type == AST_DECINT) node->symbol->datatype = DATATYPE_INT;
            else if(node->son[0]->type == AST_DECREAL) node->symbol->datatype = DATATYPE_REAL;
            else if(node->son[0]->type == AST_DECBOOL) node->symbol->datatype = DATATYPE_BOOL;
        }

		if(!isDatatypeCompatible(node->symbol->datatype, node->son[1]->symbol->datatype) ) {
			printf("Semantic ERROR in line %d: Variable declaration with mixed dataypes\n", node->lineNumber);
			SemanticErrors++;
		}
        break;
    case AST_DECARRAY:
        if(node->symbol->type != SYMBOL_IDENTIFIER){
            printf("Semantic ERROR in line %d: Vector %s redeclaration.\n", node->lineNumber, node->symbol->text);
            SemanticErrors++;
        }
        else{
            node->symbol->type = SYMBOL_VEC;
            if(node->son[0]->type == AST_DECCHAR) node->symbol->datatype = DATATYPE_CHAR;
            else if(node->son[0]->type == AST_DECINT) node->symbol->datatype = DATATYPE_INT;
            else if(node->son[0]->type == AST_DECREAL) node->symbol->datatype = DATATYPE_REAL;
            
        }
		if(!checkEveryVecElement(node->son[2], node->symbol->datatype)){
			printf("Semantic ERROR on line %d: Vector declaration with elements of mixed datatype\n", node->lineNumber);
			SemanticErrors++;
		}
        break;
    case AST_DECFUNC:
        if(node->symbol->type != SYMBOL_IDENTIFIER){
            printf("Semantic ERROR in line %d: Function %s redeclaration.\n", node->lineNumber, node->symbol->text);
            SemanticErrors++;
        } else {
            node->symbol->type = SYMBOL_FUNC;
            if(node->son[0]->type == AST_DECCHAR) node->symbol->datatype = DATATYPE_CHAR;
            else if(node->son[0]->type == AST_DECINT) node->symbol->datatype = DATATYPE_INT;
            else if(node->son[0]->type == AST_DECREAL) node->symbol->datatype = DATATYPE_REAL;
        }
        break;
    case AST_PARAMLIST: //nao sei se ta certo
        if(node->symbol->type != SYMBOL_IDENTIFIER){
            printf("Semantic ERROR in line %d: Parameter %s redeclaration.\n", node->lineNumber, node->symbol->text);
            SemanticErrors++;
        }
        else{
            node->symbol->type = SYMBOL_PARAM;
            if(node->son[0]->type == AST_DECCHAR) node->symbol->datatype = DATATYPE_CHAR;
            else if(node->son[0]->type == AST_DECINT) node->symbol->datatype = DATATYPE_INT;
            else if(node->son[0]->type == AST_DECREAL) node->symbol->datatype = DATATYPE_REAL;
        }
        break;
    default:
        break;
    }
    for(int i = 0; i < MAX_SONS; i++)
        setIdentifierTypes(node->son[i]);
}

void setNodeTypes(AST *node){
    if(node == NULL) return;

    for(int i = 0; i < MAX_SONS; i++){
        setNodeTypes(node->son[i]);
    }

    if(node->type == AST_SYMBOL){
        if(node->symbol->type == SYMBOL_VEC || node->symbol->type == SYMBOL_FUNC){
            printf("Semantic ERROR in line %d: function/vector used as scalar variable.\n", node->lineNumber);
            SemanticErrors++;
        }
        node->datatype = node->symbol->datatype;
    }

    else if(node->type == AST_FUNC_CALL || node->type == AST_ARRAY){
        node->datatype = node->symbol->datatype;
    }

    else if(node->type == AST_PARENTESES){
        node->datatype = node->son[0]->datatype;
    }

    else if(isAritmeticOp(node->type)){
        AST* son0 = node->son[0];
        AST* son1 = node->son[1];
        if(!isDatatypeCompatible(son0->datatype, son1->datatype) || son0->datatype == DATATYPE_BOOL || son1->datatype == DATATYPE_BOOL){
            printf("Semantic ERROR in line %d: Arithmetic operation with incompatible data types.\n", node->lineNumber);
            SemanticErrors++;
        }
        node->datatype = greaterDatatype(son0->datatype, son1->datatype);
    }
    else if(isRelationalOp(node->type)){
        if(!isNumerical(node->son[0]->datatype) || !isNumerical(node->son[1]->datatype)){
            printf("Semantic ERROR in line %d: Relational operation with incompatible data types.\n", node->lineNumber);
            SemanticErrors++;
        }
        node->datatype = DATATYPE_BOOL;
    }
    else if(isLogicalOp(node->type)){
        if(node->type == AST_NOT){
            if(node->son[0]->datatype != DATATYPE_BOOL){
                printf("Semantic ERROR in line %d: Logical operation with incompatible data types.\n", node->lineNumber);
                SemanticErrors++;
            }
        }
        else if(node->son[0]->datatype != DATATYPE_BOOL || node->son[1]->datatype != DATATYPE_BOOL){
            printf("Semantic ERROR in line %d: Logical operation with incompatible data types.\n", node->lineNumber);
            SemanticErrors++;
        }
        node->datatype = DATATYPE_BOOL;
    }
}

void checkUndeclared(){
	int undeclaredVariables = hashCheckUndeclared();
 	SemanticErrors += undeclaredVariables;	
}

void checkUsage(AST *node){
    if(node == NULL) return;
	switch (node->type){
        case AST_ATTR:
            if(node->symbol->type != SYMBOL_VAR){
                printf("Semantic ERROR in line %d: Attribution must be to a scalar variable.\n", node->lineNumber);
                SemanticErrors++;
            }
            if(!isDatatypeCompatible(node->symbol->datatype, node->son[0]->datatype)){
                printf("Semantic ERROR in line %d: Attribution with incompatible data type.\n", node->lineNumber);
                SemanticErrors++;
            }
            break;
        case AST_ARR_ATTR:
            if(node->symbol->type != SYMBOL_VEC){
                printf("Semantic ERROR in line %d: Indexing only allowed for vectors.\n", node->lineNumber);
                SemanticErrors++;
            }
            if(!isDatatypeCompatible(node->symbol->datatype, node->son[1]->datatype)){
                printf("Semantic ERROR in line %d: Attribution with incompatible data type.\n", node->lineNumber);
                SemanticErrors++;
            }
            if(!isInteger(node->son[0]->datatype)){
                printf("Semantic ERROR in line %d: Index must be an integer.\n", node->lineNumber);
                SemanticErrors++;
            }
            break;

        case AST_FUNC_CALL:
			validateFunction(node);
			break;

        case AST_INPUT:
            checkPrint(node->son[0]);
            break;

        case AST_OUTPUT:
            if(node->son[1]->datatype != DATATYPE_INT){
                printf("Semantic ERROR in line %d: Condition must be a boolean expression.\n", node->lineNumber);
                SemanticErrors++;
            }
            break;

        case AST_IFLOOP:
            if(node->son[3]->datatype != DATATYPE_BOOL){
                printf("Semantic ERROR in line %d: Condition must be a boolean expression.\n", node->lineNumber);
                SemanticErrors++;
            }
            break;    
            
        case AST_IF:
            if(node->son[1]->datatype != DATATYPE_BOOL){
                printf("Semantic ERROR in line %d: Condition must be a boolean expression.\n", node->lineNumber);
                SemanticErrors++;
            }
            break;
        case AST_IFELSE:
            if(node->son[2]->datatype != DATATYPE_BOOL){
                printf("Semantic ERROR in line %d: Condition must be a boolean expression.\n", node->lineNumber);
                SemanticErrors++;
            }
            break;

        default:
            break;
    }

    for(int i = 0; i < MAX_SONS; i++)
		checkUsage(node->son[i]);
}

int isDatatypeCompatible(int datatype1, int datatype2) {
    return (isInteger(datatype1) && isInteger(datatype2)) || (datatype1 == datatype2);
}

int isInteger(int datatype){
    return (datatype == DATATYPE_CHAR || datatype == DATATYPE_INT);
}

int isNumerical(int datatype){
    return (datatype == DATATYPE_CHAR || datatype == DATATYPE_INT || datatype == DATATYPE_REAL);
}

int isBoolean(int datatype) {
    return (datatype == DATATYPE_BOOL);
}

int isRelationalOp(int nodetype){
    return (nodetype == AST_LESS || nodetype == AST_GREATER || nodetype == AST_EQ || nodetype == AST_LE || nodetype == AST_GE || nodetype == AST_DIF);
}

int isAritmeticOp(int nodetype){
    return (nodetype == AST_ADD || nodetype == AST_SUB || nodetype == AST_MUL || nodetype == AST_DIV);
}

int isLogicalOp(int nodetype){
    return (nodetype == AST_AND || nodetype == AST_OR || nodetype == AST_NOT);
}

int greaterDatatype(int type1, int type2){
    return type1 > type2 ? type1 : type2;
}

void checkPrint(AST *node){
    if (node == NULL) return;

    if(node->son[0]->type == AST_SYMBOL){
        if(node->son[0]->symbol->type == SYMBOL_FUNC){
            printf("Semantic ERROR in line %d: Cannot print function\n", node->lineNumber);
            SemanticErrors++;
        }
        else if(node->son[0]->symbol->type == SYMBOL_VEC){
            printf("Semantic ERROR in line %d: Cannot print vector\n", node->lineNumber);
            SemanticErrors++;
        }
    }
    checkPrint(node->son[1]);
}

void validateFunction(AST *node){
	AST* declaration = findFunctionDeclaration(node->symbol->text, ROOT);
    if(declaration == NULL){
        printf("Semantic ERROR in line %d: Only functions can be called.\n", node->lineNumber);
        SemanticErrors++;
    }
	else if(checkNumberOfArguments(node, declaration)){
		compareCalledArguments(node->son[0], declaration->son[1]);					
	}
}

bool checkNumberOfArguments(AST *node, AST *declaration){
	int numberOfCalledArguments = getNumberOfArguments(node->son[0]);
	int numberOfDeclaredArguments = getNumberOfArguments(declaration->son[1]);	
	if(numberOfCalledArguments != numberOfDeclaredArguments){
    	printf("Semantic ERROR in line %d: Incompatible number of arguments.\n", node->lineNumber);
		SemanticErrors++;
		return false;
	}
	return true;
}

AST* findFunctionDeclaration(char * name, AST * node){
	if(node->symbol != NULL && node->type == AST_DECFUNC && strcmp(node->symbol->text, name) == 0)
		return node;

	for(int i = 0; i < MAX_SONS; i++){
		if(node->son[i] == NULL)
			return NULL;
		AST * finding = findFunctionDeclaration(name, node->son[i]) ;
		if(finding != NULL)
			return finding;
	}
	return NULL;
}

int getNumberOfArguments(AST * node){
    if(node == NULL) return 0;
	if(node->son[1] != NULL)
		return 1 + getNumberOfArguments(node->son[1]);
	else
		return 0;
}

void compareCalledArguments(AST *node, AST *declaration){
	if(node->son[0] != NULL){
		if(!isDatatypeCompatible(node->son[0]->datatype, declaration->son[0]->symbol->datatype)){
			printf("Semantic ERROR in line %d: Incompatible argument types\n", node->lineNumber);
			SemanticErrors++;
		}
        if(node->son[0]->type == AST_SYMBOL){
            if(node->son[0]->symbol->type == SYMBOL_FUNC){
                printf("Semantic ERROR in line %d: Cannot pass function as argument\n", node->lineNumber);
			    SemanticErrors++;
            }
            else if(node->son[0]->symbol->type == SYMBOL_VEC){
                printf("Semantic ERROR in line %d: Cannot pass vector as argument\n", node->lineNumber);
			    SemanticErrors++;
            }
        }
		if(node->son[1] != NULL)
			compareCalledArguments(node->son[1], declaration->son[1]);
	}
}

bool checkEveryVecElement(AST * node, int datatype){	
	if(node != NULL){
		if(!isDatatypeCompatible(node->son[0]->symbol->datatype, datatype))
			return false;
		if(node->son[1] != NULL)
			return checkEveryVecElement(node->son[1], datatype);
	}
	return true;
}

void isReturnCompatible(AST *node, int datatype){
	if(node == NULL) return;
	if(node->type == AST_RETURN){
		if(!isDatatypeCompatible(node->son[0]->datatype, datatype)){
			printf("Semantic ERROR in line %d: Return statement with wrong datatype.\n", node->lineNumber);
			SemanticErrors++;
		}
	}
	for(int i = 0; i < MAX_SONS; i++){
		isReturnCompatible(node->son[i], datatype);
	}
}

void checkReturns(AST * node){
	if(node != NULL && node->type == AST_DECFUNC){
		isReturnCompatible(node, node->symbol->datatype);
	}

	for(int i = 0; i < MAX_SONS; i++){
		if(node->son[i] == NULL)
			break;
		checkReturns(node->son[i]);
	}
}

