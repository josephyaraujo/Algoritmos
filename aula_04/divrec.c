#include <stdio.h>
int div( int a, int b){
    int cont = 0;
    if (a<b){
        return cont;
    }
    else{
        int x = a-b; 
        return cont+= 1 + div (x,b);
    }
}
int main(){    
    int resultado , a , b;
    scanf("%d",&a);
    scanf("%d",&b);
    resultado = div(a,b);
    printf ("%d\n", resultado);
    
    return 0;
}
