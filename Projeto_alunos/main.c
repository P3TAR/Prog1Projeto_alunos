#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "funcoes_auxiliar.h"
#include "funcoes_aulas.h"

int main()
{
    TipoUC vetorUC[MAXFUNC];
    AulaTP vetorTP[MAXFUNC];
    AulaT vetorT[MAXFUNC];
    AulaPL vetorPL[MAXFUNC];
    char acesso='k', codigo;
    int numeroT,numeroTP, numeroPL, opcao, opcaosub, numeroUC,i, nReal, nAgenda, nGrav,x, op;
    int NumAluno, pos;

    numeroUC=0;
    numeroT=0;
    numeroTP=0;
    numeroPL=0;
    nReal=0;
    nGrav=0;

    for (i=0;i<40;i++){
    vetorUC[i].aulasRealizadasT = 0;
    vetorUC[i].aulasRealizadasTP = 0;
    vetorUC[i].aulasRealizadasPL = 0;
    }





    do{
            opcao = menu(numeroUC, nReal, nAgenda,nGrav);
            switch (opcao){

                case 1:
                            opcaosub = submenuAulas();

                            switch(opcaosub){

                            case 1:
                                numeroT = acrescentaNoVetorT(vetorUC,vetorTP,vetorT,vetorPL,numeroT,numeroTP,numeroPL,&nAgenda, &nGrav);
                                break;

                            case 2:
                                listagemT(vetorT,numeroT);
                                break;
                            }

                    break;


                case 2:
                            opcaosub = submenuAulas();

                            switch(opcaosub){

                            case 1:
                                numeroTP = acrescentaNoVetorTP(vetorUC,vetorTP,vetorT,vetorPL,numeroT,numeroTP,numeroPL,&nAgenda, &nGrav);
                                break;

                            case 2:
                                listagemTP(vetorTP,numeroTP);
                                break;
                                }

                    break;

                case 3:
                            opcaosub = submenuAulas();

                            switch(opcaosub){

                            case 1:
                                numeroPL = acrescentaNoVetorPL(vetorUC,vetorTP,vetorT,vetorPL,numeroT,numeroTP,numeroPL,&nAgenda, &nGrav);
                                break;

                            case 2:
                                listagemPL(vetorPL,numeroPL);
                                break;
                                }


                    break;

                case 4:

                       estadoAula(vetorUC,vetorT,vetorTP,vetorPL,&numeroT,&numeroTP,&numeroPL, &nReal, &nAgenda);

                    break;


                case 5:

                        dadosAula(vetorUC, vetorT,vetorTP,vetorPL,numeroT,numeroTP,numeroPL);
                    break;



                case 6:
                     numeroUC =   acrescentaNoVetorUC(vetorUC, numeroUC);

                    break;

                case 7:
                    listagemUC(vetorUC, numeroUC,vetorT, vetorTP,vetorPL,numeroT,numeroTP,numeroPL);

                    break;


                case 8:
                        opcaosub = submenuAlterarAulas();

                        switch (opcaosub){

                            case 1:
                                  eliminaAula(vetorT,vetorTP,vetorPL,&numeroT,&numeroTP,&numeroPL,&nAgenda);
                                break;



                            case 2:
                                alterarAula(vetorT,vetorTP,vetorPL,numeroT,numeroTP,numeroPL);

                                break;



                        }
                    break;


                case 9:
                                do{


                                    printf("\nPretende adicionar (1) ou sair (2)-");
                                    op = lerInteiro(1,2);

                                if(op==1){


                                        printf("\nEscreva o numero de estudante(1/100)-");
                                        NumAluno = lerInteiro(1,100);


                                    printf("\nEscreva o codigo da aula:");
                                    lerString(&codigo,50);





                                                printf("\nDigite o tipo de acesso(online(n)/offline(f))-");
                                                lerString(&acesso, 1);



                                    FILE *AulaB;
                                        AulaB = fopen("dados.dat", "a+b");

                                        x=fwrite(&NumAluno,sizeof(int),1,AulaB);
                                            printf("\n%d",x);
                                        x=fwrite(&codigo,sizeof(int),1,AulaB);
                                            printf("\n%d",x);
                                        x=fwrite(&acesso,sizeof(int),1,AulaB);
                                            printf("\n%x",x);
                                        fclose(AulaB);
                                    FILE *Aula;
                                        Aula = fopen("dados.dat", "a+");

                                        x=fwrite(&NumAluno,sizeof(int),1,Aula);
                                            printf("\n%d",x);
                                        x=fwrite(&codigo,sizeof(int),1,Aula);
                                            printf("\n%d",x);
                                        x=fwrite(&acesso,sizeof(int),1,Aula);
                                            printf("\n%d",x);
                                        fclose(Aula);

                                }
                                }while(op!=2);






                        break;



                case 10:
                    ordem(vetorUC,vetorT,vetorTP,vetorPL,numeroT,numeroTP,numeroPL,numeroUC);

                    break;




                case 11:
                    alterarUcs(vetorUC, numeroUC);

                    break;

                default:
                    printf("\n opcao invalida! \n");
            }
    }while (opcao != 0);
return 0;
}


