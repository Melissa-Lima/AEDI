#include <stdio.h>

double encontra_maior(double v[], int n){
    if(n==1){
        return v[0];
    }
    double maior_valor = encontra_maior(v+1,n-1);
    if(v[0] > maior_valor){
        return v[0]
    }else{
        return maior_valor;
        //return (v[0] > maior_valor) ? v[0] : maior_valor;
    }
}