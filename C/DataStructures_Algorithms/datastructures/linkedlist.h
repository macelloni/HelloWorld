#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum ListType
{
    SinglyLinkedList,
    DoublyLinkedList,
    CircularList,
    DoublyCircularList
} listType;

typedef struct LinkableNode
{
    // char *key;
    int data;
    struct LinkableNode *next;
    struct LinkableNode *previous;
} linkableNode;

typedef struct LinkedList
{
    linkableNode **head;
    linkableNode **tail;
    listType type;
    unsigned int len;
    int _maxLen;
} linkedList;

// queryData arguments to be replaced by <T>

linkableNode *create_LinkableNode(int dataInput);
linkedList create_LinkedList(int maxSize, char *label, listType type);
int listInsert(linkedList *list, linkableNode *input);
linkableNode *listFind(linkedList *list, int queryData);
int listRemove(linkedList *list, int queryData);
void destroy_LinkedList(linkedList *list);

void _assignHead(linkedList *list, linkableNode *input);
void _base_ListInsert(linkedList *list, linkableNode *input);
void _circ_ListInsert(linkedList *list, linkableNode *input);
void _doubly_ListInsert(linkedList *list, linkableNode *input);
void _doublycirc_ListInsert(linkedList *list, linkableNode *input);

void _emptyList(linkedList *list, linkableNode *soleNode);
void _singly_ListRemove(linkedList *list, linkableNode *target);
void _doubly_ListRemove(linkedList *list, linkableNode *target);

#endif