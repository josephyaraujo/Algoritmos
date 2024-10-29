#include <stdio.h>
int main (int argc, char **argv){
  int i,cont=0;
  char s[100];
  scanf("%s",s);
  for (i = 0 ; s[i] != '\0' ; i++){
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
      cont++;
    }
  }
  printf("A string tem %d vogais\n",cont);
  return 0;
}