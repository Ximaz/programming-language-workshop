/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** op_syscall.c
*/

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "stack.h"

int op_syscall(istack_t *stack, ...)
{
    uint64_t i = 0;
    va_list ap = { 0 };
    char *memory = NULL;
    uint64_t nparams = 0;
    int64_t regs[6] = { 0 };

    va_start(ap, stack);
    memory = va_arg(ap, char *);
    nparams = va_arg(ap, uint64_t);
    va_end(ap);
    for (; i < nparams; ++i)
        regs[i] = (uint64_t) stack_pop(stack);
    if (2 == nparams && 60 == regs[0])
        return regs[1];
    if (3 == nparams && 1 == regs[0])
        stack_push(stack, (void *) write(regs[1], &memory[regs[2]], regs[3]));
    return 0;
}
