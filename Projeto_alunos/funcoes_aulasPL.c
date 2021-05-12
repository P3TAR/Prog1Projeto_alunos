
#include <stdio.h>
#include <ctype.h>
#include "constantes.h"
#include "funcoes_auxiliar.h"
#include "funcoes_aulas.h"



//listagem de todos os dados

void listagemPL(AulaPL vPL[MAXFUNC], int n){
int i;

if (n==0){
    printf("\n Não existem dados!!");
}
else{

    for (i=0; i<n; i++) {

        escreveDadosPL(vPL[i]);
    }
}

}



// escreve os dados

void escreveDadosPL(AulaPL teorico){
    int estado;
    int gravacao;




printf("\n codigo da UC:%s",teorico.codigoUC);

printf("\n Codigo da aula:%s", teorico.codigo_aula_PL);

printf("\nProfessor:%s",teorico.profaula_PL);

gravacao = teorico.gravacao_PL;
switch(gravacao){
case 1:
    printf("\n Gravacao de aula: sim");
    break;

case 2:
    printf("\n Gravacao de aula:nao");
    break;
}


printf("\nData da aula:%d/%d/%d",teorico.Horario_PL.dia,teorico.Horario_PL.mes,teorico.Horario_PL.ano);

printf("\nRealizado das:%.2f ate %.2f",teorico.Horario_PL.inicio,teorico.Horario_PL.fim);

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



//lê todos os dados que têm de ser inseridos

AulaPL leDadosPL(){
AulaPL aula;
char controlo;
float controlo2;
float horafinal;
int estado,tempo;

    estado = 1;

        aula.estado = estado;
            printf("Codigo da UC: ");
            lerString(aula.codigoUC,50);

            printf("Codigo da aula: ");
            lerString(aula.codigo_aula_PL,50);

            printf("Professor: ");
            lerString(aula.profaula_PL,100);

            printf("Gravação de aula: 1 - sim 2 - nao");
            aula.gravacao_PL = lerInteiro(1,2);

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
        aula.Horario_PL.inicio = controlo2;
        aula.Horario_PL.fim = horafinal;
    break;

case 2:
    do{
        printf("Hora de inicio (18h - 24h): ");
            controlo2 = lerFloat(18,24);
        controlo2 = controlo2 * 60;
        horafinal = controlo2 + tempo;
    }while(horafinal >1440);
        aula.Horario_PL.inicio = controlo2;
        aula.Horario_PL.fim = horafinal;
    break;

default:
    printf("Escolha incorreta!!");

}


printf("Dia da aula: ");
    aula.Horario_PL.dia = lerInteiro(1,31);
printf("Mês: ");
    aula.Horario_PL.mes = lerInteiro(1,12);
printf("Ano: ");
    aula.Horario_PL.ano = lerInteiro(2021,2025);
return aula;
}





//procura codigo de aula

int procuraPL (AulaPL vPL[], int n, char codigoAula[]){
int i, pos;
pos = -1;
for (i=0;i<n;i++){
    if (strcmp(vPL[i].codigo_aula_PL,codigoAula)==0){
        pos = i;
        i=n;
    }

}
return pos;
}






//acrescenta os dados de aula no vetor

int acrescentaNoVetorPL(TipoUC uc[MAXFUNC], AulaTP vTP[MAXFUNC], AulaT vT[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL, int *nAgenda, int *nGrav){
AulaPL dados;
TipoUC codUC;
int pos,pos2,pos3;
int elem;

elem = 0;
dados=leDadosPL();
pos=procuraAula(vT,vTP,vPL,nT,nTP,nPL,dados.codigo_aula_PL);
pos2=procuraUC(uc,40,dados.codigoUC);
pos3 = procuraData(vT, vTP, vPL, nT, nTP,nPL, dados.Horario_PL.dia,dados.Horario_PL.mes,dados.Horario_PL.ano,dados.Horario_PL.inicio,dados.Horario_PL.fim);
if (pos3!= -1){

    printf("\n Ja existe uma aula marcada na hora indicada \n");

}else{

    if (pos != -1){
        printf("\n Código da aula já existente \n");
    }else{

        if (pos2!= -1){
            uc[pos2].aulasRealizadasPL++;
            uc[pos2].aulas.PL--;

            vPL[nPL] = dados;
            nPL++;
            escreveFichBinarioPL(vPL,nPL);
            (*nAgenda)++;


            if (dados.gravacao_PL==1){
                (*nGrav)++;
            }
       }else{
         printf("\n nao existe esse codigo de uc \n");
       }
    }
}


return nPL;
}



























