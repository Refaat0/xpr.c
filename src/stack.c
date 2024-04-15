#include "../include/array_list.h"
#include "../include/stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//// ==== Stack "Life-Cycle" Functions ==== ////

Stack *stack_create()
{
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->collection = list_create();
    if (stack->collection == NULL)
    {
        list_destroy(stack->collection);
        free(stack);

        return NULL;
    }

    stack->size = 0;
    return stack;
}

bool stack_destroy(Stack *stack)
{
    if (stack == NULL)
    {
        return false;
    }

    list_destroy(stack->collection);
    free(stack);

    return true;
}

//// ==== Stack "Life-Cycle" Functions ==== ////

bool stack_push(Stack *stack, void *element)
{
    if (stack == NULL || element == NULL)
    {
        return false;
    }

    if (list_append(stack->collection, element) == true)
    {
        stack->size++;
        return true;
    }

    return false;
}

void *stack_peek(Stack *stack)
{
    if (stack == NULL || stack_is_empty(stack))
    {
        return NULL;
    }

    void *element = list_get(stack->collection, stack->size - 1);

    if (element == NULL)
    {
        return NULL;
    }

    return element;
}

void *stack_pop(Stack *stack)
{
    if (stack == NULL)
    {
        return false;
    }

    void *v = stack_peek(stack);
    if (list_pop(stack->collection) == true)
    {
        stack->size--;
        return v;
    }

    return NULL;
}

bool stack_is_empty(Stack *stack)
{
    if (stack == NULL)
    {
        return false;
    }

    return stack->size == 0;
}

bool stack_clear(Stack *stack)
{
    if (stack == NULL)
    {
        return false;
    }

    list_clear(stack->collection);
    stack->size = 0;

    return true;
}

ArrayList *stack_to_list(Stack *stack)
{
    return stack->collection;
}

bool stack_contains(Stack *stack, void *element)
{
    if (stack == NULL || element == NULL)
    {
        return false;
    }

    return list_contains(stack->collection, element);
}

int stack_search(Stack *stack, void *element)
{
    if (stack == NULL || element == NULL)
    {
        return -1;
    }

    int index = list_index_of(stack->collection, element);

    if (index == -1)
    {
        return -1;
    }

    return index + 1;
}