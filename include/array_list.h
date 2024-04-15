#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdbool.h>

typedef struct ArrayList
{
    void **collection;
    int capacity;
    int size;
} ArrayList;

#define INITIAL_CAPACITY 128
#define GROWING_RATE 2

//// ==== Helper Functions ==== ////

/**
 * @brief this function doubles the capacity of a specified ArrayList if it's capacity equals it's size
 * @param array_list a pointer to an ArrayList structure
 * @return           a boolean of true if the operation is successful
 */
bool _ensure_capacity(ArrayList *array_list);

/**
 * this function reduces the capacity of an ArrayList to it's size
 * @param array_list a pointer to an ArrayList structure
 * @return           a boolean of true if the operation is successful
 */
bool _trim_to_size(ArrayList *array_list);

//// ==== List "Life-Cycle" Functions ==== ////

/**
 * this function returns an initialized ArrayList
 * @return an initialized ArrayList
 */
ArrayList *list_create();

/**
 * this function destroys an ArrayList
 * @param array_list a pointer to an ArrayList structure
 * @return           a boolean of true if the operation is successful
 */
bool list_destroy(ArrayList *array_list);

//// ==== Insertion Functions === ////

/**
 * this function inserts an element to an index in an ArrayList
 * @param array_list a pointer to an ArrayList structure
 * @param element    a void pointer to an element
 * @param index      an index in the ArrayList
 * @return           a boolean of true if the operation is successful
 */
bool list_insert(ArrayList *array_list, void *element, int index);

/**
 * this functions inserts an ArrayList to an index in another ArrayList
 * @param array_list_alpha a pointer to an ArrayList structure
 * @param array_list_bravo a pointer to another ArrayList structure
 * @param index            an index in list_alpha
 * @return                 a boolean of true if the operation is successful
 */
bool list_insert_list(ArrayList *array_list_alpha, ArrayList *array_list_bravo, int index);

/**
 * this function inserts an element to the end of an ArrayList
 * @param array_list a pointer to an ArrayList structure
 * @param element    a void pointer to an element
 * @return           a boolean of true if the operation is successful
 */
bool list_append(ArrayList *array_list, void *element);

/**
 * this function inserts an element to the start of an ArrayList
 * @param array_list a pointer to an ArrayList structure
 * @param element    a void pointer to an element
 * @return           a boolean of true if the operation is successful
 */
bool list_prepend(ArrayList *array_list, void *element);

//// ==== Deletion Functions ==== ////

/**
 * this function removes removes an element at an index of an ArrayList
 * @param array_list a pointer to an ArrayList structure
 * @param index      an index in this list
 * @return           a boolean of true if the operation is successful
 */
bool list_remove(ArrayList *array_list, int index);

/**
 * this function removes an element at the end of an ArrayList
 * @param array_list a pointer to an ArrayList structure
 * @return           a boolean of true if the operation is successful
 */
bool list_pop(ArrayList *array_list);

/**
 * this function removes an element from an ArrayList
 * @param array_list a pointer to an ArrayList structure
 * @param element    a void pointer to an element
 * @return a boolean of true if the operation is successful
 */
bool list_remove_element(ArrayList *array_list, void *element);

/**
 * this function removes all elements from an ArrayList
 * @param list a pointer to an ArrayList structure
 * @return     a boolean of true if the operation is successful
 */
bool list_clear(ArrayList *list);

//// ==== Miscellaneous Functions === ////

/**
 * this function checks if an ArrayList is empty
 * @param array_list a pointer to an ArrayList structure
 * @return           a boolean of true if list is empty
 */
bool list_is_empty(ArrayList *array_list);

/**
 * this function checks if an ArrayList's size is equals to it's capacity
 * @param array_list a pointer to an ArrayList structure
 * @return           a boolean of true if list is full
 */
bool list_is_full(ArrayList *array_list);

/**
 * this function searches for an element in an ArrayList
 * @param array_list a pointer to an ArrayList structure
 * @param element    a void pointer to an element
 * @return           a boolean of true if the element is found in the list
 */
bool list_contains(ArrayList *array_list, void *element);

/**
 * this function finds the zero-based index of the element in an ArrayList,
 * where the index is -1 if the element is not found in the list
 * @param array_list a pointer to an ArrayList structure
 * @param element    a void pointer to an element
 * @return           an integer representing the index of the element in the list.
 */
int list_index_of(ArrayList *array_list, void *element);

/**
 * this function returns the element in an ArrayList at the index
 * @param array_list a pointer to an ArrayList structure
 * @param index      an index in an ArrayList
 * @return           a void pointer to the element at the index in the ArrayList
 */
void *list_get(ArrayList *array_list, int index);

/**
 * this function sets the index in an ArrayList to the element
 * @param array_list a pointer to an ArrayList structure
 * @param element    a void pointer to an element
 * @param index      an index in an ArrayList
 */
bool list_set(ArrayList *list, void *element, int index);

#endif
