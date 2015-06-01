#include "file.h"

File::File()
{

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

File *File::getProx()
{
    return prox;
}

void File::setProx(File *value)
{
    prox = value;
}

Lista<Setor *> File::getCluster()
{
    return cluster;
}

void File::setCluster( Lista<Setor *> &value)
{
    cluster = value;
}
