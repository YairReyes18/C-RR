#include <stdio.h>
#include <stdlib.h>


  int main(){

    int *x = (int*)malloc(sizeof(int));
    *x = 10;
    printf("%d\n", *x);
    free(x);
    printf("%d\n", *x);



    return 0;
  }
