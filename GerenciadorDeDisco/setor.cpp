#include "setor.h"

Setor::Setor(int id){
    this->id = id;
}

Setor::Setor(int id, int inicio, int fim){
    this->inicio = inicio;
    this->fim = fim;
    this->id = id;
}

Setor::~Setor()
{

}

int Setor::getInicio()
{
    return inicio;
}

void Setor::setInicio(int value)
{
    inicio = value;
}

int Setor::getFim()
{
    return fim;
}

void Setor::setFim(int value)
{
    fim = value;
}

int Setor::getId()
{
    return id;
}

void Setor::setId(int value)
{
    id = value;
}

