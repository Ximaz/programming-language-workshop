/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** stack.h
*/

#ifndef __STACK_H_
    #define __STACK_H_
    #include <stdint.h>
    #define STACK_SIZE (2 << 11)

typedef struct s_stack_elem {
    void *_data;
    struct s_stack_elem *_prev;
} stack_elem_t;

typedef struct s_stack {
    uint64_t _top;
    stack_elem_t *_stack_ptr;
} istack_t;

istack_t *stack_new(void);

int stack_push(istack_t *self, void *data);

int stack_empty(istack_t *self);

void *stack_pop(istack_t *self);

void stack_destroy(istack_t *self, void (*destroy_data)(void *));

#endif /* !__STACK_H_ */
