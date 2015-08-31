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
    int position, siz, el;

    /*** Example for the array ***/

    Array *array;
    array = array_init();

    printf("Empty array\n");
    prt(array);
    
    printf("Array with 1, 2 and 3 added.\n");
    add(array, 1);
    add(array, 2);
    add(array, 3);
    prt(array);
    
    printf("Array with 4 added at position 0.\n");
    add_at(array, 4, 0);
    prt(array);
    
    printf("Array with 3 deleted.\n");
    del(array, 3);
    prt(array);
   
    printf("Array with element at position 0 deleted.\n");
    del_at(array, 0);
    prt(array);
 
    printf("Looking for element at position number 1.\n");
    el = get(array, 1);
    printf("%d\n", el);

    printf("Looking for element at position number 2.\n");
    el = get(array, 2);
    printf("%d\n", el); 

    printf("Looking for element 2.\n");
    position = find(array, 2);
    printf("%d\n", position);

    printf("Looking for element 4.\n");
    position = find(array, 4);
    printf("%d\n", position);

    printf("Print the size of the array\n");
    siz = size(array);
    printf("%d\n", siz);

    printf("Print the current Array\n");
    prt(array);

    array_deinit(array);


    /*** Example for the list ***/
    printf("-----------------------------------\n");

    LinkedList *list;
    list = linkedlist_init();

    printf("Empty list\n");
    l_prt(list);
    
    printf("LinkedList with 1, 2 and 3 added.\n");
    l_add(list, 1);
    l_add(list, 2);
    l_add(list, 3);
    l_prt(list);
    
    printf("LinkedList with 4 added at position 0.\n");
    l_add_at(list, 4, 0);
    l_prt(list);
    
    printf("LinkedList with 3 deleted.\n");
    l_del(list, 3);
    l_prt(list);
   
    printf("LinkedList with element at position 0 deleted.\n");
    l_del_at(list, 0);
    l_prt(list);
 
    printf("Looking for element at position number 1.\n");
    el = l_get(list, 1);
    printf("%d\n", el);

    printf("Looking for element at position number 2.\n");
    el = l_get(list, 2);
    printf("%d\n", el); 

    printf("Looking for element 2.\n");
    position = l_find(list, 2);
    printf("%d\n", position);

    printf("Looking for element 4.\n");
    position = l_find(list, 4);
    printf("%d\n", position);

    printf("Print the size of the list\n");
    siz = l_size(list);
    printf("%d\n", siz);

    printf("Print the current LinkedList\n");
    l_prt(list);

    linkedlist_deinit(list);
 
    return 0;
}
