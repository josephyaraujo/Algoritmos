#include <stdio.h>
int mult(int a, int b){
    int m = a*b;
    return m;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",mult(a,b));
    return 0;
}