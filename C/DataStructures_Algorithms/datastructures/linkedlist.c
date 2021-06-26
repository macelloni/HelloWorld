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

int listInsert(linkedList *list, linkableNode *input)
{
    int result;

    if (list->len == 0)
    {
        _assignHead(list, input);

        result = 1;
    }
    else if (list->len + 1 <= list->_maxLen)
    {
        switch (list->type)
        {
        case SinglyLinked:
            _base_ListInsert(list, input);
            break;
        case Circular:
            _circ_ListInsert(list, input);
            break;
        case DoublyLinked:
            _doubly_ListInsert(list, input);
            break;
        case DoublyCircular:
            _doublycirc_ListInsert(list, input);
            break;
        }

        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
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
    *list->head = input;
    *list->tail = input;

    list->len++;
}

void _base_ListInsert(linkedList *list, linkableNode *input)
{
    (*list->tail)->next = input;
    *list->tail = input;

    list->len++;
}

void _circ_ListInsert(linkedList *list, linkableNode *input)
{
    input->next = *list->head;
    _base_ListInsert(list, input);
}

void _doubly_ListInsert(linkedList *list, linkableNode *input)
{
    input->previous = *list->tail;
    _base_ListInsert(list, input);
}

void _doublycirc_ListInsert(linkedList *list, linkableNode *input)
{

    _doubly_ListInsert(list, input);
    (*list->head)->previous = *list->tail;
    (*list->tail)->next = *list->head;
}