/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_dupp.c
*/

#include "stack.h"

int op_dupp(istack_t *stack, ...)
{
    void *data = stack_pop(stack);

    stack_push(stack, data);
    stack_push(stack, data);
    return 0;
}
