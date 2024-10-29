#include <stdio.h>
int main (int argc, char **argv){
	int i,maior,indiceMaior, x[5];
	for (i = 0 ; i < 5 ; i++){
		scanf("%d",&x[i]);
	}
    indiceMaior=0;
    maior=x[0];
	for (i = 1 ; i < 5 ; i++){
		if(x[i]>maior){
			indiceMaior=i;
			maior=x[i];
		}
	}
    int indiceMenor, menor;
    indiceMenor=0;
    menor=x[0];
	for (i = 1 ; i < 5 ; i++){
		if(x[i]<menor){
			indiceMenor=i;
			menor=x[i];
		}
	}
	printf("O maior elemento é %d e está no índice %d\n",maior,indiceMaior);
    printf("O menor elemento é %d e está no índice %d\n",menor,indiceMenor);
	return 0;
}