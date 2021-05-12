
#include <stdio.h>
#include <string.h>

#include "funcoes_auxiliar.h"


int lerInteiro(int min, int max){

int numero, controlo;

do{
    controlo = scanf("%d", &numero);
    limpaBufferStdin();

} while (numero<min || numero>max || controlo == 0);

return numero;
}

float lerFloat(float min, float max){

int controlo;
float numero;

do{
    controlo = scanf("%f", &numero);
    limpaBufferStdin();

} while (numero<min || numero>max || controlo == 0);

return numero;
}

void lerString(char vetor[100], int max){
int tamanhoString;

    do{
        fgets(vetor, max, stdin);
        tamanhoString = strlen(vetor);
    } while (tamanhoString == 1);

    if (vetor[tamanhoString-1] != '\n'){
        limpaBufferStdin();
    }else{
        vetor[tamanhoString-1] ='\0';
        }
}




void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
