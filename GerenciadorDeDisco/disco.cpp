#include "disco.h"

Disco::Disco()
{
    //Criar os setores aqui tbm
}

Disco::~Disco()
{

}
int Disco::getNumSetores() const
{
    return numSetores;
}

void Disco::setNumSetores(int value)
{
    numSetores = value;
}
int Disco::getTamSetores() const
{
    return tamSetores;
}

void Disco::setTamSetores(int value)
{
    tamSetores = value;
}
int Disco::getTamanho() const
{
    return tamanho;
}

void Disco::setTamanho(int value)
{
    tamanho = value;
}




