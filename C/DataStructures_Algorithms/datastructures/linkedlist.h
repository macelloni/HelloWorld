#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum ListType
{
    SinglyLinked,
    DoublyLinked,
    Circular,
    DoublyCircular
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

linkableNode *create_LinkableNode(int dataInput);
linkedList create_LinkedList(int maxSize, char *label, listType type);
void destroy_LinkedList(linkedList *list);

void _assignHead(linkedList *list, linkableNode *input);
void _base_ListInsert(linkedList *list, linkableNode *input);
void _circ_ListInsert(linkedList *list, linkableNode *input);
void _doubly_ListInsert(linkedList *list, linkableNode *input);
void _doublycirc_ListInsert(linkedList *list, linkableNode *input);

#endif