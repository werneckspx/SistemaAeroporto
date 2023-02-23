#ifndef AEROPORTO_HPP
#define AEROPORTO_HPP
#include "Pista.hpp"
#include "PistaEmerg.hpp"

using namespace std;

class Aeroporto
{
private:
    Pista *pista1;
    Pista *pista2;
    PistaEmerg *pista3;
    
public:
    Aeroporto();

    void inserirAviaoDecolagemAero(int id, int numeroPassageiros, float timer, string comapanhiaAerea, bool emerg);
    void inserirAviaoAterrisagemAero1(int id, int numeroPassageiros, float timer, string comapanhiaAerea, bool emerg);

    /*void removerAviaoDecolagemAero();
    void removerAviaoAterrisagemAero1();
    void removerAviaoAterrisagemAero2();
    void removerAviaoEmerg();*/

    void realizarAcao();
    void imprimirDadosAero();
    void medias();
    void mediaGlobal();
    void pousosEmergenciais();
    void EmergenciaGlobal();
    void decrementarMinutos();

};

#endif