#include "setor.h"

Setor::Setor()
{

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

Setor *Setor::getProx()
{
    return prox;
}

void Setor::setProx(Setor *value)
{
    prox = value;
}

int Setor::getId()
{
    return id;
}

void Setor::setId(int value)
{
    id = value;
}

