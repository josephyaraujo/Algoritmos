#include <stdio.h>
float media(float a, float b, float c, float d){
    float media = (a+b+c+d)/4;
    return media;
}
int main(){
    float a,b,c,d;
    scanf("%f %f %f %f",&a,&b,&c,&d);
    printf("%f\n",media(a,b,c,d));
    return 0;
}