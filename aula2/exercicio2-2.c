#include <stdio.h>
#include <stdlib.h>

void printaVetor(double *vetor, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%lf ",vetor[i]);
    }
    printf("\n");
}

void ordenaVet(double *vetor, int n){
    int i,j,aux;
    for(i=0; i<n; i++){
        for(j=1; j<n; j++){
            if(vetor[i]<vetor[j]){
                aux=vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=aux;
            }
        }
    }
}

void adiciona_ordenado(double *dest, double *inicial, int n, double novo_num){
    int i,aux;
    for(i=0; i<n; i++){
        dest[i] = inicial[i];
    }
    dest[n]=novo_num;
    ordenaVet(dest,n+1);
}

int main(){
    int n,i;
    double *inicial, *dest, num, novo_num;
    printf("Digite o tamanho do vetor inicial:\n");
    scanf("%d",&n);
    inicial=malloc(n*(sizeof(double)));
    printf("Digite os %d numeros:\n",n);
    for(i=0; i<n; i++){
        scanf("%lf",&num);
        inicial[i]=num;
    }
    ordenaVet(inicial,n);
    printaVetor(inicial,n);
    printf("Digite o novo numero a ser inserido no vetor:\n");
    scanf("%lf",&novo_num);
    dest=malloc((n+1)*(sizeof(double)));
    adiciona_ordenado(dest,inicial,n,novo_num);
    printaVetor(dest,n+1);
    return 0;
}