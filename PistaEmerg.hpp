#ifndef PISTAEMERG_HPP
#define PISTAEMERG_HPP
#include "Aviao.hpp"

using namespace std;

struct CompEmerg {
         bool operator()(Aviao &av1, Aviao &av2) {
            if (!av1.getEmergencia() && av2.getEmergencia())
                return true;
            return false;
         }
    };

class PistaEmerg
{
private:
    priority_queue<Aviao, vector<Aviao>, CompEmerg> pistaEmerg; 
    int auxTamanhoPistaEmerg=0;

public:
   
   PistaEmerg();

    void inserirAviaoPistaEmerg(int id, int numeroPassageiros, float timer, string comapanhiaAerea, bool emerg);
    void removerAviaoPistaEmerg();
    void imprimirDados();

    float mediaPistaEmerg();

    int aterrisagensEmergenciais();
   
    bool emptyEmerg();

    int sizeEmerg();

    void decrementarTimeEmerg();

    int getAuxTamanhoPistaEmerg();
    void setAuxTamanhoPistaEmerg(int auxTamanhoPistaEmerg);

};

#endif