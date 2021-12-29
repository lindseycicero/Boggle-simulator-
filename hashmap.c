#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <string.h>

#include "llist.h"
#include "hashmap.h"

//local function for hashing an input value (do not edit)
unsigned int _hash(hashmap_t * hm, char * val){
  //based on Java's String.hashcode()
  double k = 0;
  double len = (double) strlen(val);
  int i=1;
  for(char * c = val; *c ; c++,i++){
    k += (*c) * pow(31,len-i);
  }

  return (unsigned int) (((unsigned long) k) % hm->num_buckets);
}


//local function: resize the hashmap by doubling the number of buckets and rehashing
void _resize(hashmap_t * hm){
  hashmap_t * temp = calloc(sizeof(hashmap_t),1);
  int oldBuckets=hm->num_buckets;
  temp->num_buckets = oldBuckets*2;;
  temp->buckets = calloc(sizeof(ll_node_t),temp->num_buckets);
  temp->size = 0;
  for(int i=0; i<temp->num_buckets; i++){
    temp->buckets[i]=ll_init();
  }
  for(int i=0; i<oldBuckets; i++){
    ll_node_t * cur = hm->buckets[i]->head;
    while(cur!=NULL){
      unsigned int h = _hash(temp,cur->val);
      ll_push(temp->buckets[h],cur->val);
      cur=cur->next;
    }
    ll_delete(hm->buckets[i]);
  }
  free(hm->buckets);
  hm->buckets = temp->buckets;
  hm->num_buckets= temp->num_buckets;
  hm = temp;
  free(temp);  
}


//initliaze a hashmap with initial number of buckets
hashmap_t * hm_init(){

  //create the hashmap
  hashmap_t * hm = calloc(sizeof(hashmap_t),1);
  hm -> num_buckets = HM_INIT_NUM_BUCKETS;
  hm -> buckets = calloc(sizeof(ll_node_t),hm->num_buckets);
  for(int i=0; i<hm->num_buckets;i++){
    hm->buckets[i]= ll_init();
  }
  hm -> size = 0;  
  return hm;
}

void hm_delete(hashmap_t * hm){

  for(int i=0; i<hm->num_buckets; i++){
    ll_delete(hm->buckets[i]);
  }
  free(hm->buckets);
  //delete the hashmap
  free(hm);
}

//add a string value to the hashmap
void hm_add(hashmap_t * hm, char * val){
  // You get this function for free :)
  
  //check the load on the hashtable, if > max load, resize!
  if(((hm->size+1)/(double) hm->num_buckets) > HM_MAX_LOAD){
    _resize(hm); 
  }

  unsigned int h = _hash(hm,val); //get hash
  ll_push(hm->buckets[h],val); //note that list does string dup
  hm->size++; //increase size


}

//see if a string value is in the hashmap
bool hm_check(hashmap_t * hm, char * val){
  unsigned int h = _hash(hm,val); //get hash
  ll_node_t * cur = hm->buckets[h]->head;
  while(cur!=NULL){
    if(strcmp(cur->val,val)==0){
      return true;
    }
    cur=cur->next;
  }
  return false; //otherwise false
}




