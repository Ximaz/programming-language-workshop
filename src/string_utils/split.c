/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** split.c
*/

#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

static size_t count_blocks(const char *string, const char *sep, size_t sep_len)
{
    size_t count = 1;
    const char *tmp = strstr(string, sep);

    while (NULL != tmp) {
        tmp = strstr(tmp + sep_len, sep);
        ++count;
    }
    return count;
}

static char *new_block(const char *string, const char *sep, size_t *len)
{
    const char *tmp = strstr(string, sep);

    if (NULL == tmp) {
        *len = 0;
        return NULL;
    }
    *len = tmp - string;
    return strndup(string, *len);
}

char **split(const char *string, const char *sep)
{
    size_t cursor = 0;
    size_t sep_len = strlen(sep);
    char *block = NULL;
    size_t block_idx = 0;
    size_t block_len = 0;
    size_t blocks_count = count_blocks(string, sep, sep_len);
    char **blocks = (char **) calloc(blocks_count + 1, sizeof(char *));

    if (NULL == blocks)
        return NULL;
    block = new_block(&string[cursor], sep, &block_len);
    while (NULL != block) {
        blocks[block_idx] = block;
        ++block_idx;
        cursor += block_len + sep_len;
        block = new_block(&string[cursor], sep, &block_len);
    }
    blocks[block_idx] = strndup(&string[cursor], strlen(&string[cursor]));
    return blocks;
}

void destroy_split(char **self)
{
    size_t i = 0;

    if (NULL == self)
        return;
    while (NULL != self[i]) {
        free(self[i]);
        ++i;
    }
    free(self);
}
