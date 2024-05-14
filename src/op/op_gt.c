/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_gt.c
*/

#include "stack.h"

int op_gt(istack_t *stack, ...)
{
    int64_t b = (int64_t) stack_pop(stack);
    int64_t a = (int64_t) stack_pop(stack);

    stack_push(stack, (void *) (unsigned long) (a > b));
    return 0;
}
