#include "array.h"


/* ---------------- Memory manipulation for data structure ---------------- */

void array_alloc_test(Array *array){
    // Test if the array is allocated in memory, if not returns with error
    if (array == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

Array *array_init()
{
    // Define a pointer to an Array structure and reserves the necessary size
    Array *array = malloc(sizeof(*array));

    // Test if the pointer has been allocated
    array_alloc_test(array);

    // We define the basic elements
    array->size = 0;
    array->capacity = INITIAL_SIZE;
    array->content = malloc(sizeof(int) * array->capacity);

    // Every time you use a pointer, it needs to be allocated. We test this now
    // for the content of the array
    if (array->content == NULL)
    {
        printf("ERROR. The content of the array could not be initialize.\n");
        exit(EXIT_FAILURE);
    }

    return array;
}

void array_double_size_if_full(Array *array){
    /**
    This function uses the realloc function to take the content array and double
    its size.
    Check for dynamic memory allocation to found out more about this.
    Functions to check are :
      - malloc
      - calloc
      - realloc
    **/

    // Test if the array exists in the first place (pointer is allocated)
    array_alloc_test(array);

    int *contentTmp;

    if (array->size >= array->capacity)
    {
        // Modification of the capacity
        array->capacity *= 2;
        // Reallocation of the content in a new array two times bigger
        contentTmp = realloc(array->content, sizeof(int) * array->capacity);
        // Test if reallocation went well
        if (contentTmp == NULL)
        {
            array_deinit(array);
            printf("ERROR. The content could not be reallocated\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            array->content = contentTmp;
        }
    }
}

void array_deinit(Array *array)
{
    /**
    This function will now deallocate all the pointers we have used. This is 
    necessary to free the memory.

    /!\ Be careful, if the content element is an array of string (array of 
    array of char), you will need to deallocate all the different string also
    if you used a pointer to define them !
    **/
    array_alloc_test(array);
    free(array->content);
    free(array);
}


/* ---------------- Manipulation of the data structure ---------------- */

void add(Array *array, int iValueToAdd){
    array_alloc_test(array);
    // Check if it is possible to add a new value, if the content array is full,
    // we need to double its size
    array_double_size_if_full(array);

    array->content[array->size++] = iValueToAdd;
    // Be careful here again, with strings, you would need to use the string.h
    // library and the strcpy function as one cannot generally assign an 
    // array with an equal sign.
}

void add_at(Array *array, int iValueToAdd, int iPosition)
{
    array_alloc_test(array);
    array_double_size_if_full(array);

    int i;

    // If iPosition is not in array
    if (iPosition > array->size)
    {
        printf("ERROR. There are only %d element in the array.\n", array->size);
    }
    else
    {
        array->size++;
        // We need to shift the position to the right to make place for the new
        // element. To do so, we start from the end of the array.
        for (i = iPosition; i < array->size - 1; ++i)
        {
            array->content[array->size + iPosition - 1 - i] = array->content[array->size + iPosition - 2 - i];
        }
        array->content[iPosition] = iValueToAdd;
    }
}

void del(Array *array, int iValueToDel)
{
    array_alloc_test(array);

    int i = 0, iKeepGoing = 1;
    while(iKeepGoing == 1 && i < array->size)
    {
        if (array->content[i] == iValueToDel)
        {   
            // We need to shift the array to delete the element.
            while (i < array->size - 1)
            {
                array->content[i] = array->content[i + 1];
                i++;
            }
            array->size--;
            iKeepGoing = 0;
        }
        else
        {
            i++;
        }
    }
    if (iKeepGoing == 1)
    {
        printf("ERROR. Element not found in the array.\n");
    }
}

void del_at(Array *array, int iPositionToDel)
{
    /**
    In this function, we simply shift the values after iPositionToDel to the
    left. 

    RQ: You will notice that we do not change what is in the last index.
    **/
    array_alloc_test(array);

    if (iPositionToDel > array->size - 1)
    {
        printf("ERROR. The array only contains %d elements\n", array->size);
    }
    else
    {
        int i = 0;
        for (i = iPositionToDel; i < array->size - 1; ++i)
        {
            array->content[i] = array->content[i+1];
        }
        array->size--;
    }
}
int get(Array *array, int iPosition)
{
    array_alloc_test(array);

    if (iPosition > array->size - 1)
    {
        printf("ERROR. The array only contains %d elements\n", array->size);
        return -1;
    }

    return array->content[iPosition];
}

int find(Array *array, int iValueToFind)
{
    array_alloc_test(array);

    int iPosition = 0;

    while (iPosition < array->size)
    {
        if (array->content[iPosition] == iValueToFind)
        {
            iPosition = array->size;
            return iPosition;
        }
        else
        {
            iPosition++;
        }
    }
    return -1;
}

int size(Array *array){
    array_alloc_test(array);
    return array->size;
}

void prt(Array *array){
    array_alloc_test(array);

    printf("[");
    int i;
    for (i = 0; i < array->size; i++)
    {
        printf("%d", array->content[i]);
        if (i != array->size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
