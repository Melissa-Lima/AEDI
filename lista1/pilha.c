#include <stdio.h>
#include <stdlib.h>

typedef struct char char;

struct char{
  int dado;
  char *prox;
};

void printaLista(char *lista){
  char *atual = lista;
  while(atual!=NULL){
    printf("%d ",atual->dado);
    atual=atual->prox;
  }
  printf("\n");
}

char *criaNo(int dado){
  char *novoNo = malloc(sizeof(char));
  novoNo->prox = NULL;
  novoNo->dado = dado;
  return novoNo;
}

char *push(char *pilha, int dado){
  char *aux;
  if(pilha == NULL){
    return NULL;
  }
  aux = pilha;
  pilha = criaNo(dado);
  pilha->prox = aux;
  return pilha;
}

/* A funcao pop nao retorna um ponteiro pra char, entao temos que usar ponteiro pra ponteiro
para poder atualizar o inicio da pilha. Se nao fizermos isso, manipulamos uma COPIA do ponteiro dentro da funcao, nao 
o original
*/
int pop(char **pilha){
  char *aux;
  aux = *pilha;
  if(*pilha!=NULL){
    *pilha = aux->prox;
  }
  return aux->dado;
}

int main(){
  int i, qtde, dado;
  char **pilha;
  scanf("%d",&qtde);
  scanf("%d",&dado);
  *pilha = criaNo(dado);
  for(i=0; i<qtde-1; i++){
    scanf("%d",&dado);
    *pilha=push(*pilha,dado);
    // printaLista(pilha);
  }
  for(i=0; i<qtde; i++){
    pop(pilha);
    printaLista(*pilha);
  }
  printf("\n");
  return 0;
}