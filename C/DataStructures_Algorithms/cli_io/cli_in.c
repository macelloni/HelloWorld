#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "cli_in.h"

char *readLine(int maxchar, char *errorMessage)
{

    while (1)
    {
        char userInput[2 * maxchar + 1];
        fgets(userInput, maxchar, stdin);

        int len = strlen(userInput);
        if (len < maxchar)
        {
            char *out = userInput;

            return out;
        }
        else
        {
            printf("%s: ", errorMessage);
        }
    }
}

int readInt(char *errorMessage)
{
    int error = 0;

    while (1)
    {
        char *userInput = readLine(21 + 1, errorMessage);

        errno = 0;
        char *endptr;
        int out = strtol(userInput, &endptr, 10);

        if (errno || endptr == userInput)
        {
            printf("%s: ", errorMessage);
        }
        else
        {
            return out;
        }
    }
}