#include "recognize.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include "preprocess.hpp"
#include "config.hpp"

using namespace std;

void reconhecerImagem(const vector<vector<vector<bool>>>& neuronios, const vector<bool>& imagemFlat, const vector<int>& indices) {
    vector<int> contadores(10, 0);
    int contador = 0;
    for (int i = 0; i < USED_HEIGHT * USED_WIDTH -2; i += 3) {
        int n1 = (imagemFlat[indices[i]] == true ? 1 : 0);
        int n2 = (imagemFlat[indices[i + 1]] == true ? 1 : 0);
        int n3 = (imagemFlat[indices[i + 2]] == true ? 1 : 0);

        
        for (int j = 0; j < 10; j++) {
            if (neuronios[j][i / 3][n1 * 4 + n2 * 2 + n3] == true) {
                contadores[j]+= 1+ 5 *(n1 + n2 + n3); 
                contador+= 1 + 5*(n1 + n2 + n3); 
            } else{
                contador-=3;
                contadores[j]-=3;
            }
        }
    }
    vector <pair<int,int>> colocacoes(10);
    for(int j=0; j<10; j++){
        colocacoes[j] = make_pair(contadores[j],j);
    }
    sort(colocacoes.begin(),colocacoes.end());

    
    for (int j = 0; j < 10; j++) {
        float chance = contadores[j];
        chance /= contador;
        chance *= 100;
        cout << "Chance de ser o numero " << j << ": " << chance << "%\n";
    }
    cout<<"Numero mais provavel: "<<colocacoes[9].second<<"\n";
    cout<<"O segundo mais provavel eh: "<<colocacoes[8].second<<"\n";
}