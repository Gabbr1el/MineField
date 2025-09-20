#include <stdio.h>

int main(){
   int tamanho = 5, contador = 5;
   for(int i=0;i<tamanho*tamanho;i++){
      printf("0 ");
      if(i == contador-1){
         contador+= 5;
         printf("\n");
      }
      
   }
}