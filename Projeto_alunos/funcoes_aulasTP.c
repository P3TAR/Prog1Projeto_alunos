
#include <stdio.h>
#include <ctype.h>
#include "constantes.h"
#include "funcoes_auxiliar.h"
#include "funcoes_aulas.h"



//listagem de todos os dados

void listagemTP(AulaTP vTP[MAXFUNC], int n){
int i;

if (n==0){
    printf("\n N�o existem dados!!");
}
else{

    for (i=0; i<n; i++) {

        escreveDadosTP(vTP[i]);
    }
}

}



// escreve os dados

void escreveDadosTP(AulaTP teorico){
    int estado;
    int gravacao;




printf("\n codigo da UC:%s",teorico.codigoUC);

printf("\n Codigo da aula:%s", teorico.codigo_aula_TP);

printf("\nProfessor:%s",teorico.profaula_TP);

gravacao = teorico.gravacao_TP;
switch(gravacao){
case 1:
    printf("\n Gravacao de aula: sim");
    break;

case 2:
    printf("\n Gravacao de aula:nao");
    break;
}


printf("\nData da aula:%d/%d/%d",teorico.Horario_TP.dia,teorico.Horario_TP.mes,teorico.Horario_TP.ano);

printf("\nRealizado das:%.2f ate %.2f",teorico.Horario_TP.inicio,teorico.Horario_TP.fim);

estado = teorico.estado;
switch (estado){

case 1:
    printf("\nAula agendada\n");
    break;

case 2:
    printf("\nAula a decorrer\n");
    break;

case 3:
    printf("\nAula finalizada\n");
    break;
}


}



//l� todos os dados que t�m de ser inseridos

AulaTP leDadosTP(){
AulaTP aula;
char controlo;
float controlo2;
float horafinal;
int estado,tempo;

    estado = 1;

        aula.estado = estado;
            printf("Codigo da UC: ");
            lerString(aula.codigoUC,50);

            printf("Codigo da aula: ");
            lerString(aula.codigo_aula_TP,50);

            printf("Professor: ");
            lerString(aula.profaula_TP,100);

            printf("Grava��o de aula: 1 - sim 2 - nao");
            aula.gravacao_TP = lerInteiro(1,2);

            printf("Insira o turno (1 - D ou 2 - PL)");
            aula.turno = lerInteiro(1,2);

              printf("Quanto tempo vai durar a aula em minutos?");
            tempo = lerInteiro(1,500);

            controlo = aula.turno;

switch(controlo){

case 1:
    do{
    printf("Hora de inicio (8h - 18h): ");
        controlo2 = lerFloat(8,18);
       controlo2 = controlo2 * 60;
        horafinal = controlo2 + tempo;
    }while(horafinal>1080);
        aula.Horario_TP.inicio = controlo2;
        aula.Horario_TP.fim = horafinal;
    break;

case 2:
    do{
        printf("Hora de inicio (18h - 24h): ");
            controlo2 = lerFloat(18,24);
       controlo2 = controlo2 * 60;
        horafinal = controlo2 + tempo;
    }while(horafinal >1440);
        aula.Horario_TP.inicio = controlo2;
        aula.Horario_TP.fim = horafinal;
    break;

default:
    printf("Escolha incorreta!!");

}


printf("Dia da aula: ");
    aula.Horario_TP.dia = lerInteiro(1,31);
printf("M�s: ");
    aula.Horario_TP.mes = lerInteiro(1,12);
printf("Ano: ");
    aula.Horario_TP.ano = lerInteiro(2021,2025);
return aula;
}





//procura codigo de aula

int procuraTP (AulaTP vTP[], int n, char codigoAula[]){
int i, pos;
pos = -1;
for (i=0;i<n;i++){
    if (strcmp(vTP[i].codigo_aula_TP,codigoAula)==0){
        pos = i;
        i=n;
    }

}
return pos;
}






//acrescenta os dados de aula no vetor

int acrescentaNoVetorTP(TipoUC uc[MAXFUNC], AulaTP vTP[MAXFUNC], AulaT vT[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL, int *nAgenda, int *nGrav){
AulaTP dados;
TipoUC codUC;
int pos,pos2,pos3;
int elem;

elem = 0;
dados=leDadosTP();
pos=procuraAula(vT,vTP,vPL,nT,nTP,nPL,dados.codigo_aula_TP);
pos2=procuraUC(uc,40,dados.codigoUC);
pos3 = procuraData(vT, vTP, vPL, nT, nTP,nPL,dados.Horario_TP.dia,dados.Horario_TP.mes,dados.Horario_TP.ano,dados.Horario_TP.inicio,dados.Horario_TP.fim);
if (pos3!= -1){

    printf("\n Ja existe uma aula marcada na hora indicada \n");

}else{

    if (pos != -1){
        printf("\n C�digo da aula j� existente \n");
    }else{

        if (pos2!= -1){



            vTP[nTP] = dados;
            nTP++;
            escreveFichBinarioTP(vTP,nTP);
            (*nAgenda)++;
            uc[pos2].aulasRealizadasT++;
            uc[pos2].aulas.TP--;

            if (dados.gravacao_TP==1){
                (*nGrav)++;
            }
        }else{
            printf("\n nao existe esse codigo de uc \n");
        }
    }
}


return nTP;
}

























