#include "file.h"

File::File(string nome, int tamanho, int cluster[])
{
    this->nome = nome;
    this->tamanho = tamanho;
    this->cluster = new int[tamanho];
    this->cluster = cluster;
    cout<<"ei: "<<this->cluster[0]<<endl;
}

File::~File()
{

}

string File::getNome()
{
    return nome;
}

int File::getTamanho()
{
    return tamanho;
}
int *File::getCluster()
{
    return cluster;
}

int File::getCluster(int i)
{
    //cout<<cluster[0]<<endl;
    return cluster[i];
}
