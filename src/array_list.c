#include "../include/array_list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//// ==== Helper Functions === ////

bool _ensure_capacity(ArrayList *array_list)
{
    if (array_list == NULL)
    {
        return false;
    }

    if (list_is_full(array_list))
    {
        array_list->collection = realloc(array_list->collection, (array_list->capacity * GROWING_RATE) * sizeof(void *));
        array_list->capacity = array_list->capacity * GROWING_RATE;

        return true;
    }

    return false;
}

bool _trim_to_size(ArrayList *array_list)
{
    if (array_list == NULL)
    {
        return false;
    }

    array_list->collection = realloc(array_list->collection, array_list->size * sizeof(void *));
    array_list->capacity = array_list->size;

    return true;
}

//// ==== List "Life-Cycle" Functions ==== ////

ArrayList *list_create()
{
    ArrayList *array_list = malloc(sizeof(ArrayList));
    if (array_list == NULL)
    {
        free(array_list);
        return NULL;
    }

    array_list->collection = malloc(INITIAL_CAPACITY * sizeof(void *));
    if (array_list->collection == NULL)
    {
        free(array_list->collection);
        free(array_list);

        return NULL;
    }

    array_list->capacity = INITIAL_CAPACITY;
    array_list->size = 0;

    return array_list;
}

bool list_destroy(ArrayList *array_list)
{
    if (array_list == NULL)
    {
        return false;
    }

    free(array_list->collection);
    free(array_list);

    return true;
}

//// ==== Insertion Functions === ////

bool list_insert(ArrayList *array_list, void *element, int index)
{
    if (array_list == NULL || element == NULL)
    {
        return false;
    }
    if (index < 0 || index > array_list->size)
    {
        return false;
    }

    _ensure_capacity(array_list);

    // i still dont understand why this works :(
    for (int i = array_list->size; i > index; i--)
    {
        array_list->collection[i] = array_list->collection[i - 1];
    }
    array_list->collection[index] = element;
    array_list->size++;

    return true;
}

bool list_insert_list(ArrayList *array_list_alpha, ArrayList *array_list_bravo, int index)
{
    if (array_list_alpha == NULL || array_list_bravo == NULL)
    {
        return false;
    }
    if (index < 0 || index > array_list_alpha->size)
    {
        return false;
    }

    for (int i = 0; i < array_list_bravo->size; i++)
    {
        list_insert(array_list_alpha, array_list_bravo->collection[i], index + i);
    }

    return true;
}

bool list_append(ArrayList *array_list, void *element)
{
    if (list_insert(array_list, element, array_list->size))
    {
        return true;
    }

    return false;
}

bool list_prepend(ArrayList *array_list, void *element)
{
    if (list_insert(array_list, element, 0))
    {
        return true;
    }

    return false;
}

//// ==== Deletion Functions ==== ////

bool list_remove(ArrayList *array_list, int index)
{
    if (array_list == NULL || list_is_empty(array_list)) 
    {
        return false;
    }
    if (index < 0 || index > array_list->size)
    {
        return false;
    }

    for (int i = index; i < array_list->size; i++)
    {
        array_list->collection[i] = array_list->collection[i + 1];
    }

    array_list->size--;

    return true;
}

bool list_pop(ArrayList *array_list)
{
    if (array_list == NULL || list_is_empty(array_list))
    {
        return false;
    }

    array_list->size--;

    return true;
}

bool list_remove_element(ArrayList *array_list, void *element)
{
    if (array_list == NULL || element == NULL)
    {
        return false;
    }

    for (int i = 0; i < array_list->size; i++)
    {
        if (array_list->collection[i] == element)
        {
            list_remove(array_list, i);
            return true;
        }
    }

    return false;
}

//// ==== Miscellaneous Functions === ////

bool list_clear(ArrayList *array_list)
{
    if (array_list == NULL || list_is_empty(array_list))
    {
        return false;
    }

    while (!list_is_empty(array_list))
    {
        list_pop(array_list);
    }

    return true;
}

bool list_is_empty(ArrayList *array_list)
{
    if (array_list == NULL)
    {
        return false;
    }

    return array_list->size == 0;
}

bool list_is_full(ArrayList *array_list)
{
    if (array_list == NULL)
    {
        return false;
    }

    return array_list->size == array_list->capacity;
}

bool list_contains(ArrayList *array_list, void *element)
{
    if (array_list == NULL || element == NULL)
    {
        return false;
    }

    for (int i = 0; i < array_list->size; i++)
    {
        if (array_list->collection[i] == element)
        {
            return true;
        }
    }

    return false;
}

int list_index_of(ArrayList *array_list, void *element)
{
    if (array_list == NULL || element == NULL || list_is_empty(array_list))
    {
        return -1;
    }

    for (int i = 0; i < array_list->size; i++)
    {
        if (array_list->collection[i] == element)
        {
            return i;
        }
    }

    return -1;
}

void *list_get(ArrayList *array_list, int index)
{
    if (array_list == NULL)
    {
        return NULL;
    }
    if (index < 0 || index >= array_list->size)
    {
        return NULL;
    }

    return array_list->collection[index];
}

bool list_set(ArrayList *array_list, void *element, int index)
{
    if (array_list == NULL || element == NULL)
    {
        return false;
    }
    if (index < 0 || index >= array_list->size)
    {
        return false;
    }

    array_list->collection[index] = element;
    return true;
}
