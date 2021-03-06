#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct _listnode
{
    void* data;                 /* data of this node */
    struct _listnode* next;     /* link to the next node */ 
} LISTNODE_T;

typedef struct
{
    LISTNODE_T* head;           /* first item in list */  
    LISTNODE_T* tail;           /* last item in list */ 
    LISTNODE_T* current;        /* current item in list */  
} LIST_T;

/* Create a new list with the specify capacity
 * Return pointer to the list structure if successful
 *        or NULL if the list can't be created 
 *        e.g. memory allocation error  
 */
LIST_T* listCreate(int capacity);

/* Destroy the list and release all memory
 */
void listDestroy(LIST_T* list);

/* Returns the number of elements (could be zero)
 * or -1 if the list has not been created
 */
int listSize(LIST_T* list);

/* Insert new element into the list at the specify index
 * Return -1 if the list hasn't been created
 *        -2 if the list is full 
 *         1 if the operation is successful
 */
int listInsertAt(LIST_T* list, int index, void* data);

/* Add new element at the end of the list
 * Return -1 if the list hasn't been created
 *        -2 if the list is full 
 *         1 if the operation is successful
 */
int listAppend(LIST_T* list, void* data);

/* Remove an element at the specify index
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listRemoveAt(LIST_T* list, int index);

/* Get an element at the specify index
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listGet(LIST_T* list, int index, void** data);

/* Reset the current element return by listGetNext to 
 * the first element of the list
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listReset(LIST_T* list);

/* Get the current element
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listGetNext(LIST_T* list, void** data);

/* 
 * Return -1 if the list hasn't been created
 *         0 if there still some elements left to be returned from listGetNext
 *         1 if there isn't any element to be returned from listGetNext
 */
int listAtEnd(LIST_T* list);

#endif