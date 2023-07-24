#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HASH_NODE*Table[HASH_SIZE];

void hashInit(void){
    int i;
    for (i=0; i<HASH_SIZE; i++)
        Table[i]=0;
}

HASH_NODE* hashInsert(char* text, int type){
    
    HASH_NODE *newnode;

    if((newnode = hashFind(text)) != 0)
        return newnode;

    int address = hashAddress(text);
    
    newnode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
    newnode -> type = type;
    if(newnode->type == SYMBOL_LIT_CHAR) newnode->datatype = DATATYPE_INT;
    else if(newnode->type == SYMBOL_LIT_INT) newnode->datatype = DATATYPE_INT;
    else if(newnode->type == SYMBOL_LIT_REAL) newnode->datatype = DATATYPE_REAL;

    newnode -> text = (char*) calloc(strlen(text)+1, sizeof(char));
    strcpy(newnode -> text, text);

    newnode -> next = Table[address];
    Table[address] = newnode;

    return newnode;
}

HASH_NODE* hashFind(char *text){
    HASH_NODE *node;
    
    int address = hashAddress(text);
    for (node = Table[address]; node; node = node->next) {
        if (strcmp(node -> text, text) == 0)
            return node;
    }
    return NULL;
}

int hashAddress(char *text){
    int address = 1;
    int i;
    for (i=0; i<strlen(text); i++)
        address = (address * text[i]) % HASH_SIZE + 1;
    return address-1;
}

void hashPrint(void){
    HASH_NODE* node;
    
    int i;
    for(i = 0; i < HASH_SIZE; i++){
        if(Table[i] != NULL){
            for(node = Table[i]; node; node = node->next){
                printf("Table[%d] has text: %s\n", i, node->text);
            }
        }
    }
}

int hashCheckUndeclared(void) {
    int undeclared = 0;
    HASH_NODE *node;

    for(int i = 0; i < HASH_SIZE; i++) {
        if(Table[i] != NULL){
            for(node = Table[i]; node != NULL; node = node->next) {
                if (node->type == SYMBOL_IDENTIFIER) {
                    printf("Semantic Error: Identifier %s NOT declared\n", node->text);
                    undeclared++;
                }
            }
        }
    }
    
    return undeclared;
} 