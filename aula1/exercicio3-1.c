#include <stdio.h>
#include <stdlib.h>

void printa(int tam, int *vetor){
    for(int i=0; i<tam; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}

int main(){

    int n,i,num,*vetor,novo;

    scanf("%d",&n);
    vetor=malloc(n*sizeof(int));

    for(i=0; i<n; i++){
        scanf("%d",&num);
        vetor[i]=num;
    }

    printa(n,vetor);

    scanf("%d",&novo);

    for(i=n-1; i>0; i--){
        vetor[i]=vetor[i-1];
    }
    vetor[0]=novo;

    printa(n,vetor);
    free(vetor);
    return 0;
}
