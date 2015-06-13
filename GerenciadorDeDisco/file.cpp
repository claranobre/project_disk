#include "file.h"

File::File(string nome, int tamanho, int cluster[])
{
    this->nome = nome;
    this->tamanho = tamanho;
    this->cluster = new int[tamanho];

    for(int i = 0; i<tamanho; i++){
        this->cluster[i] = cluster[i];
    }
}

File::~File()
{
    delete cluster;
}

string File::getNome()
{
    return nome;
}

int File::getTamanho()
{
    return tamanho;
}

int File::getCluster(int i)
{
    return cluster[i];
}
