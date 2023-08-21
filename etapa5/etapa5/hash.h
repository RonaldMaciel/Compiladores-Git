#ifndef HASH_HEADER
#define HASH_HEADER

#define HASH_SIZE 997

#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_FLOAT 2
#define SYMBOL_LIT_CHAR 3
#define SYMBOL_LIT_STRING 4
#define SYMBOL_IDENTIFIER 5

#define SYMBOL_VAR 10
#define SYMBOL_VEC 11
#define SYMBOL_FUNC 12
#define SYMBOL_PARAM 13

#define DATATYPE_BYTE 14
#define DATATYPE_INT 15
#define DATATYPE_FLOAT 16
#define DATATYPE_BOOL 17

typedef struct hash_node{
    int type;
    char* text;
    struct hash_node* next;
} HASH_NODE;

HASH_NODE* hashInsert(char *text, int type);
HASH_NODE* hashFind(char *text);
void hashInit(void);
int hashAddress(char *text);
void hashPrint(void);
HASH_NODE * makeTemp();
HASH_NODE * makeLabel();

#endif
