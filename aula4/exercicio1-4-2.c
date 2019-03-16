#include<stdio.h>
#include <stdlib.h>

typedef struct pilha{
  char str[];
  int topo = -1;
}pilha;

pilha *criaPilha(){
  pilha stack = malloc(sizeof(pilha));
  return &stack;
}

void push(pilha *stack, char letra, int capacidade){
  if(stack->topo < capacidade-1){
    stack->str[stack->topo] = letra;
    stack->topo++;
  }
}

void inverte_string(char *s, char *dest){
  
}

char pop(pilha *stack, char letra){
  if(stack->topo != -1){
    stack->topo--;
    return stack->str[stack->topo+1];
  }
  return NULL;
}

int main(){

}