#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *list = (List *)malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
}

/* Get the length of the string. */
int length_of_str(char *str)
{  
  int i;
  for(i = 0; str[i] != '\0'; i++)
    ;
  
  return i;
}

/* Add a history item to the end of the list.
       List* list - the linked list
       char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *new_entry = (Item *)malloc(sizeof(Item));

  new_entry->str  = copy_str(str, length_of_str(str));
  new_entry->next = NULL;
  
  /* If list is empty. */
  if (list->head == NULL) {
    list->head    = new_entry;
    list->tail    = new_entry;
    new_entry->id = 1;
  }

  else {
    int last_id = list->tail->id;
    list->tail->next = new_entry;
    list->tail       = new_entry;
    new_entry->id    = last_id + 1;
  }
}

/* Retrieve the string stored in the node where Item->id == id.
       List* list - the linked list
       int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  if (list->tail->id < id){
    printf("Error: Index our of bounds");
    return NULL;
  }

  Item *current = list->head;

  /* Iterate to find id. */
  while(current->id != id) {
    current = current->next;
  }
  return current->str;
}

/* Print the entire contents of the list. */
void print_history(List *list)
{
  
  Item *current = list->head;

  while (current != NULL){
    printf("%s", current->str);
    current = current->next;
  }
  printf("\n");
  
}

/* Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *current = list->head;
  Item *next;

  while (current != NULL) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
}
