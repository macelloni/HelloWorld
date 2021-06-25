#include <stdlib.h>
#include <string.h>

#include "intarray.h"

intArray create_IntArray(int len)
{
    intArray out;

    out.data = malloc(len * sizeof(int));
    out.len = len;

    return out;
}

intArray create_RandArray(int len, int ceil)
{
    intArray out = create_IntArray(len);

    for (int i = 0; i < out.len; i++)
    {
        out.data[i] = rand() % ceil;
    }

    return out;
}

void destroy_IntArray(intArray *arr)
{
    free(arr->data);
}