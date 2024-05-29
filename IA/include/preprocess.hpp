#ifndef PREPROCESS_HPP
#define PREPROCESS_HPP

#include <vector>

std::vector<bool> preprocessarImagem(const std::vector<std::vector<bool>>& image);
bool carregaImagem(const char* filename, int ExpectedHeight, int ExpectedWidth, std::vector<std::vector<bool>>& booleanMatrix);
void PrintaImagem (const std::vector<std::vector<bool>>& booleanMatrix);


#endif // PREPROCESS_HPP