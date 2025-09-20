#include <stdio.h>
#include <stdlib.h>

int main(){
   int tamanho, ganhou = 0, bombas;
   
   while(ganhou == 0){
      printf("Escreva o tamanho do campo min 5x5 max 100x100: ");
      scanf("%d", &tamanho);
      if(tamanho>=5 && tamanho<=100){
         system("cls");
      }
      else{
         system("cls");
         printf("O tamanho e invalido!\n");
         continue;
      }
      int mat[tamanho][tamanho];
      printf("Quantas bombas vai ter? ");
      scanf("%d",&bombas);
      if(bombas<tamanho){
         system("cls");
         break;
      }
      else{
         system("cls");
         printf("A quantidade de bombas e invalida!\n");
         continue;
      }

   }
}