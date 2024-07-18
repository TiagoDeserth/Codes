#include <stdio.h>

int main(){
   int i;
   int N[10];
   int v;
   scanf("%d", &v);
   N[0] = v; 
   for (i = 1; i < 10; i++){
       N[i] = v*2;
        v = N[i]; 
   }
   for (i = 0; i < 10; i++){
       printf("N[%d] = %d\n", i, N[i]);
   }
}