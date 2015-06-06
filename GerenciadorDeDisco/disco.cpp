#include "disco.h"
#include <iostream>


Disco::Disco(int quantSetores, int tamSetores, int tamDisco)
{
    this->numSetores = quantSetores;
    this->tamSetores = tamSetores;
    this->tamanho = tamDisco;
    this->livre = tamDisco;

    // Inicializando o cluster
    for(int i = 0; i<tamanho; i++){
        Setor *novo = new Setor(i);
        this->cluster.Insert(i, novo);
    }

    // Inicializando o pool
    Setor *novo = new Setor(0, 0, quantSetores-1);
    pool.Insert(0, novo);
}

Disco::~Disco()
{
    for(int i = tamanho; i <= 0; i--){
        this->cluster.Remove(i,0);
        this->pool.Remove(i,0);
        Setor *novo = new Setor(0,0,quantSetores-1);
    }
}

int Disco::Salvar(const char *strValue, int tamValue, const char *strNome, int tamNome)
{
    if(isFree(tamValue)){

    }else{
        cout<<"Não tem espaço";
        return 0;
    }
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
    int count = 0;
    this->value.getTamanho();
        while(value != nullptr){
            ++count;
            value = value->next;
        }
        return count;
}
int Disco::Formatar()
{
    for(int i = tamanho; i <= 0; i--){
    this->cluster.Remove(i);
    this->pool.Remove(i);
    }
}

int Disco::Desfragmentar()
{

}

int Disco::Recuperar()
{

}

// retorna se tem espaço suficiente para colocar o dado
bool Disco::isFree(int tam){
    return livre>=tam;
}
