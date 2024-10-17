#include <stdio.h>
#include <math.h>

int dist(int x_1, int x_2, int y_1, int y_2){
    int d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2};
    return d;
}
int main(){
    int x_1,x_2,y_1,y_2;
    scanf("%d %d %d %d",&x_1,&x_2,&y_1,&y_2);
    printf("%d\n",dist(x_1,x_2,y_1,y_2));
    return 0;
}