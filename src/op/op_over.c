/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_over.c
*/

#include "stack.h"

int op_over(istack_t *stack, ...)
{
    void *b = stack_pop(stack);
    void *a = stack_pop(stack);

    stack_push(stack, a);
    stack_push(stack, b);
    stack_push(stack, a);
    return 0;
}
