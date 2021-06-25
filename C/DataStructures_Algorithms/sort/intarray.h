#ifndef INTARRAY_H
#define INTARRAY_H

typedef struct IntArray
{
    char *name;
    int *data;
    int len;
} intArray;

intArray create_IntArray(int len);
intArray create_RandArray(int len, int ceil);
void destroy_IntArray(intArray *arr);

#endif