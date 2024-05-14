/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_dump.c
*/

#include <stdio.h>
#include "stack.h"

int op_dump(istack_t *stack, ...)
{
    printf("%ld\n", (int64_t) stack_pop(stack));
    return 0;
}
