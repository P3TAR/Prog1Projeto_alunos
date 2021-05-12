#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

void escreveFichBinario(AulaT vT[MAXFUNC]);
void dadosAula(TipoUC uc[MAXFUNC], AulaT vT[MAXFUNC], int n);
void estadoAula(AulaT vT[MAXFUNC], int n);
int procuraData (AulaT vT[], int n, int dia, int mes, int ano, float inicio, float fim);
int procuraUC(TipoUC UC[], int n, char codigoUC[]);
int acrescentaNoVetorT(TipoUC uc[MAXFUNC], AulaT vT[], int n);
int procuraT (AulaT vT[], int n, char codigoAula[]);
AulaT leDadosT(void);
void escreveDadosT(AulaT teorico);
void listagemT(AulaT vT[MAXFUNC], int n);
#endif // FUNCOES_AULAS_H_INCLUDED
