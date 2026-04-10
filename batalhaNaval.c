#include <stdio.h>
 
int main() {
       int tabuleiro[10][10] = {0};
       int linha[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
       char coluna[10] = {'A', 'B','C','D', 'E', 'F', 'G', 'H', 'I', 'J'};

    //estrutura para imprimir 1 barco na horizontal
        for(int i = 3; i <= 3; i++){//move a linha
            for(int j = 2; j < 5; j++){// move a coluna
                tabuleiro[i][j] = 3;
            }
            }
    
    //estrutura para imprimir barco na vertical
            for(int i = 5; i < 8; i++){//move a linha
                for(int j = 8; j <= 8; j++){//move a coluna
                    tabuleiro[i][j] = 3;
                }
            }

            
    //inicio da lógica do jogo
       printf("TABULEIRO BATALHA NAVAL \n");
       printf("   ");//espaço para alinhar as colunas de A - J
            for(int i = 0; i < 10; i++){//imprimi as colunas de 'A' a 'J'
                printf("%c ", coluna[i]);
           }
                printf("\n");//pula uma linha
           //inicio da lógica para as linhas
            for(int i = 0; i < 10; i++){//pula linha entre colunas
                printf("%2d ", linha[i]);//%2d garante que os numeros de 1 digito de cada linha ocupem espaço igual ao 10 para alinhar tudo;
               
            for(int j = 0; j < 10; j++){
                printf("%d ", tabuleiro[i][j]);//imprimi o tabuleiro inteiro
                }
                printf("\n");
            }
   

    return 0;
}
