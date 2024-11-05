#include <stdio.h>
int mod( int a, int b){
    int sub = a-b;
    if (b>sub){
        return sub;
    }
    else{
        sub= sub-b; 
        return sub;
    }
}
int main(){    
    int resultado , a , b;
    scanf("%d",&a);
    scanf("%d",&b);
    resultado = mod(a,b);
    printf ("%d\n", resultado);
    
    return 0;
}

