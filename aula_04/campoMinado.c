#include <stdio.h>
int main(){
    char campo [5][5]={
        {"o","x","x","o","o"},
        {"x","o","o","x","o"},
        {"o","o","o","x","x"},
        {"o","x","o","o","x"},
        {"x","o","x","o","o"}
    };
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            int contador = 0;
            if (campo [i][j] == "o"){
                for (int k = i-1; k <i+1; k++){
                    for (int l = j-1; l< j+1; l++){
                        if (k<0 || k>4 || l<0 || l>4){
                            continue;
                        }
                        if (campo [i][j]== "x"){
                            contador++;
                        }
                    }
                }
                campo[i][j] = contador;
            }
            for (int i = 0; i<5; i++){
                for (int j = 0; j<5; j++){
                    printf ("%c ", campo [i][j]);
                }
            }
        }
        print("\n");
    }
    return 0;
}
