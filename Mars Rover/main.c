#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    FILE *arquivo_txt;
    char *resultado, texto_da_linha[50], comando, heading;
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

    //return 0;

    /*

    printf("Mars Rover!\n");
    int tamanho_matriz[2] = {0,0};

    printf("Defina qual o tamanho da Matriz");
    scanf("%i %i", &tamanho_matriz[1], &tamanho_matriz[2]);
    int matiz[tamanho_matriz(1),tamanho_matriz(2)] = 0;
    */
    printf("\nMars Rover!\n");
    char posicao[] = "1 2 N";
    printf("\n%c", *posicao);
    printf("\n%c", *(posicao + 2));
    x = *posicao;
    y = *(posicao + 2);
    heading = *(posicao + 4);

    comando = "MLMR";
        for(int i=0; i<sizeof(comando); i++){
            if(heading == 'N'){
                if(comando*(i))
            }
            if(heading == 'W'){

            }
        }



    return 0;

}
