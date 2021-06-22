#include <stdio.h>

#include "cli_out.h"

void displayMenu(menu m)
{
    printf(" %s\n", m.title);

    for (int i = 0; i < m.amountOfItems; i++)
    {
        printf("    %d - %s\n", i + 1, m.items[i]);
    }

    switch (m.type)
    {
    case MainMenu:
        printf("\n    0 - Exit\n");
        break;
    default:
        printf("\n    0 - Back\n");
        break;
    }
}