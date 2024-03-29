#include <stdio.h>
#include <stdlib.h>
#include "history.h"


List* init_history () {

  List* itemList;

  itemList = (List*)malloc(sizeof(Item));

  itemList->root = NULL;


}

void add_history (List *list, char *str) {

  Item* listCopy = list->root; //holds root

  //changes id to prev added nodes

  //to have a new node have id: 1

  int i;


  for (i=0;listCopy != NULL; i++) {

    listCopy->id = i+2;

    listCopy = listCopy->next;

  }

  Item listItem;

  listItem.id = 1;


  //allocate memory and copy string into listItem string

  listItem.str = (char*)malloc(sizeof(str));

  char* strCopy = str; //copy to not affect str

  for (i = 0; strCopy[0] != '\0'; i++) {

    listItem.str[i] = strCopy[0];

    strCopy++;
  }

  listItem.next = list->root;

  list->root = malloc(sizeof(Item));

  list->root[0] = listItem;

}

char *get_history (List *list, int id) {

  if(list->root == NULL){

    return '\0';    
  }

  //traverse list to find id

  Item* listCopy = list->root;

  while(listCopy != NULL && listCopy->id != id){

    listCopy = listCopy->next;

  }

  return listCopy->str;

}

void print_history (List *list) {

  if(list->root == NULL){

    printf("There is no history.\n");

    return;

  }

  printf("Full History:\n");

  Item* listCopy = list->root;

  while (listCopy != NULL) {

    printf("----------------------\n");

    printf("ID: %d\n", listCopy->id);

    printf("Entry: %s\n", listCopy->str);

    printf("----------------------\n");

    listCopy = listCopy->next;

  }
}

void free_history (List *list) {

  Item* curr = list->root;

  Item* next = list->root->next;


  while(next != NULL){

    free(curr); //frees current node
    curr = next;
    next = curr->next;
  }
  free(curr); //since loop stops 1 before end
  free(list);
}
