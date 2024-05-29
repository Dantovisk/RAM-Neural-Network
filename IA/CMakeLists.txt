cmake_minimum_required(VERSION 3.10)
project(ImageRecognition)

set(CMAKE_CXX_STANDARD 17)

# Incluir o diretório 'include' e o diretório raiz para o stb_image.h
include_directories(include .)

# Adicionar a definição de STB_IMAGE_IMPLEMENTATION
add_definitions(-DSTB_IMAGE_IMPLEMENTATION)

# Adicionar todos os arquivos fonte
add_executable(ImageRecognition
    src/main.cpp
    src/preprocess.cpp
    src/train.cpp
    src/recognize.cpp
    stb_image.h
)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(ImageRecognition OpenMP::OpenMP_CXX)
endif()