#include <stdlib.h>
#include "linkedlist.h"

linkableNode *create_LinkableNode(int dataInput)
{
    linkableNode *out = malloc(sizeof(linkableNode));

    out->data = dataInput;
    out->next = NULL;
    out->previous = NULL;

    return out;
}

linkedList create_LinkedList(int maxSize, char *label, listType type)
{
    linkedList out;

    out.head = malloc(sizeof(linkableNode *));
    *out.head = NULL;

    out.tail = malloc(sizeof(linkableNode *));
    *out.tail = NULL;

    out.len = 0;
    out._maxLen = maxSize;
    out.type = type;

    return out;
}

void destroy_LinkedList(linkedList *list)
{
    linkableNode *pointers[list->len - 2];

    int i = 0;
    for (linkableNode *c = (*list->head)->next; c != *list->tail; c = c->next)
    {
        pointers[i] = c;
        i++;
    }

    for (i--; i > -1; i--)
    {
        free(pointers[i]);
    }
    free(*list->head);
    free(*list->tail);
    free(list->head);
    free(list->tail);
}

void _assignHead(linkedList *list, linkableNode *input)
{
    /*
    If-blocks and calls to this will be later placed somewhere else
    For now, insertions will be a bit verbose, at times redundant,
    but the current implementation supports cleaner code with
    little refactoring effort
    */
    *list->head = input;
    *list->tail = input;

    list->len++;
}

void _base_ListInsert(linkedList *list, linkableNode *input)
{
    if (list->len == 0)
    {
        _assignHead(list, input);
    }
    else
    {
        (*list->tail)->next = input;
        *list->tail = input;

        list->len++;
    }
}

void _circ_ListInsert(linkedList *list, linkableNode *input)
{
    if (list->len == 0)
    {
        _assignHead(list, input);
    }
    else
    {
        input->next = *list->head;
        _base_ListInsert(list, input);
    }
}

void _doubly_ListInsert(linkedList *list, linkableNode *input)
{
    if (list->len == 0)
    {
        _assignHead(list, input);
    }
    else
    {
        input->previous = *list->tail;
        _base_ListInsert(list, input);
    }
}

void _doublycirc_ListInsert(linkedList *list, linkableNode *input)
{
    if (list->len == 0)
    {
        _assignHead(list, input);
    }
    else
    {
        _doubly_ListInsert(list, input);
        (*list->head)->previous = *list->tail;
        (*list->tail)->next = *list->head;
    }
}