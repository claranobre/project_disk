#ifndef FILE_H
#define FILE_H

#include "lista.h"
#include "setor.h"
using namespace std;

class Setor;

class File
{
public:
    File();
    ~File();
    string getNome();
    void setNome( string &value);

    int getTamanho();
    void setTamanho(int value);

    File *getProx();
    void setProx(File *value);

    Lista<Setor *> getCluster();
    void setCluster( Lista<Setor *> &value);

private:
    string nome;
    int tamanho;
    File* prox;
    Lista<Setor*> cluster;
};

#endif // FILE_H
