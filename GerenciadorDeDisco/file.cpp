#include "file.h"

File::File(string nome, int tamanho, int cluster[])
{
    this->nome = nome;
    this->tamanho = tamanho;
    this->cluster = new int[tamanho];
    this->cluster = cluster;
}

File::~File()
{

}

string File::getNome()
{
    return nome;
}

void File::setNome( string &value)
{
    nome = value;
}

int File::getTamanho()
{
    return tamanho;
}

void File::setTamanho(int value)
{
    tamanho = value;
}
