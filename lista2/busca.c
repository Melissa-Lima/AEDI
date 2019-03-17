#include <stdio.h>
#include <stdlib.h>

typedef struct list list;
struct list{
  int data;
  list *next;
};

list *procuraItem(list *lista, int dado){
  list *aux = lista;
  while(aux->next!=NULL){
    if(aux->data == dado){
      return aux;
    }
  } 
  return aux; 
}

int *buscaBinaria(int *array, int tam, int item){
  int left = 0;
  int right = tam-1;
  int middle = (left+right)/2;
  while(left<right){
    if(array[middle]==item){
      return &array[middle];
    }
    if(array[middle]<item){
      left = middle+1;
    }else{
      right = middle-1;
    }
    middle = (left+right)/2;
  }
  return NULL;
}

int *buscaBinariaDec(int *array, int tam, int item){
  int left = 0;
  int right = tam-1;
  int middle = (left+right)/2;
  while(left<right){
    if(array[middle]==item){
      return &array[middle];
    }
    if(array[middle]>item){
      left = middle+1;
    }else{
      right = middle-1;
    }
    middle = (left+right)/2;
  }
  return NULL;
}

int main(){
  return 0;
}