#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <vector>
#include "config.hpp"

void treinarNeuronios(std::vector<std::vector<std::vector<bool>>>& neuronios, const std::vector<bool>& imagemFlat, const std::vector<int>& indices, int nTreinado);

#endif // TRAIN_HPP