#include <stdio.h>
 
int main() {
       int tabuleiro[10][10] = {0};
       int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
       char linha[10] = {'A', 'B','C','D', 'E', 'F', 'G', 'H', 'I', 'J'};


       printf("TABULEIRO BATALHA NAVAL \n");   
        for(int j = 0; j < 1; j++){//pula uma linha entre a "linha"
            for(int i = 0; i < 10; i++){//imprimi a linha de 'A' a 'J'
                printf("%c ", linha[i]);
           }
                printf("\n");//pula uma linha
           }


            for(int i = 0; i < 10; i++){//pula linha entre colunas
                printf("%d ", coluna[i]);
               
            for(int j = 0; j < 10; j++){
                printf("%d ", tabuleiro[i][j]);//imprimi as colunas
                }
                printf("\n");
            }
   

    return 0;
}
