#include "disco.h"
#include <iostream>


Disco::Disco(int quantSetores, int tamSetores, int tamDisco)
{
    this->numSetores = quantSetores;
    this->tamSetores = tamSetores;
    this->tamanho = tamDisco;

    /*
    for(int i = 0; i<tamanho; i++){
        Setor *novo = new Setor();
        this->cluster.Insert(i, novo);
    }*/
   // std::cout<<cluster.Size();
}

Disco::~Disco()
{

}

int Disco::getNumSetores()
{
    return numSetores;
}

void Disco::setNumSetores(int value)
{
    numSetores = value;
}

int Disco::getTamanho()
{
    return tamanho;
}

void Disco::setTamanho(int value)
{
    tamanho = value;
}

int Disco::getTamSetores()
{
    return tamSetores;
}

void Disco::setTamSetores(int value)
{
    tamSetores = value;
}

Lista<File *> Disco::getInfo()
{
    return info;
}

void Disco::setInfo( Lista<File *> &value)
{
    info = value;
}

Lista<Setor *> Disco::getCluster()
{
    return cluster;
}

void Disco::setCluster( Lista<Setor *> &value)
{
    cluster = value;
}

Lista<Setor *> Disco::getPool()
{
    return pool;
}

void Disco::setPool( Lista<Setor *> &value)
{
    pool = value;
}

int Disco::Formatar()
{

}

int Disco::Desfragmentar()
{

}

int Disco::Recuperar()
{

}
