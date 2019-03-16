#include <stdio.h>
#include <stdlib.h>

typedef struct lista lista;

struct lista{
  int dado;
  lista *prox;
};

lista criaNode(int dado){
  lista no;
  no->prox = NULL;
  no->dado = dado;
  return lista;
}

// a
lista *insereNode(lista *lista, lista *no){
  lista aux = lista;
  while(aux->prox!=NULL){
    aux = aux->prox;
  }
  aux->prox = no;
  return lista;
}

//b
lista *concatena(lista *lista1, lista *lista2){
  insereNode(lista1,lista2);
  return lista1;
}

//c
lista *inverteLista(lista *lista){
  lista atual = lista->prox;
  lista prev = lista;
  lista next = atual->prox;
  lista->prox = NULL;
  while(atual!=NULL){
    atual->prox = prev;
    prev = atual;
    atual = next;
    next = atual->prox;
  }
  return lista;
}

//d - problema com lista de apenas 1 elemento, pois ele vai retornar um ponteiro weird após dar o free...
lista removeUltimoNo(lista *lista){
  lista anterior = lista;
  lista atual = anterior
  // lista guia = atual;
  while(atual->prox!=NULL){
    anterior = atual;
    atual = atual->next;
    // guia = guia->next;
  }
  anterior->prox = NULL;
  free(atual);
  return lista;
}

//e
lista removeEnesimo(lista *lista, int n){
  int i;
  lista atual = lista;
  lista prox = lista->prox;
  lista anterior = lista;
  for(i=0; i<n; i++){
    anterior = atual;
    atual = prox;
    prox = atual->prox;
  }
  free(atual);
  anterior->prox = prox;
  return lista;
}

//f
lista removeLista(lista *lista){
  aux = lista->prox;
  while(aux!=NULL){
    free(lista);
    lista = aux;
    aux = lista->prox;
  }
  free(lista);
  return NULL;
}

//g
// lista concatenaOrdem(lista *lista1, lista *lista2){
//   lista first = lista1;
//   lista second = lista2;
//   lista aux1, aux2;

//   while(first!=NULL && second!=NULL){
//     if(first->dado < second->dado){
//       aux1 = first->prox;
//       first->prox = 
//       aux2 = second;
//       second = second->prox;

//     }else if(first->dado > second->dado){

//     }
//   }
// }

//h

//i

//j

//k
int somaLista(lista *lista){
  int soma = 0;
  lista aux = lista;
  while(aux!=NULL){
    soma = soma + aux->dado;
    aux = aux->prox;
  }
  return soma;
}
//l
lista *desloca(lista *no, int n){
  int i;
  lista aux = no;
  for(i=0; i<n; i++){
    aux = aux->prox;
  }
  no->prox = aux;
  return no;
}

//m
lista *removeDup(lista *lista){
  // lista comp = lista
  // lista prox = comp->prox;
  // lista aux;
  // while(prox!=NULL){
  //   if(comp->dado == prox->dado){
  //     aux = prox->prox;
  //     free(prox);
  //     comp->prox = aux;
  //     prox = aux->prox;
  //   }
  // }

  node *prox;
//todos os 3 ponteiros abaixo começa
//apontando pro primeiro elemento
node *comp = lista;
node *ant = comp;
node *del = ant;
// comp = elemento principal que vamos comparar com o resto
//del = o que vamos comparar com o elemento principal
//ant = anterior ao del, pra guardar por quem ele esta sendo apontado
//prox = proximo elemento do elemento que vai ser deletado (del),
//pois não podemos perder pra quem ele apontava
  while(comp->prox!=NULL){
    del = del->prox;
    while(del!=NULL){
      if(comp->dado == del->dado){
        prox = del->prox;
        free(del);
        ant->prox = prox;
      }
      ant = del;
      del = del->prox;
    }
    comp = comp->prox;
  }
}
//n

//o




