#include <stdio.h>
#include <stdlib.h>

// typedef struct pilha pilha;

// struct node{
//   char carac;
//   node pilha *prox;
// };

// node *empilha(node *no){
//   node *aux = pilha;
//   while(aux->prox!=NULL){
//     aux = aux->prox;
//   }
//   aux->prox = no;
//   return pilha;
// }

// node *desempilha(node *pilha){
//   node *aux = pilh
//   while(aux->prox!=NULL){
//     aux = aux->prox;
//   }
  
// }

int tamEspressao(char *string){
  int tam = 0;
  int i = 0;
  while(*(string+i)!='\n'){
    tam++;
    i++;
  }
  printf("%d\n",tam);
  return tam;
}

char *empilha(char *pilha, char carac, int **topoPtrPtr){
  *(pilha+(**topoPtrPtr)) = carac;
  (**topoPtrPtr)++;
  return pilha;
}

char desempilha(char **pilha, int **topo){
  char obj = **(pilha+(**topo));
  **(pilha+(**topo)) = ' ';
  (**topo)--;
  return obj;
}

int verifica(char carac, char *pilha, int *topoPtr){
  printf("carac = %c, pilha = %c\n",carac,*(pilha+(*topoPtr)));
  if(*(pilha+(*topoPtr))=='('){
    if(carac == ')'){
      return 1;
    }
  }
  if(*(pilha+(*topoPtr))=='['){
    if(carac == ']'){
      return 1;
    }
  }
  if(*(pilha+(*topoPtr))=='{'){
    if(carac == '}'){
      return 1;
    }
  }
  return 0;
}

int main(){
  char *expressao = malloc(12*sizeof(char)); 
  char **pilha;
  int *topoPtr, **topoPtrPtr, tam, i, topo = -1;;
  topoPtr = &topo;
  topoPtrPtr = &topoPtr;

  fgets(expressao,12,stdin);
  tam = tamEspressao(expressao);

  *pilha = expressao;
  for(i=0; i<tam; i++){
    if(expressao[i]=='(' || expressao[i]=='{' || expressao[i]=='['){
      *pilha = empilha(*pilha, expressao[i], topoPtrPtr);
      printf("empilhou:%c\n",**(pilha+(**topoPtrPtr)));
    }
  }
  for(i=0;i<tam;i++){
    if(expressao[i]==')' || expressao[i]=='}' || expressao[i]==']'){ 
      if(!verifica(expressao[i], *pilha, topoPtr)){
        printf("pilha = %c, item = %c\n",**(pilha+i),expressao[i]);
        printf("EXPRESSAO INVALIDA\n");
        break;
      }
      desempilha(pilha,topoPtrPtr);
    }
  }
  return 0;
}