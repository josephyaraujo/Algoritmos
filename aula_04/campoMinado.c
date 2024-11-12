#include <stdio.h>
int main(){
    int campo [5][5]={
        {0,-1,-1,0,0},
        {-1,0,0,-1,0},
        {0,0,0,-1,-1},
        {0,-1,0,0,-1},
        {-1,0,-1,0,0}
    };
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (campo [i][j] == 0){
                int contador = 0;
                for (int k = i-1; k < i+1; k++){
                    for (int l = j-1; l < j+1; l++){
                        if (k<0 || k>5 || l<0 || l>5){
                            continue;
                        }
                        if (campo [k][l]== -1){
                            contador++;
                        }
                    }
                }
                campo[i][j] = contador;
            }
        }
    }
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            printf ("%d ", campo [i][j]);
        }
        printf("\n");
    }
    return 0;
}
