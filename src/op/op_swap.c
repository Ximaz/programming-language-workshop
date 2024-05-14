/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_swap.c
*/

#include "stack.h"

int op_swap(istack_t *stack, ...)
{
    void *a = stack_pop(stack);
    void *b = stack_pop(stack);

    stack_push(stack, a);
    stack_push(stack, b);
    return 0;
}
