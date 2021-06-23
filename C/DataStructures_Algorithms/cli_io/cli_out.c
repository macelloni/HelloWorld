#include <stdio.h>
#include <string.h>

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

void displayArray(intArray arr, arr_ViewMode mode)
{
    char separator[2 + 1];
    char prefix[8 + 1];

    switch (mode)
    {
    case SingleLine:
        strcpy(separator, ",");
        strcpy(prefix, " ");
        break;
    case NewLine:
        strcpy(separator, "\n");
        strcpy(prefix, "    ");
        break;
    }

    printf("Displaying %s\n\n", arr.name);

    if (mode == SingleLine)
    {
        printf("   ");
    }
    
    for (int i = 0; i < arr.len - 1; i++)
    {
        printf("%s%d%s", prefix, arr.data[i], separator);
    }
    printf("%s%d\n\n", prefix, arr.data[arr.len - 1]);
}