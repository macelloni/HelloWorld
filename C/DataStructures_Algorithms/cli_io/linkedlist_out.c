#include <stdio.h>
#include <stdlib.h>

#include "linkedlist_out.h"

void _displayLNode(linkableNode *ln)
{
    printf("Node value: %d\n", ln->data);

    char previousData[32 + 1];
    char nextData[32 + 1];

    if (ln->previous != NULL)
    {
        sprintf(previousData, "    Previous: %d", ln->previous->data);
    }
    else
    {
        sprintf(previousData, "    Previous: Null");
    }

    if (ln->next != NULL)
    {
        sprintf(nextData, "    Next: %d", ln->next->data);
    }
    else
    {
        sprintf(nextData, "    Next: Null");
    }

    printf("%s%s\n", previousData, nextData);
}

void _displayList(linkedList list)
{
    for (linkableNode *c = *list.head;
         c != (*list.tail)->next;
         c = c->next)
    {
        _displayLNode(c);
    }
}

void _displayCircList(linkedList list)
{
    _displayLNode(*list.head);

    for (linkableNode *c = (*list.head)->next;
         c != (*list.tail)->next;
         c = c->next)
    {
        _displayLNode(c);
    }
}