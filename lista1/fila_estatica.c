#include <stdio.h>
#include <stdlib.h>
#define CAPACIDADE 5

typedef struct queue queue;

struct queue{
  int dado[CAPACIDADE];
  int front;
  int back;
};

void printaFila(queue *fila){
  int i;
  for(i=0; i<CAPACIDADE; i++){
    printf("%d ",fila->dado[i]);
  }
  printf("\n");
}

queue *criaFila(){
  queue *fila = malloc(sizeof(queue));
  fila->front = -1;
  fila->back = -1;
  return fila;
}

queue *push(queue *fila, int dado){
  if (((fila->back)+1) % CAPACIDADE == fila->front){
    return NULL;
  }
  if(fila->front == -1){
    fila->front++;
  }
  fila->back = ((fila->back)+1) % CAPACIDADE;
  fila->dado[fila->back] = dado;
  return fila;
}

int *pop(queue **fila){
  int *dado;
  int pop = (*fila)->front;
  if((*fila)->front == -1){
    return NULL;
  }
  if((*fila)->front == (*fila)->back){
    (*fila)->front = pop-1;
  }else{
    (*fila)->front = pop+1;
  }
  dado = &((*fila)->dado[pop]);
  (*fila)->dado[pop] = 0;
  return dado;
}

int main(){
  int dado,i;
  queue **fila;
  *fila = criaFila();
  for(i=0; i<CAPACIDADE; i++){
    scanf("%d",&dado);
    *fila = push(*fila,dado);
    printaFila(*fila);
  }
  for(i=0; i<CAPACIDADE; i++){
    pop(fila);
    printaFila(*fila);
  }
  return 0;
}