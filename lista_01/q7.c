#include <stdio.h>
int invert(int a){
    int c = a/100;
    int x = a%100;
    int d = x/10;
    int y = x%10;
    int u = y/1;
    return printf ("%d %d %d",&c,&d,&u);
}
int main(){
    int a;
    scanf("%d",&a);
    printf("%d\n",invert(a));
    return 0;
}