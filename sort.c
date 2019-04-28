#include <stdio.h>
#include <stdlib.h>

typedef struct registro {
    int key;
    int data;
} registro;

// INSERTION

void insert(registro *base, int k){
    registro x = base[k];
    k--;

    while(k>=0 && base[k].key > x.key){
        base[k+1] = base[k];
        k--;
    }
    base[k+1] = x;
}

void insertionSort(registro *base, int n){
    int k = 1;
    while (k < n){
        insert(base,k);
        k++;
    }
}

// BUBBLE

void swap(registro *dado1, registro *dado2){
    registro *aux = dado1;
    dado1 = dado2;
    dado2 = aux;
}

char bubbleUp(registro *base, int n){
    char changed = 0;

    for (int i=0; i<n-1; i++){
        if(base[i].key > base[i+1].key){
            swap(base[i], base[i+1]);
            changed = 1;
        }
    }
    return changed;
}

void bubbleSort(registro *base, int n){
    while(bubbleUp(base,n));
}

// QUICK

void partition(registro *base, int n){
  int pivot = base[0];
  int i, j  = 1;
  for(j = 1; j<n; j++){
    if(base[j].data < pivot){
      swap(base[i],base[j]);
      i++;
    }
  }
  swap(registro[0],registro[i-1]);
  return i-1;
}

void partitionHalf(registro *base, int n){
  int pivot = base[n/2];
  int i, j  = 0;
  for(j = 0; j>=0; j--){
    if(j==n/2){
      j++;
    }
    if(i==n/2){
      i++
    }
    if(base[j].data < pivot){
      swap(base[i],base[j]);
      i++;
    }
  }
  swap(registro[p],registro[i-1]);
  return i-1;
}

void quickSort(registro *base, int n){
  int p;
  if(n>0){
    p = partition(base,n);
    quickSort(base,p);
    quickSort(base[p+1],n-p-1);
  }
}

int main(){
    return 0;
}
