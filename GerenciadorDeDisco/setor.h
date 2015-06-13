#ifndef SETOR_H
#define SETOR_H

#include "lista.h"

class Setor
{
private:
    int id;
    int inicio;
    int fim;

public:
    Setor(int id);
    Setor(int id, int inicio, int fim);
    ~Setor();

    int getInicio();
    int getFim();
    int getId();
};

#endif // SETOR_H
