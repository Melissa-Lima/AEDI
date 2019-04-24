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

int main(){
    return 0;
}