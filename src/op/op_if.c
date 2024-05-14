/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_if.c
*/

#include "stack.h"

int op_if(istack_t *stack, ...)
{
    return (0 == (uint64_t) stack_pop(stack));
}
