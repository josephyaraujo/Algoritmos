#include <stdio.h>
int media(int a, int b, int c, int d){
    int media = (a+b+c+d)/4;
    return media;
}
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d\n",media(a,b,c,d));
    return 0;
}