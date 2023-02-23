#include "Aeroporto.hpp"

Aeroporto::Aeroporto(){
    this->pista1= new Pista();
    this->pista2= new Pista();
    this->pista3= new PistaEmerg();
}

void Aeroporto::inserirAviaoAterrisagemAero1(int id, int numeroPassageiros, float timer, string comapanhiaAerea, bool emerg){
    
    if (emerg==true)
    {
        int menor=pista1->getAuxTamanhoPistaAte1();

        if(pista2->getAuxTamanhoPistaAte1()<menor)
            menor=pista2->getAuxTamanhoPistaAte1();
        if(pista3->getAuxTamanhoPistaEmerg()<menor)
            menor=pista3->getAuxTamanhoPistaEmerg();

        if(menor==pista1->getAuxTamanhoPistaAte1()){
            if (pista1->sizeAte1()>pista1->sizeAte2())
            {
                pista1->inserirAviaoAterrisagem2(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
            }else{
                pista1->inserirAviaoAterrisagem1(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
            }
            pista1->setAuxTamanhoPistaAte1(pista1->sizeAte1()+pista1->sizeAte2());
        }else if(menor==pista2->getAuxTamanhoPistaAte1()){
            if (pista2->sizeAte1()>pista2->sizeAte2())
            {
                pista2->inserirAviaoAterrisagem2(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
            }else{
                pista2->inserirAviaoAterrisagem1(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
            }
            pista2->setAuxTamanhoPistaAte1(pista2->sizeAte1()+pista2->sizeAte2());
        }else{
            pista3->inserirAviaoPistaEmerg(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
            pista3->setAuxTamanhoPistaEmerg(pista3->sizeEmerg());}

    
    } else if (pista1->getAuxTamanhoPistaAte1() > pista2->getAuxTamanhoPistaAte1())
    {
        if (pista2->sizeAte1()>pista2->sizeAte2())
        {
            pista2->inserirAviaoAterrisagem2(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
        }else
            pista2->inserirAviaoAterrisagem1(id,numeroPassageiros,timer,comapanhiaAerea,emerg);

        pista2->setAuxTamanhoPistaAte1(pista2->sizeAte1()+pista2->sizeAte2());
        /*cout<<endl<<"AVIOES NA PISTA 1: "<<pista1->sizeAte1()<<" e "<<pista1->sizeAte2()<<" TOTAL: "<<pista1->getAuxTamanhoPistaAte1()<<endl;
        cout<<endl<<"AVIOES NA PISTA 2: "<<pista2->sizeAte1()<<" e "<<pista2->sizeAte2()<<" TOTAL: "<<pista2->getAuxTamanhoPistaAte1()<<endl;*/
    }else{
        if (pista1->sizeAte1()>pista1->sizeAte2())
        {
            pista1->inserirAviaoAterrisagem2(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
        }else{
            pista1->inserirAviaoAterrisagem1(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
        }
        pista1->setAuxTamanhoPistaAte1(pista1->sizeAte1()+pista1->sizeAte2());
       /* cout<<endl<<"AVIOES NA PISTA 1: "<<pista1->sizeAte1()<<" e "<<pista1->sizeAte2()<<" TOTAL: "<<pista1->getAuxTamanhoPistaAte1()<<endl;
        cout<<endl<<"AVIOES NA PISTA 2: "<<pista2->sizeAte1()<<" e "<<pista2->sizeAte2()<<" TOTAL: "<<pista2->getAuxTamanhoPistaAte1()<<endl;*/
    }

}

void Aeroporto::inserirAviaoDecolagemAero(int id, int numeroPassageiros, float timer, string comapanhiaAerea, bool emerg){
    int menor=pista1->getAuxTamanhoPistaDec();

    if(pista2->getAuxTamanhoPistaDec()<menor)
        menor=pista2->getAuxTamanhoPistaDec();
    if(pista3->getAuxTamanhoPistaEmerg()<menor)
        menor=pista3->getAuxTamanhoPistaEmerg();

    if(menor==pista1->getAuxTamanhoPistaDec()){
        pista1->inserirAviaoDecolagem(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
        pista1->setAuxTamanhoPistaDec(pista1->sizeDec());}
    else if(menor==pista2->getAuxTamanhoPistaDec()){
        pista2->inserirAviaoDecolagem(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
        pista2->setAuxTamanhoPistaDec(pista2->sizeDec());}
    else{
        pista3->inserirAviaoPistaEmerg(id,numeroPassageiros,timer,comapanhiaAerea,emerg);
        pista3->setAuxTamanhoPistaEmerg(pista3->sizeEmerg());}

   /* cout<<endl<<"AVIOES NA PISTA 1 DEC: "<<pista1->getAuxTamanhoPistaDec()<<endl;
    cout<<endl<<"AVIOES NA PISTA 2 DEC: "<<pista2->getAuxTamanhoPistaDec()<<endl;
    cout<<endl<<"AVIOES NA PISTA 3 DEC: "<<pista3->getAuxTamanhoPistaEmerg()<<endl; */
}

/*void Aeroporto::removerAviaoDecolagemAero(){ 
    if (pista1->emptyDec())
    {
        cout<<"Vazia"<<endl;
    }else
        pista1->removerAviaoDecolagem();
}

void Aeroporto::removerAviaoAterrisagemAero1(){
    if (pista1->emptyAte1())
    {
        cout<<"Vazia"<<endl;
    }else
        pista1->removerAviaoAterrisagem1();
}

void Aeroporto::removerAviaoAterrisagemAero2(){
    if (pista1->emptyAte2())
    {
        cout<<"Vazia"<<endl;
    }else
        pista1->removerAviaoAterrisagem2();
}

void Aeroporto::removerAviaoEmerg(){
    if (pista3->emptyEmerg())
    {
        cout<<"Vazia"<<endl;
    }else
        pista3->removerAviaoPistaEmerg();
}*/

void Aeroporto::realizarAcao(){
//pista1
    cout<<endl<<"-----PISTA 1-----"<<endl;
    if (pista1->emptyDec())
    {
        if(pista1->timerPrimAte1()>pista1->timerPrimAte2())
        {
            if (!pista1->emptyAte2())
            {
                pista1->removerAviaoAterrisagem2();
            }else{
                cout<<"Sem avioes."<<endl;
                if (!pista1->emptyAte1())
                {
                    pista1->removerAviaoAterrisagem1();
                }  
            }
        }else{
            if (!pista1->emptyAte1())
            {
                pista1->removerAviaoAterrisagem1();
            }else{
                cout<<"Sem avioes."<<endl;
                if (!pista1->emptyAte2())
                {
                    pista1->removerAviaoAterrisagem2();
                }
            }
        }
    }
    else if ((pista1->emptyAte1() && pista1->emptyAte2())||
    (pista1->emptyAte1() && pista1->timerPrimDec()<pista1->timerPrimAte2())||
    (pista1->emptyAte2() && pista1->timerPrimDec()<pista1->timerPrimAte1()))
    {
        pista1->removerAviaoDecolagem();
    }
    else if (pista1->timerPrimDec()<pista1->timerPrimAte1() && pista1->timerPrimDec()<pista1->timerPrimAte2())
    {
        if (!pista1->emptyDec())
        {
            pista1->removerAviaoDecolagem();
        }else{
            cout<<"Sem avioes."<<endl;
            if(pista1->timerPrimAte1()>pista1->timerPrimAte2())
            {
                if (!pista1->emptyAte2())
                {
                    pista1->removerAviaoAterrisagem2();
                }else{
                    cout<<"Sem avioes."<<endl;
                    if (!pista1->emptyAte1())
                    {
                        pista1->removerAviaoAterrisagem1();
                    }  
                }
            }else{
                if (!pista1->emptyAte1())
                {
                    pista1->removerAviaoAterrisagem1();
                }else{
                    cout<<"Sem avioes."<<endl;
                    if (!pista1->emptyAte2())
                    {
                        pista1->removerAviaoAterrisagem2();
                    }
                }
            }
        }
    }else if(pista1->timerPrimAte1()>pista1->timerPrimAte2())
    {
        if (!pista1->emptyAte2())
        {
            pista1->removerAviaoAterrisagem2();
        }else{
            cout<<"Sem avioes."<<endl;
            if (!pista1->emptyAte1())
            {
                pista1->removerAviaoAterrisagem1();
            }  
        }
    }else{
        if (!pista1->emptyAte1())
        {
            pista1->removerAviaoAterrisagem1();
        }else{
            cout<<"Sem avioes."<<endl;
            if (!pista1->emptyAte2())
            {
                pista1->removerAviaoAterrisagem2();
            }
        }
    }
//pista2
    cout<<endl<<"-----PISTA 2-----"<<endl;
    if (pista2->emptyDec())
    {
        if(pista2->timerPrimAte1()>pista2->timerPrimAte2())
        {
            if (!pista2->emptyAte2())
            {
                pista2->removerAviaoAterrisagem2();
            }else{
                cout<<"Sem avioes."<<endl;
                if (!pista2->emptyAte1())
                {
                    pista2->removerAviaoAterrisagem1();
                }
            }
            
        }else{
            if (!pista2->emptyAte1())
            {
                pista2->removerAviaoAterrisagem1();
            }else{
                cout<<"Sem avioes."<<endl;
                if (!pista2->emptyAte2())
                {
                    pista2->removerAviaoAterrisagem2();
                }
            }
        }
    }
    else if ((pista2->emptyAte1() && pista2->emptyAte2())||
    (pista2->emptyAte1() && pista2->timerPrimDec()<pista2->timerPrimAte2())||
    (pista2->emptyAte2() && pista2->timerPrimDec()<pista2->timerPrimAte1()))
    {
        pista2->removerAviaoDecolagem();
    }
    else if (pista2->timerPrimDec()<pista2->timerPrimAte1() && pista2->timerPrimDec()<pista2->timerPrimAte2())
    {
        if (!pista2->emptyDec())
        {
            pista2->removerAviaoDecolagem();
        }else{
            cout<<"Sem avioes."<<endl;

            if(pista2->timerPrimAte1()>pista2->timerPrimAte2())
            {
                if (!pista2->emptyAte2())
                {
                    pista2->removerAviaoAterrisagem2();
                }else{
                    cout<<"Sem avioes."<<endl;
                    if (!pista2->emptyAte1())
                    {
                        pista2->removerAviaoAterrisagem1();
                    }
                }
                
            }else{
                if (!pista2->emptyAte1())
                {
                    pista2->removerAviaoAterrisagem1();
                }else{
                    cout<<"Sem avioes."<<endl;
                    if (!pista2->emptyAte2())
                    {
                        pista2->removerAviaoAterrisagem2();
                    }
                }
            }
        }
    }else if(pista2->timerPrimAte1()>pista2->timerPrimAte2())
    {
        if (!pista2->emptyAte2())
        {
            pista2->removerAviaoAterrisagem2();
        }else{
            cout<<"Sem avioes."<<endl;
            if (!pista2->emptyAte1())
            {
                pista2->removerAviaoAterrisagem1();
            }
        }
        
    }else{
        if (!pista2->emptyAte1())
        {
            pista2->removerAviaoAterrisagem1();
        }else{
            cout<<"Sem avioes."<<endl;
            if (!pista2->emptyAte2())
            {
                pista2->removerAviaoAterrisagem2();
            }
        }
    }
//pista3
    cout<<endl<<"-----PISTA 3-----"<<endl;
    if (!pista3->emptyEmerg())
    {
        pista3->removerAviaoPistaEmerg();
    }else
        cout<<"Sem avioes."<<endl;

}

void Aeroporto::imprimirDadosAero(){
    cout<<endl<<"-----PISTA 1-----"<<endl;
    pista1->imprimirDados();
    cout<<"----------"<<endl;
    cout<<endl<<"-----PISTA 2-----"<<endl;
    pista2->imprimirDados();
    cout<<"----------"<<endl;
    cout<<endl<<"-----PISTA 3-----"<<endl;
    pista3->imprimirDados();
    cout<<"----------"<<endl;
}

void Aeroporto::medias(){
    cout<<endl<<"-----PISTA 1-----"<<endl;
    pista1->mediaPistaAterrisagem1();
    pista1->mediaPistaAterrisagem2();
    pista1->mediaPistaDecolagem();
    cout<<endl<<"-----PISTA 2-----"<<endl;
    pista2->mediaPistaAterrisagem1();
    pista2->mediaPistaAterrisagem2();
    pista2->mediaPistaDecolagem();
    cout<<endl<<"-----PISTA 3-----"<<endl;
    pista3->mediaPistaEmerg();

    cout<<endl;
}

void Aeroporto::mediaGlobal(){
    float media=0;
        media=(pista1->mediaPistaAterrisagem1()+pista1->mediaPistaAterrisagem2()+pista1->mediaPistaDecolagem()+
        pista2->mediaPistaAterrisagem1()+pista2->mediaPistaAterrisagem2()+pista2->mediaPistaDecolagem()+
        pista3->mediaPistaEmerg())/3;
        cout<<"MEDIA GLOBAL: "<<media<<endl;
}

void Aeroporto::pousosEmergenciais(){
    cout<<endl<<"-----PISTA 1-----"<<endl;
    pista1->aterrisagensEmergenciais1();
    pista1->aterrisagensEmergenciais2();

    cout<<endl<<"-----PISTA 2-----"<<endl;
    pista2->aterrisagensEmergenciais1();
    pista2->aterrisagensEmergenciais2();

    cout<<endl<<"-----PISTA 3-----"<<endl;
    pista3->aterrisagensEmergenciais();
}

void Aeroporto::EmergenciaGlobal(){
    int total=0;
    total=(pista1->aterrisagensEmergenciais1()+pista1->aterrisagensEmergenciais2()
    +pista2->aterrisagensEmergenciais1()+pista2->aterrisagensEmergenciais2()
    +pista3->aterrisagensEmergenciais());
    cout<<endl<<"POUSOS EMERGENCIAIS REALIZADOS NO AEROPORTO: "<<total<<endl;
}

void Aeroporto::decrementarMinutos(){
    pista1->decrementarTimer();
    pista2->decrementarTimer();
    pista3->decrementarTimeEmerg();
}