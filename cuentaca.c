#include <stdio.h>

int cuentaCaracteres(char *cadena){
  int i=0;
  while (cadena[i] != '\0'){
    i++;
  }
return i;
  }


int main(){
  char cadena[] = "Yair Reyes";

  printf("Longitud Cadena: %d\n", cuentaCaracteres(cadena));

}
