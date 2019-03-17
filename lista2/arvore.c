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

int calculaNodeSimple(bTree *tree){
  if(tree==NULL){
    return 0;
  }
  return (1 + calculaNodeSimple(tree->right) + calculaNodeSimple(tree->left));
}

int *calculaValue(bTree *tree, int soma){
  if(tree == NULL){
    return NULL;
  }
  if(tree->left!=NULL){
    soma = soma + calculaValue(tree->left, tree->data);
  }
  if(tree->right!=NULL){
    soma = soma + calculaValue(tree->right, tree->data);
  }
  return &(soma + (tree->data));
}

int calculaValueSimple(bTree *tree){
  if(tree==NULL){
    return 0;
  }
  return(tree->data + tree->data + calculaNodeSimple(tree->left) + calculaNodeSimple(tree->right));
}

int *alturaTree(bTree *tree, int altura){
  int left = 0;
  int right = 0;
  if(tree==NULL){
    return NULL;
  }
  if(tree->left!=NULL){
    left = left + alturaTree(tree->left, left) + 1;
  }
  if(tree->right!=NULL){
    right = right + alturaTree(tree->right, right) + 1;
  }
  altura = right>left ? right:left;
  return &altura;
}

int *arvoreCheia(bTree *tree){
  int retorno;
  if(tree==NULL){
    return NULL;
  }
  if(tree->left!=NULL || tree->right!=NULL){
    if(!(tree->left && tree->right)){
      retorno = 0;
    }
    else{
      retorno = 1;
    }
    retorno = arvoreCheia(tree->left);
    if(retorno){
      retorno = arvoreCheia(tree->right);
    }
  }
  return &retorno;
}

int *qtdeFolhas(bTree *tree){
  int soma = 0;
  if(tree==NULL){
    return &soma;
  }
  if(!(tree->left || tree->right)){
    soma++;
  }
  return &(soma + qtdeFolhas(tree->left) + qtdeFolhas(tree->right));
}

int qtdeInternos(bTree *tree){
  int soma = 0;
  int *somaPtr = &soma;
  if(tree==NULL){
    return NULL;
  }
  if(tree->left || tree->right){
    soma++;
  }
  soma = soma + qtdeInternos(tree->left) + qtdeInternos(tree->right);
  return somaPtr;
}

int arvoreBusca(bTree *tree){
  int guide = 0;
  if(tree==NULL){
    return 0;
  }

  if(tree->left){
    if ((tree->left).data < tree->data){
      guide = 1;
    }
  }
  else if(tree->right){
    if ((tree->right).data > tree->data){
      guide = 1;
    }
    guide = guide * arvoreBusca(tree->left) * arvoreBusca(tree->right);
  }

  else{
    guide = 1;
  }

  return guide;
}

// void printaNiveis(bTree *tree){
  
//   // printaNiveis((tree->left).left);
//   // printaNiveis((tree->right).right);
// }

int main(){
  return 0;
}