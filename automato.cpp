#include "automato.hpp"

int verificadorInit(char* a,char* p){
    for (size_t i = 0; i<std::strlen(a); i++)
    {
        if (p[0]==a[i])
        {
            return i;
        }
    }
    return -1;
}

int verificadorFim(char* a,char* p,int pAtual){
    for (size_t i = 0; i<std::strlen(a); i++)
    {
        if (p[pAtual]==a[i])
        {
            return i;
        }
    }
    return -1;
}


int verificador(automato a, char* palavra, int contadorP,int contadorA,int estadoAtual){
    for (int i = 0; i < contadorA; i++)
    {
        if (palavra[contadorP]==palavra[contadorP+1])
        {
            if (a.funcs[i].estadoAtual==estadoAtual && palavra[contadorP]==a.funcs[i].valor && a.funcs[i].estadoAtual==a.funcs[i].estadoFinal )
            {  
            return i;
            }
        }else
        {   
            if (a.funcs[i].estadoAtual==estadoAtual && palavra[contadorP]==a.funcs[i].valor && a.funcs[i].estadoAtual!=a.funcs[i].estadoFinal )
            {  
            return i;
            }

        }
        
        
    }
    return -1;
}

int VerificarPalavra(char* palavra, automato a, int count){


    int estadoAtual=0;
    int TamP= std::strlen(palavra);
    

    for (int countP = 0; countP < TamP; countP++)
    {
        if (countP==0)
        {   
            if (verificadorInit(a.iniciais,palavra)==-1)
            {
                std::cout<<"Estado inicial inexistente"<<std::endl;
                return 1;
            }else{
                std::cout<<"Estado inicial encontrado"<<std::endl;

                if (verificador(a,palavra,countP,count,estadoAtual)==-1)
                {
                    std::cout<<"Função transição de q0 nao encontrada"<<std::endl;
                    return 1;
                }else{
                    int iterador=verificador(a,palavra,countP,count,estadoAtual);
                    std::cout<<"q0 para q"<<a.funcs[iterador].estadoFinal<<std::endl;
                    estadoAtual=a.funcs[iterador].estadoFinal;
               }
            }
            
        }else if (countP==TamP-1)
        {
             if (verificadorFim(a.finais,palavra,countP)==-1)
            {
                std::cout<<"Estado final inexistente"<<std::endl;
                return 1;
            }else{
                std::cout<<"Estado final existente"<<std::endl;
                return 0;
            }
        }else
        {
          if (verificador(a,palavra,countP,count,estadoAtual)==-1)
            {
                std::cout<<"Função transição de q"<<estadoAtual<<" nao encontrada"<<std::endl;
                return 1;
            }else{
                int iterador=verificador(a,palavra,countP,count,estadoAtual);
                std::cout<<"q"<<estadoAtual<<" para q"<<a.funcs[iterador].estadoFinal<<std::endl;
                estadoAtual=a.funcs[iterador].estadoFinal;
            }
        } 
    }
    return 1;
}