#include "Aeroporto.hpp"
using namespace std;

int main()
{
    //aterrisagem = 1, decolagem = 0 

    Aeroporto *aero = new Aeroporto();

    int id=0,idAuxAte=1,idAuxDec=2, numeroPassageiros=0,actionAviao=0,actionAviaoDec=0;
    float timer=0;
    string companhiaAerea;
    bool emerg=false;
    int contBuc=0,contDec = 0,contAte=0, numAvioes = 3, passa, op,continuar=0;
    int numAterrissagem=0, numDecolagem=0;
    float comb;
    srand(time(NULL));
    string filename("dadosAte.txt");
    string filename2("dadosDec.txt");
    vector<string> lines;
    vector<string> lines2;
    string line;
    ifstream input_file(filename,ios::in);
    ifstream input_file2(filename2,ios::in);
    int contAux=1,contAux2=1;
    int cont=0;
    int minutos=0;
    int help=0;

    vector<Aviao>avioes;
    vector<Aviao>avioesDec;
    
    int auxLeitura=0;
    cout<<"------INICIANDO AEROPORTO------"<<endl;
    cout<<"ESCOLHA COMO O AEROPORTO IRA RECEBER OS DADOS: "<<endl
    <<"1-PRE-SELECIONADO"<<endl<<"2-ALEATORIAMENTE"<<endl;
    cin>> auxLeitura;

    switch (auxLeitura)
    {
    case 1:

        if (!input_file.is_open()) {
            cout << "Nao foi possivel abrir o arquivo"
                << filename << " " << endl;
            return EXIT_FAILURE;
        }

        while (!input_file.eof())
        {
            while (getline(input_file, line,'\n')){
                lines.push_back(line);
                line.clear();
            } 
            
        }
        input_file.close();

        if (!input_file2.is_open()) {
            cout << "Nao foi possivel abrir o arquivo"
                << filename2 << " " << endl;
            return EXIT_FAILURE;
        }

        while (!input_file2.eof())
        {
            while (getline(input_file2, line,'\n')){
                lines2.push_back(line);
                line.clear();
            } 
            
        }
    
        input_file2.close();

        while(!lines.empty())
            {
                if (contAux==1)
                {
                    numeroPassageiros=atoi(lines[0].c_str());
                    lines.erase(lines.begin());
                        
                }else if(contAux==2){
                    timer=atof(lines[0].c_str());
                    if (timer<=15)
                    { 
                        emerg=true;
                    }else
                        emerg=false; 

                    lines.erase(lines.begin());

                }else if(contAux==3){
                    companhiaAerea=lines[0];
                    lines.erase(lines.begin());
                            
                            
                    id = idAuxAte;
                    idAuxAte= idAuxAte+2;
                    avioes.push_back(Aviao( idAuxAte,numeroPassageiros,timer,companhiaAerea,emerg));
                    contAux=0;
                            
                }
                contAux++;
            }

        contAux=1;
        while(!lines2.empty())
            {
                if (contAux==1)
                {
                    numeroPassageiros=atoi(lines2[0].c_str());
                    lines2.erase(lines2.begin());
                        
                }else if(contAux==2){
                    timer=atof(lines2[0].c_str()); 
                    if (timer<=15)
                    { 
                        emerg=true;
                    }else
                        emerg=false; 

                    lines2.erase(lines2.begin());

                }else if(contAux==3){
                    companhiaAerea=lines2[0];
                    lines2.erase(lines2.begin());
                            
                            
                    id = idAuxDec;
                    idAuxDec= idAuxDec+2;
                    avioesDec.push_back(Aviao( idAuxDec,numeroPassageiros,timer,companhiaAerea,emerg));
                    contAux=0;
                            
                }
                contAux++;
            }
        cont=0;
        do
        {
            if (!avioes.empty())
            {
                numAterrissagem = 0 + rand() % 4;
                cout<<"ATERRISSAGEM: "<<numAterrissagem<<endl<<endl;
                while (numAterrissagem>0 && !avioes.empty())
                {
                    aero->inserirAviaoAterrisagemAero1(avioes[0].getId(),avioes[0].getNumeroPassegeiros(),avioes[0].getTimer(),avioes[0].getCompanhiaAerea(),avioes[0].getEmergencia());
                    avioes.erase(avioes.begin());
                    numAterrissagem--;
                    cont++;
                }
            }   
            
            if (!avioesDec.empty())
            {
                numDecolagem = 0 + rand() % 4;
                cout<<"DECOLAGEM: "<<numDecolagem<<endl;
                while (numDecolagem>0 && !avioesDec.empty())
                {
                    
                    aero->inserirAviaoDecolagemAero(avioesDec[0].getId(),avioesDec[0].getNumeroPassegeiros(),avioesDec[0].getTimer(),avioesDec[0].getCompanhiaAerea(),avioesDec[0].getEmergencia());
                    avioesDec.erase(avioesDec.begin());
                    numDecolagem--;
                    cont++;
                               
                }
            }
            
           // cout<<"-----ENTRARAM "<< numDecolagem+numAterrissagem<<" AERONAVES-----"<<endl;
            
                aero->decrementarMinutos();
                aero->imprimirDadosAero();
                aero->EmergenciaGlobal();
                aero->mediaGlobal();
                aero->realizarAcao();
                minutos++;    
                cout<<"MINUTOS: "<<minutos<<endl;
                cout<<"QUANTIDA DE AVIOES: "<<cont<<endl;

        } while ((!avioes.empty())||(!avioesDec.empty()));
        
    break;
    
    case 2:
        do {
            numDecolagem = 0 + rand() % 4;
            numAterrissagem = 0 + rand() % 4;

            cout<<"deco"<<numDecolagem<<endl;
            cout<<"ate"<<numAterrissagem<<endl;

            for(int i=0;i<numAterrissagem;i++)
            {
                passa = 50 + rand() % 251;

                comb = 7 + rand() % 137;
                if (comb<15)
                {
                    emerg=true;
                }else
                    emerg=false;

                op = rand() % 4;

                if (op == 0)
                    companhiaAerea="LATAM";
                else if (op == 1)
                    companhiaAerea="AZUL";
                else if (op == 2)
                    companhiaAerea="GOL";   
                else
                    companhiaAerea="American Airlines";

                id = idAuxAte;
                idAuxAte= idAuxAte+2;
                aero->inserirAviaoAterrisagemAero1(id,passa,comb,companhiaAerea,emerg);
                cont++;
            }

            for(int i=0;i<numDecolagem;i++)
            {
                passa = 50 + rand() % 251;

                comb = 7 + rand() % 137;
                if (comb<15)
                {
                    emerg=true;
                }else
                    emerg=false;

                op = rand() % 4;

                if (op == 0)
                    companhiaAerea="LATAM";
                else if (op == 1)
                    companhiaAerea="AZUL";
                else if (op == 2)
                    companhiaAerea="GOL";   
                else
                    companhiaAerea="American Airlines";

                id = idAuxDec;
                idAuxDec = idAuxDec+2;
                aero->inserirAviaoDecolagemAero(id,passa,comb,companhiaAerea,emerg);
                cont++;
            }

                aero->decrementarMinutos();
                cout<<"-----ENTRARAM "<< numDecolagem+numAterrissagem<<" AERONAVES-----"<<endl;
                aero->imprimirDadosAero();
                aero->EmergenciaGlobal();
                aero->mediaGlobal();
                aero->realizarAcao();
                minutos++;

                cout<<"MINUTOS: "<<minutos<<endl;
                cout<<"QUANTIDA DE AVIOES: "<<cont<<endl;

                cout<<"1 para continuar/ outro numero para parar."<<endl;
                cin>>continuar;            
            }while(continuar==1);
        
        break;
    default:
        break;
        
    }
        
    return 0;
}