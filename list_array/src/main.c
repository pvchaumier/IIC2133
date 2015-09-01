/******************************************************************************\
|   --  TAREA1.C --
|   Author:     Chaumier Pierre-Victor <pvchaumier@uc.cl>
|   Date:       20/03/2015
|   Comments:   IIC2133 - estructuras de datos - tarea1
\******************************************************************************/

#include <stdio.h> 
#include <stdlib.h>

#include "array.h"
#include "linkedlist.h"

int main( int argc, char *argv[] )
{
    int el;

    /*** Example for the array ***/

    Array *array;
    array = array_init();

    printf("Empty array\n");
    array_print(array);
    
    printf("Array with 1, 2 and 3 added.\n");
    array_add(array, 1);
    array_add(array, 2);
    array_add(array, 3);
    array_print(array);
    
    printf("Array delete the 3.\n");
    array_del(array, 3);
    array_print(array);
   
 
    printf("Looking for element at position number 1.\n");
    el = array_get(array, 1);
    printf("%d\n", el);

    printf("Looking for element at position number 2.\n");
    el = array_get(array, 2);
    printf("%d\n", el); 

    array_deinit(array);


    /*** Example for the list ***/
    printf("-----------------------------------\n");

    LinkedList *list;
    list = list_init();

    printf("Empty list\n");
    list_print(list);
    
    printf("LinkedList with 1, 2 and 3 added.\n");
    list_add(list, 1);
    list_add(list, 2);
    list_add(list, 3);
    list_print(list);
    
    printf("LinkedList with 3 deleted.\n");
    list_del(list, 3);
    list_print(list);
 
    printf("Looking for element at position number 1.\n");
    el = list_get(list, 1);
    printf("%d\n", el);

    printf("Looking for element at position number 2.\n");
    el = list_get(list, 2);
    printf("%d\n", el); 

    list_deinit(list);
 
    return 0;
}
