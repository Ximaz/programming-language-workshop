/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_2dupp.c
*/

#include "stack.h"

int op_2dupp(istack_t *stack, ...)
{
    void *data_a = stack_pop(stack);
    void *data_b = stack_pop(stack);

    stack_push(stack, data_a);
    stack_push(stack, data_b);
    stack_push(stack, data_a);
    stack_push(stack, data_b);
    return 0;
}
