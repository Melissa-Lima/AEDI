#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int potencia2(int x){
    int n = log2(x)/log2(2);
    return pow(2,n) == x;
}

int main(){
    int n,i,num;
    int *vetor;
    int qtde;

    scanf("%d",&n);
    vetor=malloc(n*(sizeof(int)));

    for(i=0; i<n; i++){
        scanf("%d",&num);
        vetor[i]=num;
    }

    for(i=0; i<n; i++){
        if(potencia2(vetor[i])){
            qtde++;
        }
    }

    printf("%d",qtde);
    return 0;
}

//>>n desloca n bits pra direita
//<<n desloca n bits pra esquerda
