/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_pop.c
*/

#include "stack.h"

int op_pop(istack_t *stack, ...)
{
    return (uint64_t) stack_pop(stack);
    return 0;
}
