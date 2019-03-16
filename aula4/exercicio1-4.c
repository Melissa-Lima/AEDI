#include <stdio.h>
#include <stdlib.h>
#define CAPACIDADE 101

typedef struct pilha{
  char str[CAPACIDADE];
  int topo;
}pilha;

pilha criar_pilha(){
  pilha p;
  p.topo = -1;
  return p;
}

int conta_string(char str[]){
  int cont,i;
  for(i=0; str[i]!='\n'; i++){
    cont++;
  }
  return cont;
}

void push(pilha *pilha, char c, int tam){
  if((pilha->topo) < tam-1){
    pilha->str[pilha->topo+1] = c;
    pilha->topo++;
  }
}

char pop(pilha *pilha){
  if(pilha->topo==-1){
    return NULL;
  }
  pilha->topo--;
  return pilha->str[pilha->(topo+1)];
}

void inverte_string(char *s, char *dest){
  int i = 0;
  while((s->topo)>=0){
    dest->str[i]=pop(s);
    i++;
  }
}

int main(){
  int tam,i;
  char str[CAPACIDADE];
  pilha *s, *dest;

  dest=malloc(sizeof(pilha));
  fgets(str,CAPACIDADE,stdin);
  s=(criar_pilha());

  tam=conta_string(str);
  for(i=0; i<tam; i++){
    s->str[i]=str[i];
  }
  inverte_string(s,dest);
  return 0;

}

// {
//   int tam = conta_string(*s);
//   for(i=0; i<tam; i++){

//   }
// }

// int main(){
//   char str, inv, *s, *dest;
//   s=str;
//   inv=dest;
//   fgets(str,30,stdin);
//   inverte_string(s,dest);
//   return 0;
// }