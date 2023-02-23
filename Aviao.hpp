#ifndef AVIAO_HPP
#define AVIAO_HPP
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

class Aviao{
    private:
    int id, numeroPassageiros;
    float timer;
    string companhiaAerea;
    bool emerg;

    public:

    Aviao();

    Aviao(int id, int numeroPassageiros, float timer, string companhiaAerea, bool emerg);

    void imprimir();

    int getId();
    void setId(int id);

    int getNumeroPassegeiros();
    void setNumeroPassageiros(int numeroPassageiros);

    float getTimer();
    void setTimer(float timer);

    bool getEmergencia();
    void setEmergencia(bool emerg);

    string getCompanhiaAerea();
    void setCompanhiaAerea(string companhiaAerea);
};
#endif