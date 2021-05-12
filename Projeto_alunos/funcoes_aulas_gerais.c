#include <stdio.h>
#include <ctype.h>
#include "constantes.h"
#include "funcoes_auxiliar.h"
#include "funcoes_aulas.h"

// Procura aula com codigo inserido para apresentar dados

void dadosAula(TipoUC uc[MAXFUNC], AulaT vT[MAXFUNC], AulaTP vTP[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL){
char aula[50];
int pos,pos2,tipo;

printf("Insira o tipo de aula que pretende aceder (1 - T, 2 - TP, 3 - PL)");
tipo = lerInteiro(1,3);

switch(tipo){

case 1:
                printf("\n Insira o codigo da aula : \n");
                    lerString(aula,50);

                pos = procuraAula(vT,vTP,vPL,nT,nTP,nPL,aula);
                pos2=procuraUC(uc,40,vT[pos].codigoUC);

                    if (pos != -1){
                        escreveDadosT(vT[pos]);
                        printf("\n nome da UC: %s",uc[pos2].nomeUC);
                        printf("\nAulas restantes da UC: %d",uc[pos2].aulas.T);
                    }else{
                    printf("\n aula nao existente \n");
                    }


    break;


case 2:

       printf("\n Insira o codigo da aula : \n");
                    lerString(aula,50);

                pos = procuraAula(vT,vTP,vPL,nT,nTP,nPL,aula);
                pos2=procuraUC(uc,40,vTP[pos].codigoUC);

                    if (pos != -1){
                        escreveDadosTP(vTP[pos]);
                        printf("UC: %s",uc[pos2].nomeUC);
                        printf("Aulas restantes da UC: %d",uc[pos2].aulas.TP);
                    }else{
                    printf("\n aula nao existente \n");
                    }



    break;


case 3:


       printf("\n Insira o codigo da aula : \n");
                    lerString(aula,50);

                pos = procuraAula(vT,vTP,vPL,nT,nTP,nPL,aula);
                pos2=procuraUC(uc,40,vPL[pos].codigoUC);

                    if (pos != -1){
                        escreveDadosPL(vPL[pos]);
                        printf("UC: %s",uc[pos2].nomeUC);
                        printf("Aulas restantes da UC: %d",uc[pos2].aulas.PL);
                    }else{
                    printf("\n aula nao existente \n");
                    }



    break;
}

}




// ALTERA O ESTADO DA AULA

void estadoAula(TipoUC uc[40], AulaT vT[MAXFUNC], AulaTP vTP[MAXFUNC], AulaPL vPL[MAXFUNC], int *nT, int *nTP, int *nPL,int *nReal, int *nAgenda){

char escolha[50];
int i, escolha2, pos, posuc;
int estado, estado2, tipo;

printf("Insira o tipo de aula que pretende aceder (1 - T, 2 - TP, 3 - PL)");
tipo = lerInteiro(1,3);


switch(tipo){

case 1:

                    printf("\n escolha a aula que pretende iniciar / finalizar\n");

                        for(i=0;i<*nT;i++){

                            printf("\ncodigo: %s",vT[i].codigo_aula_T);
                                estado = vT[i].estado;

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


                        printf("\n Insira o codigo da aula que pretende inicializar ou finalizar: \n");
                            lerString(escolha,50);

                          pos = procuraAula(vT,vTP,vPL,*nT,*nTP,*nPL,escolha);
                                    if (pos != 1){

                                            estado2 = vT[pos].estado;

                                            switch (estado2){

                                            case 1:
                                                printf("\n pretende inicializar a aula com o codigo %s? 1 - sim 2 - nao \n", vT[pos].codigo_aula_T);
                                                    escolha2 = lerInteiro(1,2);

                                                        if (escolha2 == 1){
                                                            vT[pos].estado = 2;
                                                        }else{
                                                            vT[pos].estado = 1;
                                                        }
                                            break;

                                            case 2:
                                                printf("\n pretende finalizar a aula com o codigo %s? 1 - sim 2 - nao \n", vT[pos].codigo_aula_T);
                                                    escolha2 = lerInteiro(1,2);

                                                        if (escolha2 == 1){
                                                            vT[pos].estado = 3;
                                                           posuc = procuraUC(uc, 40, vT[pos].codigoUC);

                                                           if (posuc != -1){
                                                            uc[posuc].aulasRealizadasT += 1;
                                                            (*nAgenda)--;
                                                            (*nReal)++;

                                                           }
                                                        }else{
                                                            vT[pos].estado = 2;
                                                        }
                                            break;

                                            case 3:
                                                printf("\n A aula já se encontra finalizada\n");
                                            break;

                                            default:
                                                printf("\n Erro\n");
                                            }
                                    }else{
                                    printf("\ncodigo nao encontrado\n");
                                    }


    break;



case 2:

                                    printf("\n escolha a aula que pretende iniciar / finalizar\n");

                                    for(i=0;i<*nTP;i++){

                                        printf("\ncodigo: %s",vTP[i].codigo_aula_TP);
                                            estado = vTP[i].estado;

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


                                    printf("\n Insira o codigo da aula que pretende inicializar ou finalizar: \n");
                                        lerString(escolha,50);

                                       pos = procuraAula(vT,vTP,vPL,*nT,*nTP,*nPL,escolha);

                                                if (pos != -1){
                                                        estado2 = vTP[pos].estado;

                                                        switch (estado2){

                                                        case 1:
                                                            printf("\n pretende inicializar a aula com o codigo %s? 1 - sim 2 - nao \n", vTP[pos].codigo_aula_TP);
                                                                escolha2 = lerInteiro(1,2);

                                                                    if (escolha2 == 1){
                                                                        vTP[pos].estado = 2;
                                                                    }else{
                                                                        vTP[pos].estado = 1;
                                                                    }
                                                        break;

                                                        case 2:
                                                            printf("\n pretende finalizar a aula com o codigo %s? 1 - sim 2 - nao \n", vTP[pos].codigo_aula_TP);
                                                                escolha2 = lerInteiro(1,2);

                                                                    if (escolha2 == 1){
                                                                        vTP[pos].estado = 3;
                                                                        posuc = procuraUC(uc, 40, vT[pos].codigoUC);

                                                                            if (posuc != -1){
                                                                            uc[posuc].aulasRealizadasTP += 1;
                                                                                (*nAgenda)--;
                                                                             (*nReal)++;

                                                           }
                                                                    }else{
                                                                        vTP[pos].estado = 2;
                                                                    }
                                                        break;

                                                        case 3:
                                                            printf("\n A aula já se encontra finalizada\n");
                                                        break;

                                                        default:
                                                            printf("\n Erro\n");
                                                        }
                                                }else{
                                                        printf("\n Código da aula não existente \n");
                                    }


    break;




case 3:

                            printf("\n escolha a aula que pretende iniciar / finalizar\n");

                                for(i=0;i<*nPL;i++){

                                    printf("\ncodigo: %s",vPL[i].codigo_aula_PL);
                                        estado = vPL[i].estado;

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


                                printf("\n Insira o codigo da aula que pretende inicializar ou finalizar: \n");
                                    lerString(escolha,50);

                                   pos = procuraAula(vT,vTP,vPL,*nT,*nTP,*nPL,escolha);

                                            if (pos != -1){
                                                    estado2 = vPL[pos].estado;

                                                    switch (estado2){

                                                    case 1:
                                                        printf("\n pretende inicializar a aula com o codigo %s? 1 - sim 2 - nao \n", vPL[pos].codigo_aula_PL);
                                                            escolha2 = lerInteiro(1,2);

                                                                if (escolha2 == 1){
                                                                    vPL[pos].estado = 2;
                                                                }else{
                                                                    vPL[pos].estado = 1;
                                                                }
                                                    break;

                                                    case 2:
                                                        printf("\n pretende finalizar a aula com o codigo %s? 1 - sim 2 - nao \n", vPL[pos].codigo_aula_PL);
                                                            escolha2 = lerInteiro(1,2);

                                                                if (escolha2 == 1){
                                                                    vPL[pos].estado = 3;

                                                                    posuc = procuraUC(uc, 40, vT[pos].codigoUC);

                                                                        if (posuc != -1){
                                                                        uc[posuc].aulasRealizadasPL += 1;
                                                                                (*nAgenda)--;
                                                                             (*nReal)++;

                                                                        }

                                                                }else{
                                                                    vPL[pos].estado = 2;
                                                                }
                                                    break;

                                                    case 3:
                                                        printf("\n A aula já se encontra finalizada\n");
                                                    break;

                                                    default:
                                                        printf("\n Erro\n");
                                                    }
                                            }else{
                                                    printf("\n Código da aula não existente \n");
                                }



    break;

                        default:

                            printf("\n erro \n");



}


}




//procura o codigo da UC

int procuraUC(TipoUC UC[], int n, char codigoUC[]){
int i, pos;
pos = -1;

for (i=0;i<n;i++){
    if (strcmp(UC[i].codigo,codigoUC)==0){
        pos = i;
        i=n;
    }

}
return pos;
}




//procura codigo de aula

int procuraAula (AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL, char codigoAula[]){
int i, pos;
pos = -1;
for (i=0;i<nT;i++){
    if (strcmp(vT[i].codigo_aula_T,codigoAula)==0){
        pos = i;
        i=nT;
    }
}
    for (i=0;i<nTP;i++){

    if (strcmp(vTP[i].codigo_aula_TP,codigoAula)==0){
        pos = i;
        i=nTP;
    }
}

for (i=0;i<nPL;i++){
    if (strcmp(vPL[i].codigo_aula_PL,codigoAula)==0){
        pos = i;
        i=nPL;
    }
}
return pos;
}


//vê se existe alguma aula na data que é apontada

int procuraData (AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL, int dia, int mes, int ano, float inicio, float fim){
int i, pos;
pos = -1;

for (i=0;i<nT;i++){
    if ((vT[i].Horario_T.dia == dia) && (vT[i].Horario_T.mes == mes) && (vT[i].Horario_T.ano == ano)){
            if(((fim > vT[i].Horario_T.inicio) && (fim <= vT[i].Horario_T.fim)) || ((inicio >= vT[i].Horario_T.inicio) && (inicio < vT[i].Horario_T.fim))){
                pos = i;
                i=nT;
            }
    }
}

    for (i=0;i<nTP;i++){
    if ((vTP[i].Horario_TP.dia == dia) && (vTP[i].Horario_TP.mes == mes) && (vTP[i].Horario_TP.ano == ano)){
            if(((fim > vTP[i].Horario_TP.inicio) && (fim <= vTP[i].Horario_TP.fim)) || ((inicio >= vTP[i].Horario_TP.inicio) && (inicio < vTP[i].Horario_TP.fim))){
                pos = i;
                i=nTP;
            }
    }

                }


    for (i=0;i<nPL;i++){
    if ((vPL[i].Horario_PL.dia == dia) && (vPL[i].Horario_PL.mes == mes) && (vPL[i].Horario_PL.ano == ano)){
            if(((fim > vPL[i].Horario_PL.inicio) && (fim <= vPL[i].Horario_PL.fim)) || ((inicio >= vPL[i].Horario_PL.inicio) && (inicio < vPL[i].Horario_PL.fim))){
                pos = i;
                i=nPL;
            }
    }

                }
return pos;
}


int menu(int numUC, int nReal, int nAgenda, int nGrav){
    char option;
    printf("\n************************ Menu Principal ************************");
    printf("\n Quantidade de UCs: %d\n",numUC);
    printf("\n Numero de aulas agendadas: %d\n",nAgenda);
    printf("\n Numero de aulas realizadas: %d\n",nReal);
    printf("\n Numero de aulas gravadas: %d\n",nGrav);
    printf("\n 1- Gestao de Aulas T");
    printf("\n 2- Gestao de Aulas TP");
    printf("\n 3- Gestao de Aulas PL");
    printf("\n 4- Alterar estado da Aula");
    printf("\n 5- Procurar Aula ");
    printf("\n 6- Adicionar UC ");
    printf("\n 7- listagem de UC ");
    printf("\n 8- Alterar aula agendada ");
    printf("\n 9- Registar acesso de Aluno");
    printf("\n 10- Ranking das Ucs");
    printf("\n 11- Alterar UC \n");
    option = lerInteiro(1,11);
    return option;
}

int submenuAulas(){
    char option2;
    printf("\n************************ Submenu Aulas************************");
    printf("\n 1- Agendar Aula");
    printf ("\n 2- Listar Aulas");
    option2 = lerInteiro(1,2);
    return option2;
}

int submenuAlterarAulas(){
int option3;
printf("\n************************ Submenu Alterar Aulas ************************");
    printf("\n 1- Eliminar Aula");
    printf ("\n 2- Alterar Aula");
    option3 = lerInteiro(1,2);
    return option3;


}









void escreveFichBinarioT(AulaT vT[], int nT){
FILE *ficheiro;

ficheiro=fopen("dadosT.dat","wb");

if (ficheiro == NULL) {
printf ("Erro abrir ficheiro");
}

else{

fwrite(vT,sizeof(AulaT),nT,ficheiro);
fclose(ficheiro); }
}








void escreveFichBinarioTP(AulaTP vTP[], int nTP){
FILE *ficheiro;

ficheiro=fopen("dadosTP.dat","wb");

if (ficheiro == NULL) {
printf ("Erro abrir ficheiro");
}

else{

fwrite(vTP,sizeof(AulaTP),nTP,ficheiro);
fclose(ficheiro); }
}








void escreveFichBinarioPL(AulaPL vPL[], int nPL){
FILE *ficheiro;

ficheiro=fopen("dadosPL.dat","wb");

if (ficheiro == NULL) {
printf ("Erro abrir ficheiro");
}

else{

fwrite(vPL,sizeof(AulaPL),nPL,ficheiro);
fclose(ficheiro); }
}



void escreveFichBinarioUC(TipoUC vUC[], int nUC){
FILE *ficheiro;

ficheiro=fopen("dadosUC.dat","wb");

if (ficheiro == NULL) {
printf ("Erro abrir ficheiro");
}

else{

fwrite(vUC,sizeof(TipoUC),nUC,ficheiro);
fclose(ficheiro); }
}






// LE DADOS DA UC

TipoUC leDadosUC(){
TipoUC UC;



            printf("Codigo da UC: ");
            lerString(UC.codigo,50);

            printf("Designacao da UC: ");
            lerString(UC.nomeUC,50);

            printf("Semestre: ");
            UC.semestre = lerInteiro(1,6);

            printf("Regime 1 - 'D' ou 2 - 'PL': ");
            UC.regime = lerInteiro(1,2);

            printf("Quantidade prevista de aulas Teoricas: ");
            UC.aulas.T = lerInteiro(1,100);

            printf("Quantidade prevista de aulas Teoricas e praticas: ");
            UC.aulas.TP = lerInteiro(1,100);


            printf("Quantidade prevista de aulas praticas laboratoreais: ");
            UC.aulas.PL = lerInteiro(1,100);


return UC;
}








//acrescenta os dados da UC no vetor

int acrescentaNoVetorUC(TipoUC uc[40],int nUC){
TipoUC dados;
int pos;


dados=leDadosUC();
pos=procuraUC(uc,40,dados.codigo);

    if (pos != -1){
        printf("\n Código da UC ja existe \n");
    }else{


            uc[nUC] = dados;
            nUC++;
            escreveFichBinarioUC(uc,nUC);

    }



return nUC;
}


// LISTA TODAS AS UCS
void listagemUC(TipoUC uc[40], int nUC, AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL){
int i;

if (nUC==0){
    printf("\n Não existem dados!!");
}
else{

    for (i=0; i<nUC; i++) {

        escreveDadosUC(uc[i], vT, vTP, vPL, nT, nTP, nPL);
    }
}

}



// ESCREVE OS DADOS DA UC

void escreveDadosUC(TipoUC UC, AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL){
    int regime,i;


    printf("********DADOS DA UC*********");
printf("\n Nome da UC:%s",UC.nomeUC);

printf("\n codigo da UC:%s",UC.codigo);

regime = UC.regime;

switch(regime){

case 1:
    printf("\n Regime: Diurno");

    break;

case 2:

    printf("\n Regime: Pos laboral");

    break;

}
printf("\nSemestre: %d", UC.semestre);

        printf("\nQuantidade prevista de aulas Teoricas: %d",UC.aulas.T);


        printf("\nQuantidade prevista de aulas Teoricas e praticas: %d", UC.aulas.TP);

        printf("\nQuantidade prevista de aulas praticas laboratoreais: %d \n",UC.aulas.PL);

        printf ("\nquantidade de aulas teoricas realizadas: %d", UC.aulasRealizadasT);

        printf ("\nquantidade de aulas teorico praticas realizadas: %d", UC.aulasRealizadasTP);

        printf ("\nquantidade de aulas praticas laboratoriais realizadas: %d \n", UC.aulasRealizadasPL);

printf("********AULAS DA UC**************");

       for (i=0;i<nT;i++){
    if (strcmp(vT[i].codigoUC,UC.codigo)==0){

            escreveDadosT(vT[i]);



    }
}



    for (i=0;i<nTP;i++){

    if (strcmp(vTP[i].codigoUC,UC.codigo)==0){

            escreveDadosTP(vTP[i]);



    }
}

for (i=0;i<nPL;i++){
    if (strcmp(vPL[i].codigoUC,UC.codigo)==0){

            escreveDadosPL(vPL[i]);



    }
}


}


//ELIMINA A AULA

void eliminaAula(AulaT vT[MAXFUNC], AulaTP vTP[MAXFUNC], AulaPL vPL[MAXFUNC] , int *nT, int *nTP, int *nPL, int *nAgenda ){
char codaula[50];
int decisao;
int i, pos;

printf("Insira o tipo de aula: 1 - T, 2 - TP, 3 - PL");
decisao = lerInteiro(1,3);

switch (decisao){


case 1:
    if (*nT == 0){

    printf("nao ha aulas agendadas!");

}
    else{
        printf("Codigo da aula a eliminar: ");
        lerString(codaula,50);

        pos = procuraAula(vT,vTP,vPL,*nT,*nTP,*nPL,codaula);



            if (pos ==-1){
                printf("Aula nao existe!!");
            }else{

            for (i=pos; i< *nT - 1; i++){
                vT[i] = vT[i+1];

            }
                (*nT)--;
                (*nAgenda)--;

            }
}

    break;



case 2:

  if (*nTP == 0){

    printf("nao ha aulas agendadas!");

}
    else{
        printf("Codigo da aula a eliminar: ");
        lerString(codaula,50);

        pos = procuraAula(vT,vTP,vPL,*nT,*nTP,*nPL,codaula);



            if (pos ==-1){
                printf("Aula nao existe!!");
            }else{

            for (i=pos; i< *nTP - 1; i++){
                vTP[i] = vTP[i+1];

            }
                (*nTP)--;
                (*nAgenda)--;
            }
}

    break;




case 3:

  if (*nPL == 0){

    printf("nao ha aulas agendadas!");

}
    else{
        printf("Codigo da aula a eliminar: ");
        lerString(codaula,50);

        pos = procuraAula(vT,vTP,vPL,*nT,*nTP,*nPL,codaula);



            if (pos ==-1){
                printf("Aula nao existe!!");
            }else{

            for (i=pos; i< *nPL - 1; i++){
                vPL[i] = vPL[i+1];

            }
                (*nPL)--;
                (*nAgenda)--;
            }
}

    break;
}
}




//ALTERA A DATA DA AULA

void alterarAula(AulaT vT[MAXFUNC], AulaTP vTP[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL){
char codigo[50];
int tempo,pos2, escolha,horafinal,controlo2, pos, controlo;

printf("\ninsira o tipo da aula que pretende alterar: 1 - T, 2 - TP, 3 - PL\n");
escolha = lerInteiro(1,3);



switch(escolha){


case 1:
    printf("\ninsira o codigo da aula: \n");
    lerString(codigo,50);
    pos = procuraAula(vT,vTP,vPL,nT,nTP,nPL,codigo);

if (pos == -1){
    printf("\nAula nao existe\n");

}else{

                            do{
                                printf("Insira o turno (1 - D ou 2 - PL)");
                                vT[pos].turno = lerInteiro(1,2);

                                printf("Quanto tempo vai durar a aula em minutos?");
                                tempo = lerInteiro(1,500);

                            controlo = vT[pos].turno;

                            switch(controlo){

                            case 1:
                                do{
                                printf("Hora de inicio (8h - 18h): ");
                                    controlo2 = lerFloat(8,18);
                                    controlo2 = controlo2 * 60;
                                    horafinal = controlo2 + tempo;
                                }while(horafinal>1080);
                                    vT[pos].Horario_T.inicio = controlo2;
                                    vT[pos].Horario_T.fim = horafinal;
                                break;

                            case 2:
                                do{
                                    printf("Hora de inicio (18h - 24h): ");
                                        controlo2 = lerFloat(18,24);
                                    controlo2 = controlo2 * 60;
                                    horafinal = controlo2 + tempo;
                                }while(horafinal >1440);
                                    vT[pos].Horario_T.inicio = controlo2;
                                    vT[pos].Horario_T.fim = horafinal;
                                break;

                            default:
                                printf("Escolha incorreta!!");

                            }


                            printf("Dia da aula: ");
                                vT[pos].Horario_T.dia = lerInteiro(1,31);
                            printf("Mês: ");
                                vT[pos].Horario_T.mes = lerInteiro(1,12);
                            printf("Ano: ");
                                vT[pos].Horario_T.ano = lerInteiro(2021,2025);
                                pos2 = procuraData(vT,vTP,vPL,nT,nTP,nPL,vT[pos].Horario_T.dia,vT[pos].Horario_T.mes,vT[pos].Horario_T.ano,vT[pos].Horario_T.inicio,vT[pos].Horario_T.fim);
                            }while(pos2!=-1);
}

    break;




case 2:
    printf("\ninsira o codigo da aula: \n");
    lerString(codigo,50);
      pos = procuraAula(vT,vTP,vPL,nT,nTP,nPL,codigo);

    if (pos == -1){
        printf("\nAula nao existe\n");

    }else{

                        do{
                                printf("Insira o turno (1 - D ou 2 - PL)");
                                vTP[pos].turno = lerInteiro(1,2);

                                printf("Quanto tempo vai durar a aula em minutos?");
                                tempo = lerInteiro(1,500);

                            controlo = vTP[pos].turno;

                            switch(controlo){

                            case 1:
                                do{
                                printf("Hora de inicio (8h - 18h): ");
                                    controlo2 = lerFloat(8,18);
                                    controlo2 = controlo2 * 60;
                                    horafinal = controlo2 + tempo;
                                }while(horafinal>1080);
                                    vTP[pos].Horario_TP.inicio = controlo2;
                                    vTP[pos].Horario_TP.fim = horafinal;
                                break;

                            case 2:
                                do{
                                    printf("Hora de inicio (18h - 24h): ");
                                        controlo2 = lerFloat(18,24);
                                    controlo2 = controlo2 * 60;
                                    horafinal = controlo2 + tempo;
                                }while(horafinal >1440);
                                    vTP[pos].Horario_TP.inicio = controlo2;
                                    vTP[pos].Horario_TP.fim = horafinal;
                                break;

                            default:
                                printf("Escolha incorreta!!");

                            }


                            printf("Dia da aula: ");
                                vTP[pos].Horario_TP.dia = lerInteiro(1,31);
                            printf("Mês: ");
                                vTP[pos].Horario_TP.mes = lerInteiro(1,12);
                            printf("Ano: ");
                                vTP[pos].Horario_TP.ano = lerInteiro(2021,2025);
                                   pos2 = procuraData(vT,vTP,vPL,nT,nTP,nPL,vTP[pos].Horario_TP.dia,vTP[pos].Horario_TP.mes,vTP[pos].Horario_TP.ano,vTP[pos].Horario_TP.inicio,vTP[pos].Horario_TP.fim);
                        }while(pos2!=-1);
}




    break;




case 3:
        printf("\ninsira o codigo da aula: \n");
    lerString(codigo,50);
      pos = procuraAula(vT,vTP,vPL,nT,nTP,nPL,codigo);

        if (pos == -1){
            printf("\nAula nao existe\n");

        }else{

                            do{
                                printf("Insira o turno (1 - D ou 2 - PL)");
                                vPL[pos].turno = lerInteiro(1,2);

                                printf("Quanto tempo vai durar a aula em minutos?");
                                tempo = lerInteiro(1,500);

                            controlo = vPL[pos].turno;

                            switch(controlo){

                            case 1:
                                do{
                                printf("Hora de inicio (8h - 18h): ");
                                    controlo2 = lerFloat(8,18);
                                    controlo2 = controlo2 * 60;
                                    horafinal = controlo2 + tempo;
                                }while(horafinal>1080);
                                    vPL[pos].Horario_PL.inicio = controlo2;
                                    vPL[pos].Horario_PL.fim = horafinal;
                                break;

                            case 2:
                                do{
                                    printf("Hora de inicio (18h - 24h): ");
                                        controlo2 = lerFloat(18,24);
                                    controlo2 = controlo2 * 60;
                                    horafinal = controlo2 + tempo;
                                }while(horafinal >1440);
                                    vPL[pos].Horario_PL.inicio = controlo2;
                                    vPL[pos].Horario_PL.fim = horafinal;
                                break;

                            default:
                                printf("Escolha incorreta!!");

                            }


                            printf("Dia da aula: ");
                                vPL[pos].Horario_PL.dia = lerInteiro(1,31);
                            printf("Mês: ");
                                vPL[pos].Horario_PL.mes = lerInteiro(1,12);
                            printf("Ano: ");
                                vPL[pos].Horario_PL.ano = lerInteiro(2021,2025);
                                   pos2 = procuraData(vT,vTP,vPL,nT,nTP,nPL,vPL[pos].Horario_PL.dia,vPL[pos].Horario_PL.mes,vPL[pos].Horario_PL.ano,vPL[pos].Horario_PL.inicio,vPL[pos].Horario_PL.fim);

                            }while(pos2!=-1);

}


    break;



}





}







//RANKING DAS UCS


void ordem(TipoUC UC[40], AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL, int nUC){








    int i, m, x;

    for(i=0;i<40;i++){
    x=UC[i].aulas.acessos;
        for(m=0;m<40;m++){
        if(x>UC[m].aulas.acessos){
        UC[i].contador=UC[i].contador+1;
    }

    }


    }
    for(i=0;i<40;i++){
        for(m=0;m<nUC;m++){
            if(39-i==UC[m].contador){
                escreveDadosUC(UC[m],vT,vTP,vPL,nT,nTP,nPL);
            }

        }
    }
}






// ALTERAR UCS

void alterarUcs(TipoUC uc[40], int nUC){
char codigo[50];
int pos;

printf("\ninsira o codigo da uc que pretende alterar:\n");
lerString(codigo,50);

pos = procuraUC(uc,nUC,codigo);

if (pos == -1){

    printf("/n UC nao existe /n");

}else{

            printf("Designacao da UC: ");
            lerString(uc[pos].nomeUC,50);

            printf("Semestre: ");
            uc[pos].semestre = lerInteiro(1,6);

            printf("Regime 1 - 'D' ou 2 - 'PL': ");
            uc[pos].regime = lerInteiro(1,2);

            printf("Quantidade prevista de aulas Teoricas: ");
            uc[pos].aulas.T = lerInteiro(1,100);

            printf("Quantidade prevista de aulas Teoricas e praticas: ");
            uc[pos].aulas.TP = lerInteiro(1,100);


            printf("Quantidade prevista de aulas praticas laboratoreais: ");
            uc[pos].aulas.PL = lerInteiro(1,100);


}


}
