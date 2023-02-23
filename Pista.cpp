#include "Pista.hpp"

Pista::Pista(){

}

void Pista::inserirAviaoDecolagem(int id, int numeroPassageiros, float timer, string companhiaAerea, bool emerg){
    Aviao a= Aviao(id,numeroPassageiros,timer,companhiaAerea,emerg);
    pistaDec.push(a);
}

void Pista::inserirAviaoAterrisagem1(int id, int numeroPassageiros, float timer, string companhiaAerea, bool emerg){
    Aviao a(id,numeroPassageiros,timer,companhiaAerea,emerg);
    pistaAte1.push(a);
}

void Pista::inserirAviaoAterrisagem2(int id, int numeroPassageiros, float timer, string companhiaAerea, bool emerg){
    Aviao a(id,numeroPassageiros,timer,companhiaAerea,emerg);
    pistaAte2.push(a);
}

void Pista::removerAviaoDecolagem(){
    cout<<endl<<"AVIAO REALIZANDO DECOLAGEM: "<<endl;
    pistaDec.front().imprimir();
    pistaDec.pop();
}
void Pista::removerAviaoAterrisagem1(){
    cout<<endl<<"AVIAO REALIZANDO ATERRISAGEM: "<<endl;
    Aviao aAux;
    aAux = pistaAte1.top();
    aAux.imprimir();
    pistaAte1.pop();
}

void Pista::removerAviaoAterrisagem2(){
    cout<<endl<<"AVIAO REALIZANDO ATERRISAGEM: "<<endl;
    Aviao aAux;
    aAux = pistaAte2.top();
    aAux.imprimir();
    pistaAte2.pop();
}

void Pista::imprimirDados(){
    cout<<endl<<"Avioes na fila para decolagem"<<endl;
    Aviao aAux1;
    Aviao aAux2;
    queue <Aviao> pistaaux = pistaDec;  
    while (!pistaaux.empty())  
    {  
        pistaaux.front().imprimir();  
        pistaaux.pop();  
    }
    cout<<endl<<"Avioes na fila para aterrisagem 1"<<endl;
    priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux1 = pistaAte1;  
    while (!pistaaux1.empty())  
    {  
        aAux1 = pistaaux1.top();
        aAux1.imprimir();  
        pistaaux1.pop();   
    }
    cout<<endl<<"Avioes na fila para aterrisagem 2"<<endl;
    priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux2 = pistaAte2;  
    while (!pistaaux2.empty())  
    {  
        aAux2 = pistaaux2.top();
        aAux2.imprimir();  
        pistaaux2.pop();  
    }
}

float Pista::mediaPistaDecolagem(){
    float media=0;
    int cont=0;
    if (pistaDec.empty())
    {
        cout<<"PISTA DECOLAGEM VAZIA"<<endl;
    }else{
        queue <Aviao> pistaaux = pistaDec;  
        while (!pistaaux.empty())
        {  
            media+= pistaaux.front().getTimer();  
            pistaaux.pop();
            cont++;
        }
        media=media/cont;
        cout<<"MEDIA DECOLAGEM: "<<media<<endl;
    }

    return media;
}

float Pista::mediaPistaAterrisagem1(){
    float media=0;
    int cont=0;
    Aviao aAux;
    if (pistaAte1.empty())
    {
        cout<<"PISTA ATERRISAGEM VAZIA"<<endl;
    }else{
        priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux = pistaAte1;  
        while (!pistaaux.empty())
        {  
            aAux = pistaaux.top();
            media+= aAux.getTimer();  
            pistaaux.pop();
            cont++;
        }
        media=media/cont;
        cout<<"MEDIA ATE1: "<<media<<endl;
    }

    return media;
}


float Pista::mediaPistaAterrisagem2(){
    float media=0;
    int cont=0;
    Aviao aAux;
    if (pistaAte2.empty())
    {
        cout<<"PISTA ATERRISAGEM VAZIA"<<endl;
    }else{
        priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux = pistaAte2;  
        while (!pistaaux.empty())
        {  
            aAux = pistaaux.top();
            media+= aAux.getTimer();  
            pistaaux.pop();
            cont++;
        }
        media=media/cont;
        cout<<"MEDIA ATE2: "<<media<<endl;
    }

    return media;
}

int Pista::aterrisagensEmergenciais1(){
    int cont=0;
    Aviao aAux;
    priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux = pistaAte1;  
    while (!pistaaux.empty())
    {  
        aAux = pistaaux.top();
        if (aAux.getEmergencia()==true)
        {
            cont++;
        }
        pistaaux.pop();
    }
    //cout<<endl<<"POUSOS EMERGENCIAIS REALIZADOS PISTA ATERRISAGEM 1: "<<cont<<endl;
    return cont;
}

int Pista::aterrisagensEmergenciais2(){
    int cont=0;
    Aviao aAux;
    priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux = pistaAte2;  
    while (!pistaaux.empty())
    {  
        aAux = pistaaux.top();
        if (aAux.getEmergencia()==true)
        {
            cont++;
        }
        pistaaux.pop();
    }
    //cout<<endl<<"POUSOS EMERGENCIAIS REALIZADOS PISTA ATERRISAGEM 1: "<<cont<<endl;
    return cont;   
}

bool Pista::emptyAte1(){
    return pistaAte1.empty();
}

bool Pista::emptyAte2(){
    return pistaAte2.empty();
}

bool Pista::emptyDec(){
    return pistaDec.empty();
}

int Pista::sizeAte1(){
    return pistaAte1.size();
}

int Pista::sizeAte2(){
    return pistaAte2.size();
}

int Pista::sizeDec(){
    return pistaDec.size();
}

int Pista::getAuxTamanhoPistaAte1(){
    return auxTamanhoPistaAte1;
}

float Pista::timerPrimAte1(){
    float menor=0;
    Aviao aAux;
    if (pistaAte1.empty())
    {
        cout<<"PISTA ATERRISSAGEM VAZIA"<<endl;
        menor=0;
    }else{
        priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux = pistaAte1;  
        aAux = pistaaux.top();
        menor= aAux.getTimer();  
    }

    return menor;
}

float Pista::timerPrimAte2(){
    float menor=0;
    Aviao aAux;
    if (pistaAte2.empty())
    {
        cout<<"PISTA ATERRISSAGEM VAZIA"<<endl;
        menor=0;
    }else{
        priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux = pistaAte2;  
        aAux = pistaaux.top();
        menor= aAux.getTimer();  
    }

    return menor;
}

float Pista::timerPrimDec(){
    float menor=0;
    if (pistaDec.empty())
    {
        cout<<"PISTA DECOLAGEM VAZIA"<<endl;
    }else{
        queue <Aviao> pistaaux = pistaDec;  
        menor= pistaaux.front().getTimer();  
    }
    return menor;    
}

void Pista::setAuxTamanhoPistaAte1(int auxTamanhoPistaAte1){
    this->auxTamanhoPistaAte1= auxTamanhoPistaAte1;
}

int Pista::getAuxTamanhoPistaAte2(){
    return auxTamanhoPistaAte2;
}

void Pista::setAuxTamanhoPistaAte2(int auxTamanhoPistaAte2){
    this->auxTamanhoPistaAte2= auxTamanhoPistaAte2;
}

int Pista::getAuxTamanhoPistaDec(){
    return auxTamanhoPistaDec;
}

void Pista::setAuxTamanhoPistaDec(int auxTamanhoPistaDec){
    this->auxTamanhoPistaDec= auxTamanhoPistaDec;
}

void Pista::decrementarTimer(){

    /*Aviao aAux1;
    queue <Aviao> pistaaux1 = pistaDec;  
    queue <Aviao> pistaaux2; 
    while (!pistaaux1.empty())  
    {  
        aAux1= pistaaux1.front();
        aAux1.setTimer(aAux1.getTimer()-1);
        if (aAux1.getTimer()<15)
        {
            aAux1.setEmergencia(true);
        }
        pistaaux2.push(aAux1);
        pistaaux1.pop();
    }
    pistaDec = pistaaux2;*/

    
    Aviao aAux2;
    priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux3 = pistaAte1;
    priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux4;
    while (!pistaaux3.empty())  
    {  
        aAux2= pistaaux3.top();
        aAux2.setTimer(aAux2.getTimer()-1);
        if (aAux2.getTimer()<15)
        {
            aAux2.setEmergencia(true);
        }
        
        pistaaux4.push(aAux2);
        pistaaux3.pop();
    }
    pistaAte1 = pistaaux4;


    Aviao aAux3;
    priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux5 = pistaAte2;
    priority_queue <Aviao, vector<Aviao>, CompEmergPista> pistaaux6;
    while (!pistaaux5.empty())  
    {  
        aAux3= pistaaux5.top();
        aAux3.setTimer(aAux3.getTimer()-1);
        if (aAux3.getTimer()<15)
        {
            aAux3.setEmergencia(true);
        }
        pistaaux6.push(aAux3);
        pistaaux5.pop();
    }
    pistaAte2 = pistaaux6;
}