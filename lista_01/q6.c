#include <stdio.h>
float media(float n1, float n2){
    float mediaari = ((n1*6)+(n2*4))/10;
    return mediaari;
}
int main(){
    float n1,n2;
    printf ("Digite a primeira nota (n1) e em seguida a seguida a segunda nota (n2):");
    scanf("%f %f",&n1,&n2);
    printf("A média final é: %.1f\n",media(n1,n2));
    return 0;
}