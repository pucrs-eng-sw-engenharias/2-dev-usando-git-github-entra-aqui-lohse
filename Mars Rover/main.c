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
    int tamanho_do_tabuleiro = 0;


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
                tamanho_do_tabuleiro = atoi(texto_da_linha);
                printf("\n----%d----\n",tamanho_do_tabuleiro);
            }
            linha++;
        }
    }

    printf("\n\nMars Rover!\n");
    char posicao[] = "1 2 N";
    printf("\n%c", *posicao);
    printf("\n%c", *(posicao + 2));
    x = *posicao;
    y = *(posicao + 2);
    heading = *(posicao + 4);

    char temp[20] = "MLMR";
    strcpy(comando, temp);
    printf("\n%c", *(comando + 0));

    int retorno;
    retorno = strcmp(heading,"N");
    printf("%i",&retorno);


        for(int i=0; i<sizeof(comando); i++){
            if(heading == 'N'){
                if(*(comando + i) == 'M') y++;
                if(*(comando + i) == 'L') heading = "W";
                if(*(comando + i) == 'R') heading = "E";
            }
            if(heading == 'W'){
                if(*(comando + i) == 'M') x--;
                if(*(comando + i) == 'L') heading = "S";
                if(*(comando + i) == 'R') heading = "N";
            }
            if(heading == 'S'){
                if(*(comando + i) == "M") y--;
                if(*(comando + i) == "L") heading = "E";
                if(*(comando + i) == "R") heading = "W";
            }
            if(heading == 'E'){
                if(*(comando + i) == "M") x++;
                if(*(comando + i) == "L") heading = "N";
                if(*(comando + i) == "R") heading = "S";
            }
            printf("\nA contagem esta em %i e o robo esta virado para ",&i);
            puts(heading);
        }

    return 0;
}
