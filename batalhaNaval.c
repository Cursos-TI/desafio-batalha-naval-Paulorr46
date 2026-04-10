#include <stdio.h>
 
int main() {
       int tabuleiro[10][10] = {0};
       int linha[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
       char coluna[10] = {'A', 'B','C','D', 'E', 'F', 'G', 'H', 'I', 'J'};

        tabuleiro[1][4] = 3;
        tabuleiro[1][5] = 3;
        tabuleiro[1][6] = 3;

        tabuleiro[3][3] = 3;
        tabuleiro[4][3] = 3;
        tabuleiro[5][3] = 3;


       printf("TABULEIRO BATALHA NAVAL \n");  
       printf("   ");//espaço para alinha as colunas de A - J
            for(int i = 0; i < 10; i++){//imprimi a linha de 'A' a 'J'
                printf("%c ", coluna[i]);
           }
                printf("\n");//pula uma linha
           //inicio da lógica para as linhas
            for(int i = 0; i < 10; i++){//pula linha entre colunas
                printf("%2d ", linha[i]);//%2d garante que os numeros de 1 digito de cada linha ocupem espaço igual ao 10 para alinhar tudo;
               
            for(int j = 0; j < 10; j++){
                printf("%d ", tabuleiro[i][j]);//imprimi as linhas iniciadas com 0
                }
                printf("\n");
            }
   

    return 0;
}
