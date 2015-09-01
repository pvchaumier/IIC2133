#include "linkedlist.h"

/* ---------------- Memory manipulation for data structure ---------------- */

void list_alloc_test(LinkedList *list){
    // Test if the list is allocated in memory, if not returns with error
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

LinkedList *list_init()
{
    LinkedList *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->value = 0;
    element->next = NULL;
    element->previous = NULL;
    
    list->first = element;
    list->last = element;
    list->size = 0;

    return list;
}

void list_deinit(LinkedList *list)
{
    list_alloc_test(list);

    Element *elementCurrent, *elementNext;

    elementCurrent = list->first;
    while (elementCurrent != NULL)
    {
        elementNext = elementCurrent->next;
        free(elementCurrent);
        elementCurrent = elementNext;
    }
    free(elementCurrent);
    free(elementNext);
    free(list);
}

/* ---------------- Manipulation of the data structure ---------------- */

void list_add(LinkedList *list, int iValueToAdd)
{
    list_alloc_test(list);

    Element *element = malloc(sizeof(*element));

    if (element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->value = iValueToAdd;
    element->next = NULL;

    if (list->size == 0)
    {
        free(list->first);
        element->previous = NULL;
        list->first = element;

    }
    else
    {
        element->previous = list->last;
        list->last->next = element;
    }
    
    list->last = element;
    list->size += 1;
}

void list_del(LinkedList *list, int iValueToDel)
{
    list_alloc_test(list);

    Element *elementCurrent, *elementPrevious;
    
    // List empty
    if (list->size == 0)
    {
        printf("ERROR. List is empty, nothing to delete\n");
    }
    // List contains only one element
    else if (list->size == 1)
    {
        elementCurrent = list->first;
        if (elementCurrent->value == iValueToDel)
        {
            free(elementCurrent);
            list->first = NULL;
            list->last = NULL;
            list->size = 0;
        }
        else
        {
            printf("ERROR. Element not in list, nothing to delete\n");
        }
    }
    // List has at least two elements
    else
    {
        elementPrevious = list->first;
        elementCurrent = elementPrevious->next;

        // Element to delete is the first one
        if (elementPrevious->value == iValueToDel)
        {
            list->first = elementCurrent;
            elementCurrent->previous = NULL;
            list->size -= 1;
            free(elementPrevious);
        }
        // Element to delete is not the first
        else
        {
            // Loop to check if any of the value of the elements is iValueToDel
            int iKeepGoing = 1;
            while (elementCurrent != NULL && iKeepGoing == 1)
            {
                if (elementCurrent->value == iValueToDel)
                {
                    iKeepGoing = 0;
                    elementPrevious->next = elementCurrent->next;
                    list->size -= 1;
                    // if we are deleting the last element
                    if (elementCurrent->next == NULL)
                    {
                        list->last = elementPrevious;
                    }
                    else
                    {
                        elementCurrent->next->previous = elementPrevious;
                    }
                    free(elementCurrent);
                }
                else
                {
                    elementPrevious = elementCurrent;
                    elementCurrent = elementCurrent->next;
                }
            }
            // Feedback if element was not found
            if (iKeepGoing == 1)
            {
                printf("ERROR. Element not found.\n");
            }
        }
    }
}

int list_get(LinkedList *list, int iPosition)
{
    list_alloc_test(list);

    Element *elementCurrent;
   
    if (iPosition > list->size - 1)
    {
        printf("ERROR. The list only contains %d elements.\n", list->size);
        return -1;
    }
    else
    {
        int i;
        elementCurrent = list->first;
        for (i = 0; i < iPosition; i++)
        {
            elementCurrent = elementCurrent->next;
        }
        return elementCurrent->value;
    }
}

void list_print(LinkedList *list)
{
    list_alloc_test(list);

    Element *elementCurrent;

    printf("{");

    if (list->size > 0)
    {
        elementCurrent = list->first;
        while (elementCurrent != NULL)
        {
            printf("%d", elementCurrent->value);
            elementCurrent = elementCurrent->next;
            if (elementCurrent != NULL)
            {
                printf(", ");
            }
        }
    }
    printf("}\n");
}
