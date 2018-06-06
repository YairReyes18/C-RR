#include <stdio.h>

void cm(int tam, int v[][15]){
   int aux = tam * tam;
   int i = 0, j = tam / 2, k;
    for (k = 1; k <= aux; ++k){
       v[i][j] = k;
       i--;
       j++;
        if (k % tam == 0){
           i += 2;
           --j;
       }
          else{
            if (j == tam){
               j -= tam;
           }
           else if (i < 0){
               i += tam;
           }
       }
   }
   for (i = 0; i < tam; i++){
       for (j = 0; j < tam; j++){
           printf("%2d  ", v[i][j]);
       }
       printf("\n");
   }
   printf("\n");
}



int main( ){
   int tam;
   int v[15][15];

   scanf("%d", &tam);

   if (tam % 2 == 0){
       printf("Solo funciona con numeros impares \n");
   }
      else{
       cm(tam, v);
   }
   return 0;
}
