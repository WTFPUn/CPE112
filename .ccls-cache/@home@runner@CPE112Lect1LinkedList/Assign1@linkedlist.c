#include "linkedlist.h"
#include <stdlib.h>

/* Create a new list with the specify capacity
 * Return pointer to the list structure if successful
 *        or NULL if the list can't be created 
 *        e.g. memory allocation error  
 */
LIST_T* listCreate(int capacity)
{
    LIST_T* list = (LIST_T *) calloc(1, sizeof(LIST_T));
    return list;
}

/* Destroy the list and release all memory
 */
void listDestroy(LIST_T* list)
{
  while(list->head != NULL) {
    LISTNODE_T* temp = list->head;
    list->head = temp->next;
    free(temp); 
  }
}

/* Returns the number of elements (could be zero)
 * or -1 if the list has not been created
 */
int listSize(LIST_T* list)
{
  int count = 0;
  list->current = list->head;
  if(list->current == NULL)
    return -1;
  while(list->current != NULL) {
    count++;
    list->current = list->current->next;
  }
  return count;
}

/* Insert new element into the list at the specify index
 * Return -1 if the list hasn't been created
 *        -2 if the list is full 
 *         1 if the operation is successful
 */
int listInsertAt(LIST_T* list, int index, void* data)
{
  if(list == NULL) {
    return -1;
  }
  if(listSize(list) >= index) {
    return -2;
  }
  
  int count = 0;
  LISTNODE_T* target, temp;

  target->data = data;
  list->current = list->head;

  while(count < index) {
    list->current = list->current->next;    
    count++;
  }
  temp = list->current->next;
  target->next = temp;
  list->current->next = target;


}

/* Add new element at the end of the list
 * Return -1 if the list hasn't been created
 *        -2 if the memory allocation error 
 *         1 if the operation is successful
 */
int listAppend(LIST_T* list, void* data)
{
    if (list == NULL)
    {
        return -1;
    }

    LISTNODE_T* node = (LISTNODE_T*) calloc(1, sizeof(LISTNODE_T));
    if (node == NULL)
    {
        return -2;
    }
    node->data = data;

    if (list->head == NULL && list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
    return 1;
}

/* Remove an element at the specify index
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listRemoveAt(LIST_T* list, int index)
{
    LISTNODE_T* previousNode = list->head;
    LISTNODE_T* nodeToBeRemove;

    if (index == 0)
    {
        nodeToBeRemove = list->head;
        list->head = nodeToBeRemove->next;
        free(nodeToBeRemove->data);
        free(nodeToBeRemove);
    }
    else
    {
        int i = 0;
        while (i < index-1)
        {
            previousNode = previousNode->next;
            i++;
        }

        nodeToBeRemove = previousNode->next;
        previousNode->next = nodeToBeRemove->next; 
        if (nodeToBeRemove == list->tail) 
        {
            list->tail = previousNode;
        }
        free(nodeToBeRemove->data);
        free(nodeToBeRemove);
    }
}

/* Get an element at the specify index
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listGet(LIST_T* list, int index, void** data)
{

}

/* Reset the current element return by listGetNext to 
 * the first element of the list
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listReset(LIST_T* list)
{

}

/* Get the current element
 * Return -1 if the list hasn't been created
 *         1 if the operation is successful
 */
int listGetNext(LIST_T* list, void** data)
{

}

/* 
 * Return -1 if the list hasn't been created
 *         0 if there still some elements left to be returned from listGetNext
 *         1 if there isn't any element to be returned from listGetNext
 */
int listAtEnd(LIST_T* list)
{

}