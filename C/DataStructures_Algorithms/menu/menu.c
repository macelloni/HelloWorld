#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "menubuilder.h"

menu getMenu(menuType arg)
{
    menu out;
    out.type = arg;

    switch (out.type)
    {
    case MainMenu:
        _assignMainMenu(&out);
        break;
    }

    return out;
}

void destroyMenu(menu *m)
{
    free(m->title);

    for (int i = 0; i < m->amountOfItems; i++)
    {
        free(m->items[i]);
    }
    free(m->items);
}