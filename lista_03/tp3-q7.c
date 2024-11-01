#include <stdio.h>
int main(){
    char string [100];
    int contador = 0;

    printf ("Digite uma string até 100 caracteres:\n");
    scanf ("%s", string);

    while (string[contador]!= '\0'){
        contador++;
    }
    
    printf ("A sting digitada tem %d caracteres.\n", contador);
    return 0;
}