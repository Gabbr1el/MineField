#include <stdio.h>
#include <stdlib.h>

int main(){
   int ganhou = 0;
   while(ganhou == 0){
      int tamanho, bombas, linha, coluna;
      //variaveis declaradas dentro do while pois quando o codigo der um continue, ele resetar tudo que foi feito.
      system("cls");
      printf("Escreva o tamanho do campo min 5x5 max 100x100: ");
      scanf("%d", &tamanho);
      if(tamanho<5 || tamanho>100){
         system("cls");
         printf("O tamanho e invalido!\n");
         continue;
      }
      else{
         system("cls");
      }
      //acima verifica se o tamanho da matriz é menor que 5 ou maior que 100, caso estiver correto ele reinicia o codigo.

      int mat[tamanho][tamanho];
      for(int i = 0; i < tamanho; i++){
         for(int j = 0; j < tamanho; j++){
         mat[i][j] = 0;  
         }
      }
      // O For acima define todas as posições como vazias
      printf("Quantas bombas vai ter? ");
      scanf("%d",&bombas);

      if(bombas> tamanho*tamanho || bombas == 0){
         system("cls");
         printf("A quantidade de bombas e invalida!\n");
         continue;
      }
      //este if verifica o tamanho total da matriz, para não ter mais bombas que espaços vazios e se não tem bombas.
      system("cls");
      for(int i = 0; i < bombas ; i++){
         printf("Digite a posicao das bombas: ");
         scanf("%d %d", &linha, &coluna);
      
         if(linha < 0 || coluna < 0 || linha>=tamanho || coluna>=tamanho){
            system("cls");
            printf("A posicao e ivalida!\n");
            i--;
         }
         else if(mat[linha][coluna] == -1){
            system("cls");
            printf("ja existe uma bomba nesse local!\n");
            i--;
            
         }
         else{
            mat[linha][coluna] = -1;
            system("cls");
            printf("Bomba %d posicionada em (%d, %d)\n", i+1, linha, coluna);
         }
         // acima verifica quantas bombas o campo minado vai ter, caso as bombas ultrapassem a variável "tamanho", ele reinicia o código.
      }  
         printf("\nCampo:\n");
         char visivel[tamanho][tamanho];
         for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
               visivel[i][j] = '0'; 
            }
         }
         for(int i = 0; i < tamanho;i++){
            for(int j = 0; j < tamanho; j++){
            printf("%c ", visivel[i][j]);            
            }
         printf("\n");
         } 
      while(ganhou == 0){   
         printf("Escolha uma posicao: ");
         scanf("%d %d", &linha, &coluna);
         if (linha < 0 || coluna < 0 || linha >= tamanho || coluna >= tamanho) {
            printf("posicao invalida");
         }
         system("cls");
         for(int i = 0; i < tamanho;i++){
            for(int j = 0; j < tamanho; j++){
               visivel[linha][coluna] = ' ';               
            }
         }
         for(int i = 0; i < tamanho; i++){
            for(int j = 0; j < tamanho; j++){
               printf("%c ", visivel[i][j]);
            }
         printf("\n");
         }
         if(mat[linha][coluna] == 0){
            mat[linha][coluna] = 1;
         }
         else if(mat[linha][coluna] == -1){
            ganhou = -1;
         }
         if(ganhou == 1){
            system("cls");
            printf("Voce GANHOU!!!");
         }
         else if(ganhou == -1){
            system("cls");
            printf("Voce PERDEU!!!");
         }
      }
   }
}