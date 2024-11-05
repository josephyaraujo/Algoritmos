#include <stdio.h>
int div( int a, int b){
    int cont = 0;
    int x = a - b;
    if (b>x){
        return cont +=1;
    }
    else{
        return div (x,b);
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
