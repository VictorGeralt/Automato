#ifndef automato_hpp
#define automato_hpp
#include <iostream>
#include <cstring>
#define TAM 50 

struct funcoes
{
    int estadoAtual;
    char valor;
    int estadoFinal;
};


struct automato
{
    char iniciais[50];
    char finais[50];
    funcoes funcs[TAM];
};

int verificadorInit(char* a,char* p);
int verificadorFim(char* a,char* p,int pAtual);
int verificador(automato a, char* palavra, int contador);
int VerificarPalavra(char* palavra, automato a,int cont);



#endif