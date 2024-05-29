#include "train.hpp"
#include <vector>
#include <random>
#include <iostream>
#include "preprocess.hpp"

using namespace std;

void treinarNeuronios(vector<vector<vector<bool>>>& neuronios, const vector<bool>& imagemFlat, const vector<int>& indices, int nTreinado) {
    for (int i = 0; i < USED_HEIGHT * USED_WIDTH-2; i += 3) {
        if (i + 2 >= USED_HEIGHT * USED_WIDTH) {
            cerr << "Índice fora dos limites: " << i << endl;
            continue;
        }
        int n1 = (imagemFlat[indices[i]] == true ? 1 : 0);
        int n2 = (imagemFlat[indices[i + 1]] == true ? 1 : 0);
        int n3 = (imagemFlat[indices[i + 2]] == true ? 1 : 0);

        neuronios[nTreinado][i / 3][n1 * 4 + n2 * 2 + n3] = true;
    }
}