#include <stdio.h>
#include <math.h>

float dist(float x_1, float x_2, float y_1, float y_2){
    float d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2};
    return d;
}
float main(){
    float x_1,x_2,y_1,y_2;
    scanf("%f %f %f %f",&x_1,&x_2,&y_1,&y_2);
    printf("%f\n",dist(x_1,x_2,y_1,y_2));
    return 0;
}