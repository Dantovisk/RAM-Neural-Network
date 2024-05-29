#include <bits/stdc++.h>

using namespace std;

void jogoParaUsuario(){
    short int resposta[4];
    bool ganhou = false;
    short int chute[4];
    multiset <int> temp;
    char feedback[4];
    int nRodadas = 0;

    srand(time(0));

    for (int i = 0; i < 4; i++) {
        resposta[i] = (rand() % 8);
    }
    
    /*
    cout << "Valores gerados para resposta: ";
    for (int i = 0; i < 4; i++) {
        cout << resposta[i] << " ";
    }*/

    cout << endl;
    while(!ganhou){
        nRodadas++;
        int cont = 0;
        cout<<"Digite 4 numeros de 0 a 7\n";
        for(int i=0; i<4; i++){        
            cin>>chute[i];
            temp.insert(resposta[i]);
        }
        for(int i=0; i<4; i++){
            if(chute[i]==resposta[i]){
                auto ptr = temp.find(chute[i]);
                feedback[i] = 'C';
                chute[i]= -1;
                temp.erase(ptr);
                cont++;
            }
        }

        for(int i=0; i<4; i++){
            if(chute[i]!=-1){
                auto ptr = temp.find(chute[i]);
                if(ptr != temp.end()){
                    feedback[i] = '?';
                    chute[i]= -1;
                    temp.erase(ptr);
                }
                else{
                    feedback[i] = 'X';
                    chute[i]= -1;
                }
            }    
        }
        temp.clear();
        for(int i=0; i<4; i++){
            cout<<feedback[i]<<" ";
        }
        cout<<"\n";
        if(cont == 4){
            cout<<"VOCE GANHOU!\n";
            cout<<"N° de rodadas: "<<nRodadas<<"\n";
            ganhou = true;
        }
    }
}

int main(){
    
    jogoParaUsuario();


    return 0;
}