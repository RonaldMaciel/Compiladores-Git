#ifndef HASH_HEADER
#define HASH_HEADER

#define HASH_SIZE 997

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

#endif
