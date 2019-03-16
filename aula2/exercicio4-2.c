#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void printaTexto(char *texto){
    int tam,i;
    tam = strlen(texto)-1;
    for(i=0; i<tam; i++){
        printf("%c",texto[i]);
    }
    printf("\n");
}

char *inverte_texto(char *texto){
    int tam, i ,cont;
    char aux;
    tam = strlen(texto)-1;
    for(i=0, cont=tam-1; i<cont; i++,cont--){
        aux = texto[i];
        texto[i] = texto[cont];
        texto[cont] = aux;
    }
}

int main(){
    char *texto;
    char textoStr[40];
    fgets(textoStr,41,stdin);
    texto = textoStr;
    inverte_texto(texto);
    printaTexto(texto);
    return 0;
}