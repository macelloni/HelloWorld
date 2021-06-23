#ifndef INTARRAY_H
#define INTARRAY_H

typedef struct IntArray
{
    char *name;
    int *data;
    int len;
} intArray;

intArray create_IntArray(char *id, int len);
intArray create_RandArray(char *id, int len, int ceil);
void destroy_IntArray(intArray *arr);

#endif