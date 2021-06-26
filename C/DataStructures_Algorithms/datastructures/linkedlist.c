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

linkedList create_LinkedList(int maxSize, listType type)
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

int push(linkedList *list, linkableNode *input)
{
    int result = 0;

    if (list->len == 0)
    {
        _assignFirst(list, input);

        list->len++;
        result = 1;
    }
    else if (list->len + 1 <= list->_maxLen)
    {
        switch (list->type)
        {
        case SinglyLinkedList:
            _base_PushFront(list, input);
            break;

        case CircularList:
            _circ_PushFront(list, input);
            break;

        case DoublyLinkedList:
            _doubly_PushFront(list, input);
            break;

        case DoublyCircularList:
            _doublycirc_PushFront(list, input);
            break;
        }

        list->len++;
        result = 1;
    }

    return result;
}

int pushBack(linkedList *list, linkableNode *input)
{
    int result = 0;

    if (list->len == 0)
    {
        _assignFirst(list, input);

        list->len++;
        result = 1;
    }
    else if (list->len + 1 <= list->_maxLen)
    {
        switch (list->type)
        {
        case SinglyLinkedList:
            _base_PushBack(list, input);
            break;

        case CircularList:
            _circ_PushBack(list, input);
            break;

        case DoublyLinkedList:
            _doubly_PushBack(list, input);
            break;

        case DoublyCircularList:
            _doublycirc_PushBack(list, input);
            break;
        }

        list->len++;
        result = 1;
    }

    return result;
}

linkableNode *peek(linkedList *list, listBounds position)
{
    linkableNode *out;

    switch (position)
    {
    case Front:
        out = *list->head;
        break;
    case Back:
        out = *list->tail;
        break;
    }

    return out;
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

int popFront(linkedList *list)
{
    int result = 0;

    if (list->len > 0)
    {
        linkableNode *localPtr = *list->head;

        switch (list->type)
        {
        case SinglyLinkedList:
            _base_PopFront(list);
            break;

        case CircularList:
            _circ_PopFront(list);
            break;

        case DoublyLinkedList:
            _doubly_PopFront(list);
            break;

        case DoublyCircularList:
            _doublycirc_PopFront(list);
            break;
        }

        list->len--;
        free(localPtr);
        result = 1;
    }

    return result;
}

int popBack(linkedList *list)
{
    int result = 0;

    if (list->len > 0)
    {
        linkableNode *localPtr = *list->tail;

        switch (list->type)
        {
        case SinglyLinkedList:
            _base_PopBack(list);
            break;

        case CircularList:
            _circ_PopBack(list);
            break;
        case DoublyLinkedList:
            _doubly_PopBack(list);

            break;
        case DoublyCircularList:
            _doublycirc_PopBack(list);
            break;
        }

        list->len--;
        free(localPtr);
        result = 1;
    }

    return result;
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

void _assignFirst(linkedList *list, linkableNode *input)
{
    *list->head = input;
    *list->tail = input;
}

void _base_PushFront(linkedList *list, linkableNode *input)
{
    input->next = *list->head;
    *list->head = input;
}

void _circ_PushFront(linkedList *list, linkableNode *input)
{
    _base_PushFront(list, input);
    (*list->tail)->next = input;
}

void _doubly_PushFront(linkedList *list, linkableNode *input)
{
    (*list->head)->previous = input;
    _base_PushFront(list, input);
}

void _doublycirc_PushFront(linkedList *list, linkableNode *input)
{
    _doubly_PushFront(list, input);
    (*list->head)->previous = *list->tail;
    (*list->tail)->next = *list->head;
}

void _base_PushBack(linkedList *list, linkableNode *input)
{
    (*list->tail)->next = input;
    *list->tail = input;
}

void _circ_PushBack(linkedList *list, linkableNode *input)
{
    input->next = *list->head;
    _base_PushBack(list, input);
}

void _doubly_PushBack(linkedList *list, linkableNode *input)
{
    input->previous = *list->tail;
    _base_PushBack(list, input);
}

void _doublycirc_PushBack(linkedList *list, linkableNode *input)
{
    _doubly_PushBack(list, input);
    (*list->head)->previous = *list->tail;
    (*list->tail)->next = *list->head;
}

void _base_PopFront(linkedList *list)
{
    *list->head = (*list->head)->next;
}

void _circ_PopFront(linkedList *list)
{
    _base_PopFront(list);
    *list->tail = *list->head;
}

void _doubly_PopFront(linkedList *list)
{
    _base_PopFront(list);
    (*list->head)->previous = NULL;
}

void _doublycirc_PopFront(linkedList *list)
{
    _base_PopFront(list);
    (*list->tail)->next = *list->head;
    (*list->head)->previous = *list->tail;
}

void _base_PopBack(linkedList *list)
{
    linkableNode *newTail = *list->head;

    while (newTail->next != *list->tail)
    {
        newTail = newTail->next;
    }

    newTail->next = NULL;
    *list->tail = newTail;
}

void _circ_PopBack(linkedList *list)
{
    _base_PopBack(list);
    (*list->tail)->next = *list->head;
}

void _doubly_PopBack(linkedList *list)
{
    *list->tail = (*list->tail)->previous;
}

void _doublycirc_PopBack(linkedList *list)
{
    _doubly_PopBack(list);
    (*list->tail)->next = *list->head;
    (*list->head)->previous = *list->tail;
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