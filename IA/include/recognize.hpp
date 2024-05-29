#ifndef RECOGNIZE_HPP
#define RECOGNIZE_HPP

#include <vector>
#include "config.hpp"

void reconhecerImagem(const std::vector<std::vector<std::vector<bool>>>& neuronios, const std::vector<bool>& imagemFlat, const std::vector<int>& indices);

#endif // RECOGNIZE_HPP