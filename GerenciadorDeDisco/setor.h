#ifndef SETOR_H
#define SETOR_H

#include "lista.h"
#include "file.h"

class File;

class Setor
{
private:
    int id;
    int inicio;
    int fim;
    //Setor* prox; comentei pq esse prox está na lista

public:
    Setor(int id);
    Setor(int id, int inicio, int fim);
    ~Setor();

    int getInicio();
    void setInicio(int value);

    int getFim();
    void setFim(int value);

    int getId();
    void setId(int value);
};

#endif // SETOR_H
