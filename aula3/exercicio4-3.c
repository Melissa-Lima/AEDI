#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int dados;
  struct node *next;
}node;

node *criaNode(int novo){
  node *newNode = malloc(sizeof(node));
  newNode->dados = novo;
  newNode->next = NULL;
  return newNode;
}

void printaLista(node *lista){
  node *atual = lista;
  while(atual->next!=NULL){
    printf("%d ",atual->dados);
    atual=atual->next;
  }
  printf("%d ",atual->dados);
  printf("\n");
}

void freeLista(node *lista){
  node *atual = lista;
  node *prox = atual->next;

  while(prox!=NULL){
    free(atual);
    atual=prox;
    prox=atual->next;
  }
  free(atual);
}

int main(){
  int novo;
  int first=1;
  node *inicio;
  node *anterior;
  node *novoNo;
  node *aux;
  while(1){
    scanf("%d",&novo);
    if(novo<0){
      break;
    }
    novoNo=criaNode(novo);
    if(first){
      inicio=novoNo;
      first = 0;
      printaLista(inicio);
    }
    else{
      aux=inicio;
      anterior=aux;
      while(aux!=NULL){
        if(aux->dados > novo){
          novoNo->next=aux;
          if(novoNo->next==inicio){
            inicio=novoNo;
          }else{
            anterior->next=novoNo;
          }
          break;
        }
        anterior=aux;
        aux=aux->next;
      }
      if(aux==NULL){
        anterior->next=novoNo;
      }
      printaLista(inicio);
    }
  }
  if(first==0){
  
  freeLista(inicio);
  }
  return 0;
}