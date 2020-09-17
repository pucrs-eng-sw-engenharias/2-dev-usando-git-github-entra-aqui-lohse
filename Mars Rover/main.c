#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    FILE *arquivo_txt;
    char *resultado, texto_da_linha[50], comando[20], heading;
    int linha, m=0, n=0, x=0, y=0;


    arquivo_txt = fopen("rover.txt","rt");
     if(arquivo_txt == NULL)
    {
        printf("Erro na leitura");
    }
    linha=1;
    printf("Mars Rover!\n\n");
    while(!feof(arquivo_txt))
    {
        resultado = fgets(texto_da_linha,100,arquivo_txt);
        if(resultado)
        {
            printf("linha %d: %s",linha,texto_da_linha);
            linha++;
        }
    }

    return 0;
}
