#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

void printListContentInt(LIST_T* list)
{
    int i = 0;
    void* data;

    // printf("List contain : ");
    // listReset(list);
    // while (!listAtEnd(list))
    // {
    //     listGetNext(list, &data);
    //     printf("%d ", *((int*) data));
    // }
    // printf("\n");

    printf("List contain : ");
    int size = listSize(list);
    for (i=0; i<size; i++)
    {
        listGet(list, i, &data);
        printf("%d ", *((int *) data));
    }
    printf("\n");
}

int* allocateHeapInt(int value)
{
    int* data = (int*) calloc(1, sizeof(int));
    *data = value;
    return data;
}

int main() 
{
    // Create new list with 4 elements : 10, 11, 12, 13
    LIST_T* list = listCreate(5);
    listAppend(list, allocateHeapInt(10));
    listAppend(list, allocateHeapInt(12));
    listAppend(list, allocateHeapInt(13));
    printf("%d", listInsertAt(list, 1, allocateHeapInt(11)));
    // listInsertAt(list, 1, allocateHeapInt(11));

    // Print list content
    // > List contain : 10 11 12 13
    printListContentInt(list);

    // Print number of element in the list
    int size = listSize(list);
    printf("Number of element in the list : %d\n", size);

    // Print data at index 1
    // > Data at index 1 : 11
    void* data;
    int retVal = listGet(list, 1, &data); // retVal is not checked for brevity
    printf("Data at index 1 : %d\n", *((int *) data));

    // Remove data at index 2 and print list content
    // > List contain : 10 11 13
    retVal = listRemoveAt(list, 2); // retVal is not checked for brevity
    printListContentInt(list);

    return 0;
}