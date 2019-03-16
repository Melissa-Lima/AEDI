#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[100];
    int ra;
    double nota;
} aluno;

double mediaNota(aluno *alunos, int n){
    int i;
    double media=0;
    
    for(i=0; i<n; i++){
        media=media+alunos[i].nota; 
    }
    
    return media/n;
}

int maiorNota(aluno *alunos, int n){
    int i;
    aluno maior = alunos[0];

    for(i=0; i<n; i++){
        if(alunos[i].nota>maior.nota){
        maior=alunos[i];
        }
    }
    return maior.ra;
} 

int main(){
    int n,i;
    aluno *alunos;

    scanf("%d",&n);
    alunos = malloc(n*sizeof(aluno));
    
    for(i=0; i<n; i++){
        scanf("%s",alunos[i].nome);
        scanf("%d",&alunos[i].ra);
        scanf("%lf",&alunos[i].nota);
    }
    printf("O aluno com maior nota eh: %d\n",maiorNota(alunos,n));
    printf("A media das notas eh: %lf\n",mediaNota(alunos,n));
    free(alunos);
    return 0;
}