#include "automato.hpp"



int main(){

    automato a;
    int contador;
    char cond;
    char palavra[50]; 

    std::cout<<"Digite todos estados iniciais seguidos: (abcd) "<<std::endl;
    std::cin>>a.iniciais;

    std::cout<<"Digite todos estados finais seguidos: (abcd) "<<std::endl;
    std::cin>>a.finais;

    std::cout<<"Digite o numero de funcoes de transicao exceto as que levam para o estado final: "<<std::endl;
    std::cin>>contador;
  

    for (size_t i = 0; i < contador; i++)
    {
        std::cout<<"Digite o numero do estado atual: (q0=0,q1=1,q2=2,...) "<<std::endl;
        std::cin>>a.funcs[i].estadoAtual;
        std::cout<<"Digite o Valor: "<<std::endl;
        std::cin>>a.funcs[i].valor;
        std::cout<<"Digite o numero do estado final: (q0=0,q1=1,q2=2...)"<<std::endl;
        std::cin>>a.funcs[i].estadoFinal;
    }
    
    do
    {

        std::cout<<"Digite uma palavra para ser verificada: "<<std::endl;
        std::cin>>palavra;

        if(VerificarPalavra(palavra,a,contador)==0){
            std::cout<<"ACEITO"<<std::endl;
        }else{
            std::cout<<"REJEITADA"<<std::endl;
        };

        std::cout<<"Deseja verificar outra palavra? (s) // (n) "<<std::endl;
        std::cin>>cond;

    } while (cond=='s');
    

    return 0;
}