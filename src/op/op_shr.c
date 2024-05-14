/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_shr.c
*/

#include "stack.h"

int op_shr(istack_t *stack, ...)
{
    int64_t b = (int64_t) stack_pop(stack);
    int64_t a = (int64_t) stack_pop(stack);

    stack_push(stack, (void *) (unsigned long) (a >> b));
    return 0;
}
