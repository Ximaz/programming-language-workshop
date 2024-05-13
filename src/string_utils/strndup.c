/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** strndup.c
*/

#include <stdlib.h>
#include <string.h>

char *strndup(const char *string, size_t length)
{
    char *block = calloc(length + 1, sizeof(char));

    if (NULL != block)
        strncpy(block, string, length);
    return block;
}
