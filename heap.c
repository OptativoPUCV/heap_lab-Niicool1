#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq->heapArray==NULL){
    return NULL;
  }
  pq->heapArray[0].data= NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if (pq->size+1 > pq->capac){
    pq->capac = (pq->capac)*2 + 1;
    pq->heapArray= realloc(pq->heapArray, (pq->capac)*sizeof(heapElem));
  }
  int x= pq->size;
  while (x>0 && pq->heapArray[(x-1)/2].priority < priority){
    pq->heapArray[x]=pq->heapArray[(x-1)/2];
    x= (x-1)/2;
  }
  pq->heapArray[x].priority=priority;
  pq->heapArray[x].data=data;
  pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap * heap_= (Heap*) malloc(sizeof(Heap));
  heap_->capac= 3;
  heap_->size=0;
  heap_->heapArray =(heapElem*) calloc (3,sizeof(heapElem));
   return heap_;
}
