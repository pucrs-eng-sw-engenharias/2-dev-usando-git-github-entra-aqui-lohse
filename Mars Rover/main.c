#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
    FILE *arquivo_txt;
    char *resultado, texto_da_linha[50], heading;
    char comando[20];
    int linha, m=0, n=0, x=0, y=0;
    int tamanho_do_tabuleiro_x = 0, tamanho_do_tabuleiro_y = 0, area = 0, i = 0, tamanho_comando= 0;

    arquivo_txt = fopen("rover.txt","rt");
     if(arquivo_txt == NULL)
    {
        printf("Erro na leitura");
    }
    linha = 1;
    printf("Mars Rover!\n\n");
    while(!feof(arquivo_txt))
    {
        resultado = fgets(texto_da_linha,100,arquivo_txt);
        if(resultado)
        {
            printf("linha %d: %s",linha,texto_da_linha);
            if(linha == 1){
                tamanho_do_tabuleiro_x = (int)*texto_da_linha - 48;
                tamanho_do_tabuleiro_y = (int)*(texto_da_linha+2) - 48;
                area = tamanho_do_tabuleiro_x*tamanho_do_tabuleiro_y;
                printf("\nA area do tabuleiro e de: %d m^2\n",area);
            }
            linha++;
             if(linha == 4){
                x = (int)*texto_da_linha - 48;
                y = (int)*(texto_da_linha + 2) - 48;
                heading = *(texto_da_linha + 4);
                // printf("\n%c\n",heading);
            }
              if(linha == 6){
                strcpy(comando, texto_da_linha);
                tamanho_comando = strlen(comando) - 1;
                for(i = 0; i<tamanho_comando; i++){
                    printf("\nComando(%i) = %c\n",i, *(comando + i));
                /*
                    if(strcmp(heading,"N") == 0){
                        if(strcmp(*(comando + i),"M") == 0) y++;
                        if(strcmp(*(comando + i),"L") == 0) heading = "W";
                        if(strcmp(*(comando + i),"R") == 0) heading = "E";
                    }
                    if(heading == "W"){
                        if(strcmp(*(comando + i),"M") == 0) x--;
                        if(strcmp(*(comando + i),"L") == 0) heading = "S";
                        if(strcmp(*(comando + i),"R") == 0) heading = "N";
                    }
                    if(heading == "S"){
                        if(*(comando + i) == "M") y--;
                        if(*(comando + i) == "L") heading = "E";
                        if(*(comando + i) == "R") heading = "W";
                    }
                    if(heading == "E"){
                        if(*(comando + i) == "M") x++;
                        if(*(comando + i) == "L") heading = "N";
                        if(*(comando + i) == "R") heading = "S";
                    }
                    else printf("\nNao entrou em ninguem\n");
                */
                }
            }
        }
    }

    return 0;
}
