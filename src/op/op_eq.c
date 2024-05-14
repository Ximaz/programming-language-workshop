/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_eq.c
*/

#include "stack.h"

int op_eq(istack_t *stack, ...)
{
    uint64_t b = (uint64_t) stack_pop(stack);
    uint64_t a = (uint64_t) stack_pop(stack);

    stack_push(stack, (void *) (unsigned long) (a == b));
    return 0;
}
