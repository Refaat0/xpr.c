#ifndef STACK_H
#define STACK_H

#include "../include/array_list.h"
#include <stdbool.h>

typedef struct Stack
{
    ArrayList *collection;
    int size;
} Stack;

//// ==== Stack "Life-Cycle" Functions ==== ////
/**
 * this function returns an initialized Stack
 * @return an initialized Stack
 */
Stack *stack_create();

/**
 * this function destroys a Stack
 * @param stack a pointer to a Stack structure
 * @return      a boolean of true if the operation is successful
 */
bool stack_destroy(Stack *stack);

//// ==== Stack Operational Functions ==== ////

/**
 * this functions pushes an element onto the top of a Stack
 * @param stack   a pointer to a Stack structure
 * @param element a void pointer to an element
 * @return        a boolean of true of the operation is successful
 */
bool stack_push(Stack *stack, void *element);

/**
 * this function returns the element at the top of the Stack
 * @param stack a pointer to a Stack structure
 * @return      the element at the top of the stack
 */
void *stack_peek(Stack *stack);

/**
 * this function removes the element from the top of a Stack
 * @param stack a pointer to a Stack structure
 * @return      ...
 */
void *stack_pop(Stack *stack);

/**
 * this function checks if the Stack is empty
 * @param stack a pointer to a Stack structure
 * @return      a boolean of true if the stack is empty
 */
bool stack_is_empty(Stack *stack);

/**
 * this function pops off all the elements from a Stack
 * @param stack a pointer to a Stack structure
 * @return      a boolean of true if the operation is successful
 */
bool stack_clear(Stack *stack);

/**
 * this function converts the Stack to an ArrayList
 * @param stack a pointer to a Stack structure
 * @return      an Arraylist containing all the elements from the stack, in order of appearance
 */
ArrayList *stack_to_list(Stack *stack);

/**
 * this function checks if an element is in the Stack
 * @param stack a pointer to a Stack structure
 * @return      a boolean of true if the element is found in the Stack
 */
bool stack_contains(Stack *stack, void *element);

/**
 * this function returns the 1-based index of where an element is in the Stack,
 * where the index is the distance from the top of the stack to the specified element
 * @param stack   a pointer to a Stack structure
 * @param element a void pointer to an element
 * @return ...
 */
int stack_search(Stack *stack, void *element);

#endif
