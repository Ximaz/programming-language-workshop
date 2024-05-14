/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_mem.c
*/

#include "stack.h"
#include "program.h"

int op_mem(istack_t *stack, ...)
{
    stack_push(stack, (void *) STRING_CAPACITY);
    return 0;
}
