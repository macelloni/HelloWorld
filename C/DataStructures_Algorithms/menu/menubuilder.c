#include <stdlib.h>
#include <string.h>

#include "menubuilder.h"

// All contents are hard-coded

void _assignMainMenu(menu *m)
{
    m->title = malloc((9 + 1) * sizeof(char));
    strcpy(m->title, "MAIN MENU");

    m->amountOfItems = 2;
    m->items = malloc(sizeof(char *));

    // Alloc strings
    m->items[0] = malloc((3 + 1) * sizeof(char));
    m->items[1] = malloc((3 + 1) * sizeof(char));

    // Assign strings
    strcpy(m->items[0], "foo");
    strcpy(m->items[1], "bar");
}