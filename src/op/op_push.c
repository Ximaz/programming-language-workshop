/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_push.c
*/

#include <stdarg.h>
#include "stack.h"

int op_push_int(istack_t *stack, ...)
{
    va_list ap = { 0 };
    int64_t n = 0;

    va_start(ap, stack);
    n = va_arg(ap, int64_t);
    va_end(ap);
    stack_push(stack, (void *) n);
    return 0;
}

int op_push_str(istack_t *stack, ...)
{
    va_list ap = { 0 };
    uint64_t str_addr = 0;
    uint64_t length = 0;

    va_start(ap, stack);
    str_addr = va_arg(ap, uint64_t);
    length = va_arg(ap, uint64_t);
    va_end(ap);
    stack_push(stack, (void *) length);
    stack_push(stack, (void *) str_addr);
    return 0;
}
