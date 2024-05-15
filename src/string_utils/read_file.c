/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** read_file.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t get_file_size(FILE *fp)
{
    size_t size = 0;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return size;
}

char *read_file(const char *filename)
{
    size_t size = 0;
    char *source = NULL;
    FILE *fp = fopen(filename, "r");

    if (NULL == fp)
        return NULL;
    size = get_file_size(fp);
    source = calloc(size + 1, sizeof(char));
    if (NULL != source)
        fread(source, size, sizeof(char), fp);
    fclose(fp);
    return source;
}
