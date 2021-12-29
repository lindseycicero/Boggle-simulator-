#include <stdlib.h>
#include <string.h>

#include "llist.h"

//initialize a linked list
llist_t * ll_init(){
  llist_t * ll = malloc(sizeof(llist_t));
  ll -> head = NULL;
  ll -> size = 0;
  return ll; //clearly it shouldn't return null when you finish it
}

//delete a linked list
void ll_delete(llist_t * ll){
  if(ll==NULL){
    return;
  }
  ll_node_t * cur = ll->head;
  while(cur!=NULL){
    ll_node_t *next = cur->next;
    free(cur->val);
    free(cur);
    cur=next;
  }
  free(ll);
}


//push an item onto the front of the list
void ll_push(llist_t * ll, char * s){
  if(ll==NULL){
    return;
  }
  ll_node_t * item = malloc(sizeof(ll_node_t));
  item -> val = strdup(s);
  item->next = ll->head;
  ll->head=item;
  ll->size++;
}





