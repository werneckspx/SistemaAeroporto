#include <iostream>
#include "Aviao.hpp"

Aviao::Aviao(int id, int numeroPassageiros, float timer, string companhiaAerea, bool emerg){
    setId(id);
    setNumeroPassageiros(numeroPassageiros);
    setTimer(timer);
    setEmergencia(emerg);
    setCompanhiaAerea(companhiaAerea);
}

Aviao::Aviao(){

}

void Aviao::imprimir(){
    cout<<"----------"<<endl;
    cout<<"ID: "<<id<<endl
    <<"Tempo: "<<timer<<endl
    <<"Companhia aerea: "<<companhiaAerea<<endl
    <<"Numero de passageiros: "<<numeroPassageiros<<endl
    <<"Estado: "<<emerg<<endl;
    cout<<"----------"<<endl;
}

int Aviao::getId(){
    return id;
}

void Aviao::setId(int id){
    this->id=id;
}

int Aviao::getNumeroPassegeiros(){
    return numeroPassageiros;
}

void Aviao::setNumeroPassageiros(int numeroPassageiros){
    this->numeroPassageiros=numeroPassageiros;
}

float Aviao::getTimer(){
    return timer;
}

void Aviao::setTimer(float timer){
    this->timer=timer;
}

bool Aviao::getEmergencia(){
    return emerg;
}

void Aviao::setEmergencia(bool emerg){
    this->emerg=emerg;
}

string Aviao::getCompanhiaAerea(){
    return companhiaAerea;
}

void Aviao::setCompanhiaAerea(string companhiaAerea){
    this->companhiaAerea=companhiaAerea;
}