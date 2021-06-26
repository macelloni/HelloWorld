#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum ListBounds
{
    Front,
    Back
} listBounds;

typedef enum ListType
{
    SinglyLinkedList,
    CircularList,
    DoublyLinkedList,
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
linkedList create_LinkedList(int maxSize, listType type);
int push(linkedList *list, linkableNode *input);
int pushBack(linkedList *list, linkableNode *input);
linkableNode *peek(linkedList *list, listBounds position);
linkableNode *listFind(linkedList *list, int queryData);
int popFront(linkedList *list);
int popBack(linkedList *list);
int listRemove(linkedList *list, int queryData);
void destroy_LinkedList(linkedList *list);

void _assignFirst(linkedList *list, linkableNode *input);

void _base_PushFront(linkedList *list, linkableNode *input);
void _circ_PushFront(linkedList *list, linkableNode *input);
void _doubly_PushFront(linkedList *list, linkableNode *input);
void _doublycirc_PushFront(linkedList *list, linkableNode *input);

void _base_PushBack(linkedList *list, linkableNode *input);
void _circ_PushBack(linkedList *list, linkableNode *input);
void _doubly_PushBack(linkedList *list, linkableNode *input);
void _doublycirc_PushBack(linkedList *list, linkableNode *input);

void _base_PopFront(linkedList *list);
void _circ_PopFront(linkedList *list);
void _doubly_PopFront(linkedList *list);
void _doublycirc_PopFront(linkedList *list);

void _base_PopBack(linkedList *list);
void _circ_PopBack(linkedList *list);
void _doubly_PopBack(linkedList *list);
void _doublycirc_PopBack(linkedList *list);

void _emptyList(linkedList *list, linkableNode *soleNode);
void _singly_ListRemove(linkedList *list, linkableNode *target);
void _doubly_ListRemove(linkedList *list, linkableNode *target);

#endif