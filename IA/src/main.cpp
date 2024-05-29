#include <iostream>
#include <vector>
#include <string.h>
#include <random>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "config.hpp"
#include "preprocess.hpp"
#include "train.hpp"
#include "recognize.hpp"

using namespace std;


void saveVectorToFile(vector<vector<vector<bool>>>& neuronios, vector<int>& indices, const string& filename) {
    ofstream outFile(filename);
    
    if (!outFile) {
        cerr << "Erro ao abrir o arquivo para escrita: " << filename << endl;
        return;
    }

    outFile << USED_HEIGHT << " " << USED_WIDTH << "\n";

    for (int val : indices) {
        outFile << val << " ";
    }

    outFile <<"\n";

    for (vector<vector<bool>> val : neuronios) {
        for (vector<bool> val2 : val) {
            for (bool val3 : val2) {
                outFile << (val3?1:0) << " ";
            }
        }
    }

    outFile.close();
    if (!outFile) {
        cerr << "Erro ao fechar o arquivo: " << filename << endl;
    }
}


void treinarDataSet(const char filename[],  vector<vector<vector<bool>>>& neuronios, vector<int>& indices, vector<vector<bool>> booleanMatrix, int nTreinado){
    vector<bool> imagemFlat;
    if (carregaImagem(filename, USED_HEIGHT, USED_WIDTH, booleanMatrix)) {
        imagemFlat = preprocessarImagem(booleanMatrix);
        //PrintaImagem(booleanMatrix);
        treinarNeuronios(neuronios, imagemFlat, indices, nTreinado);
    }
}

int main() {
    string filename;
    vector<vector<bool>> booleanMatrix(USED_HEIGHT, vector<bool>(USED_WIDTH));

    // Cada input irá para um neurônio aleatório
    vector<int> indices(USED_HEIGHT * USED_WIDTH);
    for (int i = 0; i < USED_HEIGHT * USED_WIDTH; i++) {
        indices[i] = i;
    }

    // Embaralha os elementos do vetor
    random_device rd;
    mt19937 g(rd());
    shuffle(indices.begin(), indices.end(), g);

    vector<vector<vector<bool>>> neuronios(10, vector<vector<bool>>((USED_HEIGHT * USED_WIDTH) / 3, vector<bool>(8, false)));

    vector<bool> imagemFlat;
    
    srand(time(0));
    for(int i=0; i<10; i++){
        for(int j=0; j<20; j++){ //10772
            int numeroAleatorio = rand() % 10001;
            filename = "../data/train/" + to_string(i) + "/" + to_string(i) + "/" + to_string(numeroAleatorio) + ".png";
            const char* cstr = filename.c_str();
            treinarDataSet(cstr, neuronios, indices, booleanMatrix, i);
            cout<<"Treinados: "<<filename<<"\n";
        }
    }

    saveVectorToFile(neuronios, indices, "output.txt");

    cout << "Vetor salvo no arquivo 'output.txt'" << endl;

    filename = "../data/test/0.png";
    const char* cstr2 = filename.c_str();
    
    // Reconhecimento da mesma imagem
    if (carregaImagem(cstr2, USED_HEIGHT, USED_WIDTH, booleanMatrix)) {
        imagemFlat = preprocessarImagem(booleanMatrix);
        PrintaImagem(booleanMatrix);
        reconhecerImagem(neuronios, imagemFlat, indices);
    }
    

    return 0;
}