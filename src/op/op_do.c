/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_do.c
*/

#include "stack.h"

int op_do(istack_t *stack, ...)
{
    return (0 == (uint64_t) stack_pop(stack));
}
