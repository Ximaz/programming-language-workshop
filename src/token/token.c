/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** token.c
*/

#include <stdlib.h>
#include <string.h>
#include "token.h"

token_t *token_new(token_location_t location, token_type_t type,
    token_value_t value)
{
    token_t *self = malloc(sizeof(token_t));

    if (NULL != self) {
        self->location = location;
        self->type = type;
        self->value = value;
    }
    return self;
}

void token_destroy(token_t *self)
{
    if (NULL != self && TOKEN_INT != self->type)
        free(self->value.v_str);
    free(self);
}
