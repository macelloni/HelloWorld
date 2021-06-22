#ifndef MENU_H
#define MENU_H

typedef enum MenuType
{
    MainMenu,
    foo,
    bar
} menuType;

typedef struct Menu
{
    menuType type;
    int amountOfItems;
    char *title;
    char **items;
} menu;

menu getMenu(menuType arg);
void destroyMenu(menu *m);

#endif