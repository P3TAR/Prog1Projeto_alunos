#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED
#define MAXFUNC 50
#define MAX 100
#define MAX_STRING 50



typedef struct{
   int acessos;
   int T;
   int TP;
   int PL;
}Totalaulas;


typedef struct{
    int aulasRealizadasT;
    int aulasRealizadasTP;
    int aulasRealizadasPL;
    char nomeUC[MAX_STRING];
    Totalaulas aulas;
    char codigo[MAX_STRING];
    int regime;
    int contador;
    int tipo;
    int semestre;
}TipoUC;





typedef struct{
    int dia;
    int mes;
    int ano;
    float inicio;
    float fim;
}Data;


typedef struct{
    int numEstudante[100];
    char AulaON_OFF;
}TipoEstudante;


typedef struct{
    char codigoUC[50];
    char codigo_aula_T[50];
    char profaula_T[50];
    Data Horario_T;
    int gravacao_T;
    int turno;
    int estado;
    TipoEstudante Acesso;
}AulaT;

typedef struct{
    char codigoUC[50];
    char codigo_aula_TP[50];
    char profaula_TP[50];
    Data Horario_TP;
    int gravacao_TP;
    int turno;
    int estado;
    TipoEstudante Acesso;
}AulaTP;

typedef struct{
    char codigoUC[50];
    char codigo_aula_PL[50];
    char profaula_PL[50];
    Data Horario_PL;
    int gravacao_PL;
    int turno;
    int estado;
    TipoEstudante Acesso;
}AulaPL;




#endif // CONSTANTES_H_INCLUDED
