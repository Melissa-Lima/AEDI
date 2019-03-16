#include <stdio.h>
#include <stdlib.h>

// int *buscaBinaria(int tam, int item, int *vet){
//   int right = 0;
//   int left = tam-1;
//   int middle = (right+left)/2;

//   while(right!=left){
//     if(*(vet+middle) == item){
//       break;
//     }else{
//       if(*(vet+middle) > item){
//         right = middle;
//       }else{
//         left = middle;
//       }
//     }
//     middle = (left+right)/2;
//   }
//   return &(*(vet+middle));
// }


int *buscaBinaria(int tam, int item, int *vet){
  int right = tam-1;
  int left = 0;
  int middle = (right+left)/2;

  while(vet[middle]!=item){
    if(vet[middle] > item){
      right = middle - 1;
    }else{
      left = middle + 1;
    }
    middle = (right + middle)/2;
    if(left > right){
    return NULL;
   }
  }
  return &(vet[middle]);
}

int main(){
  int vet[] = {1,2,4,5,6};
  int *vetPtr = vet;
  int *index;
  index = buscaBinaria(5,2,vetPtr);
  printf("%p\n",index);
  return 0;
}