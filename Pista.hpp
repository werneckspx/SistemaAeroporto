#ifndef PISTA_HPP
#define PISTA_HPP
#include "Aviao.hpp"

using namespace std;

struct CompEmergPista {
         bool operator()(Aviao &av1, Aviao &av2) {
            if (!av1.getEmergencia() && av2.getEmergencia())
                return true;
            return false;
         }
    };

class Pista
{
private:
    queue<Aviao> pistaDec;
    priority_queue<Aviao, vector<Aviao>, CompEmergPista> pistaAte1; 
    priority_queue<Aviao, vector<Aviao>, CompEmergPista> pistaAte2; 
    int auxTamanhoPistaAte1=0,auxTamanhoPistaAte2=0,auxTamanhoPistaDec=0;

public: 
   
   Pista();

   void inserirAviaoDecolagem(int id, int numeroPassageiros, float timer, string comapanhiaAerea, bool emerg);
   void inserirAviaoAterrisagem1(int id, int numeroPassageiros, float timer, string comapanhiaAerea, bool emerg);
   void inserirAviaoAterrisagem2(int id, int numeroPassageiros, float timer, string comapanhiaAerea, bool emerg);

   void removerAviaoDecolagem();
   void removerAviaoAterrisagem1();
   void removerAviaoAterrisagem2();

    void imprimirDados();

    float mediaPistaDecolagem();
    float mediaPistaAterrisagem1();
    float mediaPistaAterrisagem2();

    int aterrisagensEmergenciais1();
    int aterrisagensEmergenciais2();
   
    bool emptyAte1();
    bool emptyAte2();
    bool emptyDec();

    int sizeAte1();
    int sizeAte2();
    int sizeDec();

    float timerPrimAte1();
    float timerPrimAte2();
    float timerPrimDec();

    void decrementarTimer();

    int getAuxTamanhoPistaAte1();
    void setAuxTamanhoPistaAte1(int auxTamanhoPistaAte1);
    int getAuxTamanhoPistaAte2();
    void setAuxTamanhoPistaAte2(int auxTamanhoPistaAte2);
    int getAuxTamanhoPistaDec();
    void setAuxTamanhoPistaDec(int auxTamanhoPistaDec);
};

#endif