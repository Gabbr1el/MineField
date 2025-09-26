#include <stdio.h>
#include <stdlib.h>

int main(){
    int ganhou = 0, reveladas = 0;
    
    while(ganhou == 0){
        int tamanho, bombas, linha, coluna;
        system("cls");
        printf("Escreva o tamanho do campo (min 5x5 max 100x100): ");
        scanf("%d", &tamanho);
        system("cls");
        if(tamanho < 5 || tamanho > 100){
            printf("O tamanho e invalido!\n");
            continue;
        }

        int mat[tamanho][tamanho];
        char visivel[tamanho][tamanho];

        // inicializa os campos
        for(int i = 0; i < tamanho; i++){
            for(int j = 0; j < tamanho; j++){
                mat[i][j] = 0;
                visivel[i][j] = '0'; // '0' = escondido
            }
        }

        printf("Quantas bombas vai ter? ");
        scanf("%d", &bombas);
        

        if(bombas > tamanho * tamanho || bombas == 0){
            printf("A quantidade de bombas e invalida!\n");
            continue;
        }

        // posiciona bombas
        for(int i = 0; i < bombas ; i++){
            system("cls");
            printf("Digite a posicao da bomba %d (linha coluna): ",i+1);
            scanf("%d %d", &linha, &coluna);
            system("cls");

            // Se você prefere que o usuário digite 1..tamanho, descomente as duas linhas seguintes:
            // linha--; coluna--;

            if(linha < 0 || coluna < 0 || linha >= tamanho || coluna >= tamanho){
                printf("Posicao invalida!\n");
                i--;
                continue;
            }
            if(mat[linha][coluna] == -1){
                printf("Ja existe bomba nesse local!\n");
                i--;
            } else {
                mat[linha][coluna] = -1;
                printf("Bomba %d posicionada em (%d, %d). Pressione Enter para continar!\n", i+1, linha, coluna);
                while(getchar() != '\n'); 
                getchar();
                system("cls");                
            }
        }

        
        while(ganhou == 0){ //loop, em que o jogo realmente começa
            int seguras = tamanho * tamanho - bombas;
         
            for(int i = 0; i < tamanho; i++){ // mostra o campo que o usuario consegue ver no terminal
                for(int j = 0; j < tamanho; j++){
                    printf("%c ", visivel[i][j]);
                }
                printf("\n");
            }

            printf("Escolha uma posicao (linha coluna): "); // Efetua a jogada guardando linha e coluna como os dados da jogada
            scanf("%d %d", &linha, &coluna);
            // verifica se a posição da linha e coluna sao maior que o tamanho da matriz, e se essa mesma posiçao é menor q 0
            if (linha < 0 || coluna < 0 || linha >= tamanho || coluna >= tamanho) {
                printf("Posicao invalida! Pressione Enter para continuar.\n");
                while(getchar() != '\n');
                getchar();
                system("cls");
                continue;
            }
            if(mat[linha][coluna] == -1){ // verifica a escolha do usuario, pega o mesmo indice e aplica na matriz dentro da memoria, se for -1, perde!
                ganhou = -1; 
                system("cls");
                printf("Voce PERDEU!!!\n");
                break;
            }
            
            
            if(mat[linha][coluna] == 0){
                //verifica se a posição jogada ja foi escolhida, para confirmar a quantidade de reveladas, e verificar se o usuario não selecionou a mesma casa muitas vezes, evitando ganhar por escolher a mesma casa varias vezes.
                reveladas +=1;
                if(reveladas == seguras){ 
                    ganhou = 1;
                    system("cls");
                    printf("Voce GANHOU!!!!!!\n");
                    //Consiste em ver quantas vezes foram efetuada as tentativas, apos a validaçao da posição e apos isso verifica se a quantidade de posiçoes são a mesma quantidade da variavel "Segura".
                    }
            }
            if(mat[linha][coluna] == 0){
                mat[linha][coluna] = 1;
            }
            
      
            // conta quantas bombas tem ao redor (porém NÃO printa essa quantidade)
            int cont = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = linha + di;
                    int nj = coluna + dj;
                    if (ni >= 0 && ni < tamanho && nj >= 0 && nj < tamanho) {
                        if (mat[ni][nj] == -1) cont++;
                    }
                }
            }
    
            printf("Existem %d bomba(s) ao redor. Pressione Enter para continuar!\n", cont);
            while(getchar() != '\n'); 
                getchar(); // espera o Enter do usuário para prosseguir com o jogo.
            visivel[linha][coluna] = 'X'; // faz o local que o usuario inseriu exibir o "X".
            system("cls");
         
        } // fim loop do jogo.
        
    } // fim while principal.
    return 0;
} // fim do main.
