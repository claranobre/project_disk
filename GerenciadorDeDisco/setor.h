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
    Setor* prox;

public:
    Setor();
    ~Setor();

    int getInicio();
    void setInicio(int value);
    int getFim();
    void setFim(int value);

    Setor *getProx();
    void setProx(Setor *value);

    int getId();
    void setId(int value);
};

#endif // SETOR_H
