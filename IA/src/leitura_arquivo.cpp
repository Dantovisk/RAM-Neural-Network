/*#include <iostream>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <random>    // Para std::default_random_engine
#include <algorithm>

using namespace std;

#define USED_HEIGHT 24
#define USED_WIDTH 16

vector<bool> preprocessarImagem(const vector<vector<bool>>& image) {
    vector<bool> flatImage;
    for (const auto& row : image) {
        for (bool pixel : row) {
            flatImage.push_back(pixel);
        }
    }
    return flatImage;
}


void PrintaImagem(const vector<vector<bool>>& booleanMatrix) {
    for (const auto& row : booleanMatrix) {
        for (bool val : row) {
            cout << (val ? "1" : "0") << " ";
        }
        cout << endl;
    }
}

bool carregaImagem(const char* filename, int ExpectedHeight, int ExpectedWidth, vector<vector<bool>>& booleanMatrix) {
    int width, height, channels;
    unsigned char* img = stbi_load(filename, &width, &height, &channels, 1);

    if (img == nullptr) {
        cerr << "Erro ao carregar a imagem" << endl;
        return false;
    }

    if (width != ExpectedWidth || height != ExpectedHeight) {
        cerr << "Dimensões da imagem incorretas. Esperado 16x24 pixels." << endl;
        stbi_image_free(img);
        return false;
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char pixel = img[y * width + x];
            booleanMatrix[y][x] = (pixel < 128);
        }
    }

    stbi_image_free(img);

    return true;
}

int main() {
    const char filename[] = "../Imagens/4.png";
    vector<vector<bool>> booleanMatrix(USED_HEIGHT, vector<bool>(USED_WIDTH));

    //cada input ira para um neuronio aleatorio
    vector <int> indices (USED_HEIGHT*USED_WIDTH);
    for(int i=0; i< USED_HEIGHT*USED_WIDTH; i++){
        indices[i] = i;
    }
    // Embaralha os elementos do vetor
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);
    
    vector <bool> imagemFlat;

    if (carregaImagem(filename, USED_HEIGHT, USED_WIDTH, booleanMatrix)) {
        PrintaImagem(booleanMatrix);
        imagemFlat = preprocessarImagem(booleanMatrix);

    }

    vector<vector<vector<bool>>> neuronios(10, vector<vector<bool>>((USED_HEIGHT * USED_WIDTH) / 3, vector<bool>(8, false)));
    //teste de treinamento para o 4
    for(int i=0; i<USED_HEIGHT*USED_WIDTH; i+=3){
        if (i + 2 >= USED_HEIGHT * USED_WIDTH) {
            cerr << "Índice fora dos limites: " << i << endl;
            continue;
        }
        int n1 = (imagemFlat[indices[i]]==true?1:0);
        int n2 = (imagemFlat[indices[i+1]]==true?1:0);
        int n3 = (imagemFlat[indices[i+2]]==true?1:0);

        neuronios[4][i/3][n1*4 + n2*2 +n3] = true;
    }

    if (carregaImagem(filename, USED_HEIGHT, USED_WIDTH, booleanMatrix)) {

        //PrintaImagem(booleanMatrix);
        imagemFlat = preprocessarImagem(booleanMatrix);
    }
    //teste de reconhecimento para a mesma imagem
    vector <int> contadores(10,0);
    int contador=0;
    for(int i=0; i<USED_HEIGHT*USED_WIDTH; i+=3){
        int n1 = (imagemFlat[indices[i]]==true?1:0);
        int n2 = (imagemFlat[indices[i+1]]==true?1:0);
        int n3 = (imagemFlat[indices[i+2]]==true?1:0);

        for(int j=0; j<10; j++){
            if(neuronios[j][i/3][n1*4 + n2*2 +n3] == true){
                contadores[j]++;
                contador++;
            }
        }
    }
    
    for(int j=0; j<10; j++){
        float chance = contadores[j];
        chance/=contador;
        chance*=100;
        cout<<"Chance de ser o numero "<<j<<": "<<chance<<"%\n";
    }

    return 0;
}*/