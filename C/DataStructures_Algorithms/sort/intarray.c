#include <stdlib.h>
#include <string.h>

#include "intarray.h"

intArray create_IntArray(char *id, int len)
{
    intArray out;

    out.name = malloc(strlen(id) * sizeof(char));
    strcpy(out.name, id);

    out.data = malloc(len * sizeof(int));
    out.len = len;

    return out;
}

intArray create_RandArray(char *id, int len, int ceil)
{
    intArray out = create_IntArray(id, len);

    for (int i = 0; i < out.len; i++)
    {
        out.data[i] = rand() % ceil;
    }

    return out;
}

void destroy_IntArray(intArray *arr)
{
    free(arr->name);
    free(arr->data);
}