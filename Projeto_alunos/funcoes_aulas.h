#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

void escreveFichBinarioT(AulaT vT[], int nT);
int submenuAulas();
int menu(int numUC, int nReal, int nAgenda, int nGrav);
void dadosAula(TipoUC uc[MAXFUNC], AulaT vT[MAXFUNC], AulaTP vTP[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL);
void estadoAula(TipoUC uc[40], AulaT vT[MAXFUNC], AulaTP vTP[MAXFUNC], AulaPL vPL[MAXFUNC], int *nT, int *nTP, int *nPL, int *nReal, int *nAgenda);
int procuraData (AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL, int dia, int mes, int ano, float inicio, float fim);
int procuraUC(TipoUC UC[], int n, char codigoUC[]);
int acrescentaNoVetorT(TipoUC uc[MAXFUNC], AulaTP vTP[MAXFUNC], AulaT vT[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL, int *nAgenda, int *nGrav);
int procuraAula (AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL, char codigoAula[]);
AulaT leDadosT(void);
void escreveDadosT(AulaT teorico);
void listagemT(AulaT vT[MAXFUNC], int n);

void listagemTP(AulaTP vTP[MAXFUNC], int n);
void escreveDadosTP(AulaTP teorico);
AulaTP leDadosTP();
int procuraTP (AulaTP vTP[], int n, char codigoAula[]);
int acrescentaNoVetorTP(TipoUC uc[MAXFUNC], AulaTP vTP[MAXFUNC], AulaT vT[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL, int *nAgenda, int *nGrav);


void listagemPL(AulaPL vPL[MAXFUNC], int n);
void escreveDadosPL(AulaPL teorico);
AulaPL leDadosPL();
int procuraPL (AulaPL vPL[], int n, char codigoAula[]);
int acrescentaNoVetorPL(TipoUC uc[MAXFUNC], AulaTP vTP[MAXFUNC], AulaT vT[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL, int *nAgenda,int *nGrav);

TipoUC leDadosUC();
void escreveDadosUC(TipoUC UC, AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL);
void listagemUC(TipoUC uc[40], int nUC, AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL);
int acrescentaNoVetorUC(TipoUC uc[40],int nUC);
void eliminaAula(AulaT vT[MAXFUNC], AulaTP vTP[MAXFUNC], AulaPL vPL[MAXFUNC] , int *nT, int *nTP, int *nPL, int *nAgenda );
void alterarAula(AulaT vT[MAXFUNC], AulaTP vTP[MAXFUNC], AulaPL vPL[MAXFUNC], int nT, int nTP, int nPL);
int submenuAlterarAulas();

void escreveFichBinarioUC(TipoUC vUC[], int nUC);
void escreveFichBinarioTP(AulaTP vTP[], int nTP);
void escreveFichBinarioPL(AulaPL vPL[], int nPL);
void alterarUcs(TipoUC uc[40], int nUC);

void ordem(TipoUC UC[40], AulaT vT[], AulaTP vTP[], AulaPL vPL[], int nT, int nTP, int nPL, int nUC);
#endif // FUNCOES_AULAS_H_INCLUDED
