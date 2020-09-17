#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
<<<<<<< HEAD
    printf("Mars Rover!\n");
    int tamanho_matriz[2] = {0 0};
    
    printf("Defina qual o tamanho da Matriz"):
    scanf("%i %i", &tamanho_matriz[1], &tamanho_matriz[2]);
    int matiz[tamanho_matriz(1) tamanho_matriz(2)] = 0;
    
    int x, y;
    char heading,posicao[5] = {1,'',2,'',' N'};
    x = posicao(1);
    y = posicao(3);
    heading = posicao(5);
    
    char comando[20] = {'M,'L','M','R'};
        for(int i=0; i<sizeof(comando); i++){
            if(heading == 'N'){
                
            }
            if(heading == 'W'){
                
            }
        }
=======
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

>>>>>>> master
    return 0;
}
