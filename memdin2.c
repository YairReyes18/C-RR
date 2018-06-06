#include <stdio.h>
#include <stdlib.h>

struct x {
  int dato;
};

typedef struct X X;

int main(){
  X *apX = (X*)malloc(sizeof(X));
  apX->dato = 31; //opn

  printf("%d\n", apX->dato);

    return 0;
  }
