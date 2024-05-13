/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** stack.c
*/

#include <stdlib.h>
#include "stack.h"

istack_t *stack_new(void)
{
    istack_t *stack = malloc(sizeof(istack_t));

    if (NULL != stack) {
        stack->_top = 0;
        stack->_stack_ptr = NULL;
    }
    return stack;
}

int stack_push(istack_t *self, void *data)
{
    stack_elem_t *elem = malloc(sizeof(stack_elem_t));

    if (NULL == elem)
        return -1;
    elem->_data = data;
    elem->_prev = self->_stack_ptr;
    self->_stack_ptr = elem;
    ++self->_top;
    return 0;
}

int stack_empty(istack_t *self)
{
    return 0 == self->_top;
}

void *stack_pop(istack_t *self)
{
    void *data = NULL;
    stack_elem_t *prev = NULL;

    if (0 == self->_top)
        return NULL;
    data = self->_stack_ptr->_data;
    prev = self->_stack_ptr->_prev;
    free(self->_stack_ptr);
    self->_stack_ptr = prev;
    --self->_top;
    return data;
}

void stack_destroy(istack_t *self, void (*destroy_data)(void *))
{
    stack_elem_t *elem = NULL;

    while (0 != self->_top && NULL != self->_stack_ptr) {
        elem = self->_stack_ptr->_prev;
        if (NULL != destroy_data)
            destroy_data(self->_stack_ptr->_data);
        free(self->_stack_ptr);
        self->_stack_ptr = elem;
        --self->_top;
    }
}
