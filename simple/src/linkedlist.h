/******************************************************************************\
|
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|
\******************************************************************************/

// Include Guards to avoid double declarations
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h> 
#include <stdlib.h>

// We will implement a doubly linked list. Each element points towards its 
// previous and next element in the list.
// Notice that you can easily modify iy to get a Queue or a Stack !

// In this implementation, we assume that the list will only contain natural
// integer (otherwise, we would encounter issues in the get function. Send a
// mail if you want more details)

// Defining an element type
typedef struct Element
{
    int value;
    struct Element *next;
    struct Element *previous;
}Element;

// Defining the general data structure
typedef struct LinkedList
{
    Element *first;
    Element *last;
    int size;
}LinkedList;

LinkedList *list_init();
void list_alloc_test(LinkedList *list);
void list_deinit(LinkedList *linkedlist);

void list_add(LinkedList *linkedlist, int iValueToAdd);
void list_del(LinkedList *linkedlist, int iValueToDel);
int list_get(LinkedList *linkedlist, int iPosition);
void list_print(LinkedList *linkedlist);

#endif
