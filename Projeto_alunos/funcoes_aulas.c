
#include <stdio.h>
#include <ctype.h>
#include "constantes.h"
#include "funcoes_auxiliar.h"
#include "funcoes_aulas.h"



//listagem de todos os dados

void listagemT(AulaT vT[MAXFUNC], int n){
int i;

if (n==0){
    printf("\n Não existem dados!!");
}
else{

    for (i=0; i<n; i++) {

        escreveDadosT(vT[i]);
    }
}

}



// escreve os dados

void escreveDadosT(AulaT teorico){
    int estado;
    int gravacao;




printf("\n codigo da UC:%s",teorico.codigoUC);

printf("\n Codigo da aula:%s", teorico.codigo_aula_T);

printf("\nProfessor:%s",teorico.profaula_T);

gravacao = teorico.gravacao_T;
switch(gravacao){
case 1:
    printf("\n Gravacao de aula: sim");
    break;

case 2:
    printf("\n Gravacao de aula:nao");
    break;
}


printf("\nData da aula:%d/%d/%d",teorico.Horario_T.dia,teorico.Horario_T.mes,teorico.Horario_T.ano);

printf("\nRealizado das:%.2f ate %.2f",teorico.Horario_T.inicio / 60,teorico.Horario_T.fim / 60);

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

AulaT leDadosT(){
AulaT aula;
char controlo;
float controlo2;
float horafinal;
int estado, tempo;

    estado = 1;

        aula.estado = estado;
            printf("Codigo da UC: ");
            lerString(aula.codigoUC,50);

            printf("Codigo da aula: ");
            lerString(aula.codigo_aula_T,50);

            printf("Professor: ");
            lerString(aula.profaula_T,100);

            printf("Gravação de aula: 1 - sim 2 - nao");
            aula.gravacao_T = lerInteiro(1,2);

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
        aula.Horario_T.inicio = controlo2;
        aula.Horario_T.fim = horafinal;
    break;

case 2:
    do{
        printf("Hora de inicio (18h - 24h): ");
            controlo2 = lerFloat(18,24);
        controlo2 = controlo2 * 60;
        horafinal = controlo2 + tempo;
    }while(horafinal >1440);
        aula.Horario_T.inicio = controlo2;
        aula.Horario_T.fim = horafinal;
    break;

default:
    printf("Escolha incorreta!!");

}


printf("Dia da aula: ");
    aula.Horario_T.dia = lerInteiro(1,31);
printf("Mês: ");
    aula.Horario_T.mes = lerInteiro(1,12);
printf("Ano: ");
    aula.Horario_T.ano = lerInteiro(2021,2025);
return aula;
}












//acrescenta os dados de aula no vetor

int acrescentaNoVetorT(TipoUC uc[MAXFUNC], AulaTP vTP[MAXFUNC], AulaT vT[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL, int *nAgenda, int *nGrav){
AulaT dados;
int pos,pos2,pos3;



dados=leDadosT();
pos=procuraAula(vT,vTP,vPL,nT,nTP,nPL,dados.codigo_aula_T);
pos2=procuraUC(uc,40,dados.codigoUC);
pos3 = procuraData(vT, vTP, vPL, nT, nTP,nPL, dados.Horario_T.dia,dados.Horario_T.mes,dados.Horario_T.ano,dados.Horario_T.inicio,dados.Horario_T.fim);
if (pos3!= -1){

    printf("\n Ja existe uma aula marcada na hora indicada \n");

}else{

    if (pos != -1){
        printf("\n Código da aula já existente \n");
    }else{

       if (pos2!= -1){
            uc[pos2].aulasRealizadasT++;
            uc[pos2].aulas.T--;
            vT[nT] = dados;
            nT++;
            escreveFichBinarioT(vT,nT);
            (*nAgenda)++;

            if (dados.gravacao_T==1){
                (*nGrav)++;
            }

        }else{
            printf("\n nao existe esse codigo de uc \n");
        }
    }
}


return nT;
}



























