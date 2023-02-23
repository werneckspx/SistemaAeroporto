#include "PistaEmerg.hpp"

PistaEmerg::PistaEmerg(){

}

void PistaEmerg::inserirAviaoPistaEmerg(int id, int numeroPassageiros, float timer, string comapanhiaAerea, bool emerg){
    Aviao a(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
    pistaEmerg.push(a);
}

void PistaEmerg::removerAviaoPistaEmerg(){
    cout<<endl<<"AVIAO REALIZANDO ATERRISAGEM/DECOLAGEM: "<<endl;
    Aviao aAux;
    aAux = pistaEmerg.top();
    aAux.imprimir();
    pistaEmerg.pop();
}

void PistaEmerg::imprimirDados(){
    cout<<endl<<"Avioes na fila emergencial"<<endl;
    Aviao aAux;
    priority_queue <Aviao, vector<Aviao>, CompEmerg>pistaEmergaux = pistaEmerg;  
    while (!pistaEmergaux.empty())  
    {  
        aAux = pistaEmergaux.top();
        aAux.imprimir();  
        pistaEmergaux.pop();  
    }
}

float PistaEmerg::mediaPistaEmerg(){
    float media=0;
    int cont=0;
    Aviao aAux;
    if (pistaEmerg.empty())
    {
        cout<<"PISTA EMERGENCIAL VAZIA"<<endl;
    }else{
        priority_queue <Aviao, vector<Aviao>, CompEmerg> pistaEmergaux = pistaEmerg;  
        while (!pistaEmergaux.empty())
        {  
            aAux = pistaEmergaux.top();
            media+= aAux.getTimer();  
            pistaEmergaux.pop();
            cont++;
        }
        media=media/cont;
        cout<<"MEDIA DEC: "<<media<<endl;
    }

    return media;
}


int PistaEmerg::aterrisagensEmergenciais(){
    int cont=0;
    Aviao aAux;
    priority_queue <Aviao, vector<Aviao>, CompEmerg> pistaEmergaux = pistaEmerg;  
    while (!pistaEmergaux.empty())
    {  
        aAux = pistaEmergaux.top();
        if (aAux.getEmergencia()==true)
        {
            cont++;
        }
        pistaEmergaux.pop();
    }
    if (cont>=3)
    {
        cout<<endl<<"ESTADO CRITICO!!! PISTA EMERGENCIAL LOTADA("<<cont<<")"<<endl;
    }
    
    return cont;
}

void PistaEmerg::decrementarTimeEmerg(){
    Aviao aAux;
    priority_queue <Aviao, vector<Aviao>, CompEmerg> pistaaux1 = pistaEmerg;
    priority_queue <Aviao, vector<Aviao>, CompEmerg> pistaaux2;
    while (!pistaaux1.empty())  
    {   
        aAux= pistaaux1.top();
        if (aAux.getTimer()<=15)
        {
            aAux.setTimer(aAux.getTimer()-1);
        }
        pistaaux2.push(aAux);
        pistaaux1.pop();
    }
    pistaEmerg = pistaaux2;
}

bool PistaEmerg::emptyEmerg(){
    return pistaEmerg.empty();
}

int PistaEmerg::sizeEmerg(){
    return pistaEmerg.size();
}

int PistaEmerg::getAuxTamanhoPistaEmerg(){
    return auxTamanhoPistaEmerg;
}

void PistaEmerg::setAuxTamanhoPistaEmerg(int auxTamanhoPistaEmerg){
    this->auxTamanhoPistaEmerg= auxTamanhoPistaEmerg;
}
