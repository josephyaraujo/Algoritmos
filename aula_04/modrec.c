#include <stdio.h>
int mod (int a, int b){
    int x = a - b;
    if (b>x){
        return x;
    }
    else{
        return mod (x,b);
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

