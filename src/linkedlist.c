#include "linkedlist.h"

/* ---------------- Memory manipulation for data structure ---------------- */

void list_alloc_test(LinkedList *list){
    // Test if the list is allocated in memory, if not returns with error
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

LinkedList *linkedlist_init()
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

void linkedlist_deinit(LinkedList *list)
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

void l_add(LinkedList *list, int iValueToAdd)
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

void l_add_at(LinkedList *list, int iValueToAdd, int iPosition)
{
    list_alloc_test(list);

    Element *element = malloc(sizeof(*element));
    Element *elementCurrent;
    int i;

    if (element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Testing if the position where we want to add the int is not higher than 
    // the size of the list
    // The position to add can be equal to the size because we add before the 
    // iPosition. So if we want to be able to add at the end of the list, 
    // we need to allow the iPosition to be equal to the size of the list.
    if (iPosition > list->size)
    {
        printf("ERROR. The list only contains %d elements.\n", list->size);
    }
    else
    {
        // defining the element struct to add
        element->value = iValueToAdd;

        elementCurrent = list->first;
        if (iPosition == 0)
        {
            if (list->size == 0)
            {
                element->next = NULL;
                element->previous = NULL;
                free(elementCurrent);
            }
            else
            {
                element->next = elementCurrent;
                element->previous = NULL;
            }
            list->first = element;
        }
        else
        {
            for (i = 1; i < iPosition; i++)
            {
                elementCurrent = elementCurrent->next;
            }
            element->next = elementCurrent->next;
            element->previous = elementCurrent;
            elementCurrent->next = element;
        }

        if (element->next == NULL)
        {
            list->last = element;
        }
        
        list->size += 1;
    }
}

void l_del(LinkedList *list, int iValueToDel)
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

void l_del_at(LinkedList *list, int iPositionToDel)
{
    list_alloc_test(list);

    Element *elementNext, *elementCurrent;
    int iPosition = 0;

    // If the position to delete is not reachable in the list
    // Be careful that we start at 0 in the numerotation !
    if (iPositionToDel >= list->size)
    {
        printf("ERROR. There are only %d elements in the list.\n", list->size);
    }
    else
    {
        // if the list contains only one element
        if (list->size == 1)
        {
            free(list->first);
            list->first = NULL;
            list->last = NULL;
            list->size = 0;
        }
        else
        {
            elementCurrent = list->first;
            elementNext = elementCurrent->next;
            if (iPositionToDel == 0)
            {
                list->first = elementNext;
                elementNext->previous = NULL;
                free(elementCurrent);
            }
            else if (iPositionToDel == list->size - 1)
            {
                list->last = list->last->previous;
                free(list->last->next);
                list->last->next = NULL;
            }
            else
            {
                while (iPosition < iPositionToDel - 1)
                {
                    iPosition++;
                    elementCurrent = elementNext;
                    elementNext = elementNext->next;
                }
                elementCurrent->next = elementNext->next;
                elementNext->next->previous = elementCurrent;
                free(elementNext);
            }
            list->size -= 1;
        }
    }
}

int l_get(LinkedList *list, int iPosition)
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

int l_find(LinkedList *list, int iValueToFind)
{
    list_alloc_test(list);

    int iPosition = 0;
    Element *elementCurrent;

    elementCurrent = list->first;
    while (elementCurrent != NULL)
    {
        if (elementCurrent->value == iValueToFind)
        {   
            return iPosition;
        }
        else
        {
            iPosition += 1;
            elementCurrent = elementCurrent->next;
        }
    }
    return -1;
}

int l_size(LinkedList *list)
{
    return list->size;
}

void l_prt(LinkedList *list)
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
