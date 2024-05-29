#include "preprocess.hpp"
#include "stb_image.h"
#include <iostream>

using namespace std;

std::vector<bool> preprocessarImagem(const std::vector<std::vector<bool>>& image) {
    std::vector<bool> flatImage;
    for (const auto& row : image) {
        for (bool pixel : row) {
            flatImage.push_back(pixel);
        }
    }
    return flatImage;
}

bool carregaImagem(const char* filename, int ExpectedHeight, int ExpectedWidth, std::vector<std::vector<bool>>& booleanMatrix) {
    int width, height, channels;
    unsigned char* img = stbi_load(filename, &width, &height, &channels, 4); // 4 canais para RGBA

    if (img == nullptr) {
        std::cerr << "Erro ao carregar a imagem" << std::endl;
        return false;
    }

    if (width != ExpectedWidth || height != ExpectedHeight) {
        std::cerr << "Dimensões da imagem incorretas. Esperado " << ExpectedWidth << "x" << ExpectedHeight << " pixels." << std::endl;
        stbi_image_free(img);
        return false;
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char pixelAlpha = img[(y * width + x) * 4 + 3]; // Canal Alpha (transparência)
            booleanMatrix[y][x] = (pixelAlpha < 60); // Definir como 0 se o valor do Alpha for baixo
        }
    }

    stbi_image_free(img);
    return true;
}

void PrintaImagem(const vector<vector<bool>>& booleanMatrix) {
    for (const auto& row : booleanMatrix) {
        for (bool val : row) {
            cout << (val ? "0" : "1") << " ";
        }
        cout << endl;
    }
}