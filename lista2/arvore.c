#include <stdio.h>
#include <stdlib.h>

typedef struct bTree{
  int data;
  struct bTree *left;
  struct bTree *right;
}bTree;

int calculaNode(*bTree tree, int soma){
  if(tree == NULL){
    return 0;
  }
  if(tree->left == NULL && tree->right==NULL){
    return soma++;
  }
  if(tree->left!=NULL){
    soma = soma + calculaNode(tree->left,soma);
  }
  if(tree->right!=NULL){
    soma = soma + calculaNode(tree->right,soma);
  }
  return soma++;
}

int *calculaValue(bTree *tree, int soma){
  if(tree == NULL){
    return NULL;
  }
  if(tree->left!=NULL){
    soma = soma + calculaValue(bTree->sleft, bTree->data);
  }
  if(tree->right!=NULL){
    soma = soma + calculaValue(bTree->right, bTree->data);
  }
  return soma + (bTree->data);
}