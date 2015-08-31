/******************************************************************************\
|
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|
\******************************************************************************/

// Include Guards to avoid double declarations
#ifndef array_H
#define array_H

#include <stdio.h> 
#include <stdlib.h>

// When the array will be initialized, it will be of size INITIAL_SIZE
// Notice that it is empty for now
// You can modify this value
#define INITIAL_SIZE 10

// typedef allows you to use Array instead of struct Array when defyning new 
// variables
typedef struct Array
{
    // Number of element in the array
    int size; 
    // How many elements the current array can contain
    int capacity; 
    // What is in the array, in this case we have an array of int
    // this is where you should modify the code if you want to 
    // change the type of the content
    int *content; 
}Array;

Array *array_init();
void array_alloc_test(Array *array);
void array_double_size_if_full(Array *array);
void array_deinit(Array *array);

void add(Array *array, int iValueToAdd);
void add_at(Array *array, int iValueToAdd, int iPosition);
void del(Array *array, int iValueToDel);
void del_at(Array *array, int iPositionToDel);
int get(Array *array, int iPosition);
int find(Array *array, int iValueToFind);
int size(Array *array);
void prt(Array *array);

#endif
