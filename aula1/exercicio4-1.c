#include <stdio.h>
#include <stdlib.h>

struct celuli{
    struct celuli *prox;
    int num;
};
typedef struct celuli celuli;

void printaCel(int tam, celuli *vetor){
    for(int i=0; i<tam; i++){
        printf("%d ",vetor->num);
        vetor=vetor->prox;
    }
    printf("\n");
}

celuli *criaCeluli(){
    celuli *novoCel = malloc(sizeof(celuli));
    return novoCel;
}

int main(){
    int n, i, valor;
    scanf("%d",&n);
    celuli *inicio = criaCeluli();
    celuli *aux = inicio;

    for(i=0; i<n; i++){
        scanf("%d",&valor);
        aux->num = valor;
        if(i==n-1){
            aux->prox = NULL;
            break;
        }
        aux->prox = criaCeluli();
        aux=aux->prox;
    }

    printaCel(n,inicio);

    aux=inicio;
    inicio=inicio->prox;
    free(aux);
    n=n-1;
    printaCel(n,inicio);

    aux = inicio->prox;
    free(inicio);
    for(i=1; i<n; i++){
        celuli *aux2 = aux->prox;
        free(aux);
        aux=aux2;
    }

    return 0;
}