#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int linha, x=0, y=0;
char new_heading[2],comando_temp[2];
int robo = 0, x_robo[20],y_robo[20],heading_robo[20];

void localizacao_inicial(char *texto_da_linha){
    x = (int)*texto_da_linha - 48;
    y = (int)*(texto_da_linha + 2) - 48;
    new_heading[0] = texto_da_linha[4];
    new_heading[1] = '\0';
    robo++;
    printf("Um novo Robo foi iniciado %i ele esta olhando para %s e esta na posicao %i,%i\n",robo, new_heading,x,y);
    //printf("\nCriacao do new_heading %s\n",new_heading);

}

void caminho_do_robo(char comando[20], int tamanho_comando,char comando_temp[2]){
    for(int i = 0; i<tamanho_comando; i++){
        printf("Comando(%i) = %c\n",i, *(comando + i));
        comando_temp[0] = comando[i];
        comando_temp[1] = '\0';
        //printf("\n--Esse e o comando_temp: %s--\n",comando_temp);
        //printf("\nTESTE do new_heading %s\n",new_heading);
        if(strcmp(new_heading,"N") == 0){
            //printf("\nEntrei no primeiro if.\n");
            if(strcmp(comando_temp,"M") == 0) y++;
            if(strcmp(comando_temp,"L") == 0) strcpy(new_heading,"W");
            if(strcmp(comando_temp,"R") == 0) strcpy(new_heading,"E");
        }else
        if(strcmp(new_heading,"W") == 0){
            //printf("\nEntrei no segundo if.\n");
            if(strcmp(comando_temp,"M") == 0) x--;
            if(strcmp(comando_temp,"L") == 0) strcpy(new_heading,"S");
            if(strcmp(comando_temp,"R") == 0) strcpy(new_heading,"N");
        } else
        if(strcmp(new_heading,"S") == 0){
            //printf("\nEntrei no terceiro if.\n");
            if(strcmp(comando_temp,"M") == 0) y--;
            if(strcmp(comando_temp,"L") == 0) strcpy(new_heading,"E");
            if(strcmp(comando_temp,"R") == 0) strcpy(new_heading,"W");
        } else
        if(strcmp(new_heading,"E") == 0){
            //printf("\nEntrei no quarto if.\n");
            if(strcmp(comando_temp,"M") == 0) x++;
            if(strcmp(comando_temp,"L") == 0) strcpy(new_heading,"N");
            if(strcmp(comando_temp,"R") == 0) strcpy(new_heading,"S");
        }
        printf("O Robo esta olhando para %s e esta na posicao %i,%i\n",new_heading,x,y);
    }


    x_robo[robo] = x;
    y_robo[robo] = y;
    heading_robo[robo] = new_heading;

}

int main()
{
    FILE *arquivo_txt;
    char *resultado, texto_da_linha[50];
    char comando[20];
    int tamanho_do_tabuleiro_x = 0, tamanho_do_tabuleiro_y = 0, area = 0, i = 0, tamanho_comando= 0, contador_iniciar_robo = 1, contador_comandos_robo = -1;



    arquivo_txt = fopen("rover.txt","rt");
     if(arquivo_txt == NULL)
    {
        printf("Erro na leitura");
    }
    linha = 0;
    printf("Mars Rover!\n\n");
    while(!feof(arquivo_txt))
    {
        resultado = fgets(texto_da_linha,100,arquivo_txt);
        linha++;
        contador_iniciar_robo++;
        contador_comandos_robo++;
        if(resultado)
        {
            printf("linha %d: %s",linha,texto_da_linha);
            if(linha == 1){
                tamanho_do_tabuleiro_x = (int)*texto_da_linha - 48;
                tamanho_do_tabuleiro_y = (int)*(texto_da_linha+2) - 48;
                //printf("\nA area do tabuleiro e de: %d m^2\n",area);
            }

            if(contador_iniciar_robo == 4){
                /*
                x = (int)*texto_da_linha - 48;
                y = (int)*(texto_da_linha + 2) - 48;
                new_heading[0] = texto_da_linha[4];
                new_heading[1] = '\0';
                printf("O Robo esta olhando para %s e esta na posicao %i,%i\n",new_heading,x,y);
                */
                //printf("\nCriacao do new_heading %s\n",new_heading);
                localizacao_inicial(texto_da_linha);
                contador_iniciar_robo = 0;
            }
            if(contador_comandos_robo == 4){
                strcpy(comando, texto_da_linha);
                tamanho_comando = strlen(comando) - 1;
                //printf("%s",new_heading);
                caminho_do_robo(comando, tamanho_comando, comando_temp);
                contador_comandos_robo = 0;
            }
        }
    }
    printf("\n\nProcesso Finalizado!\nQuantidade total de robos: %i\nx   y   h",robo);
    heading_robo[robo+1] = '\0';
    //for(int i = 0; i<tamanho_comando; i++){
    for(int j = 0; j<=robo; j++){

        printf("\n%i   %i   %s",x_robo[j],y_robo[j],heading_robo[j]);

    }
    return 0;
}

