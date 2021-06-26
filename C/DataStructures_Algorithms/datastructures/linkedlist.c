#include <stdlib.h>
#include "linkedlist.h"
#include <stdio.h>

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
        case SinglyLinkedList:
            _base_ListInsert(list, input);
            break;
        case CircularList:
            _circ_ListInsert(list, input);
            break;
        case DoublyLinkedList:
            _doubly_ListInsert(list, input);
            break;
        case DoublyCircularList:
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

linkableNode *listFind(linkedList *list, int queryData)
{
    linkableNode *out = NULL;

    if (list->len > 0)
    {
        linkableNode *current = *list->head;

        for (int i = 0; i < list->len; i++)
        {
            if (queryData == current->data)
            {
                out = current;

                break;
            }

            current = current->next;
        }
    }

    return out;
}

int listRemove(linkedList *list, int queryData)
{
    int result = 0;

    linkableNode *localNode = listFind(list, queryData);

    if (localNode != NULL)
    {
        if (list->len == 1)
        {
            *list->head = NULL;
            *list->tail = NULL;
        }
        else
        {
            if (list->type == SinglyLinkedList ||
                list->type == CircularList)
            {
                _singly_ListRemove(list, localNode);
            }
            else if (list->type == DoublyLinkedList ||
                     list->type == DoublyCircularList)
            {
                _doubly_ListRemove(list, localNode);
            }
        }

        result = 1;
        list->len--;
        free(localNode);
    }

    return result;
}

void destroy_LinkedList(linkedList *list)
{

    if (list->len > 0)
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
    }

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

void _singly_ListRemove(linkedList *list, linkableNode *target)
{
    linkableNode *previousToTarget = *list->head;

    for (int i = 0; i < list->len; i++)
    {
        if (previousToTarget->next == target)
        {
            previousToTarget->next = target->next;

            break;
        }
        else
        {
            previousToTarget = previousToTarget->next;
        }
    }

    if (target == *list->head)
    {
        *list->head = target->next;
    }
    else if (target == *list->tail)
    {
        *list->tail = previousToTarget;
    }
}

void _doubly_ListRemove(linkedList *list, linkableNode *target)
{
    target->previous->next = target->next;
    target->next->previous = target->previous;

    if (target == *list->head)
    {
        *list->head = target->next;
    }
    else if (target == *list->tail)
    {
        *list->tail = target->previous;
    }
}