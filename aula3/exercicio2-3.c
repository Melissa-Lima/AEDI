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
  int novo=0;
  int qtde=0;
  node *inicio;
  node *atual;
  node *novoNo;
  while(1){
    scanf("%d",&novo);
    if(novo<0){
        break;
    }
    if(qtde==0){
      novoNo=criaNode(novo);
      atual=novoNo;
      inicio=atual;
    }else{
      novoNo=criaNode(novo);
      atual->next=novoNo;
      atual=novoNo;
    }
    qtde++;
}
  printaLista(inicio);
  freeLista(inicio);
  return 0;
}