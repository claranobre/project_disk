#ifndef FILE_H
#define FILE_H

#include "lista.h"
#include "setor.h"
using namespace std;

//class Setor;

class File
{
public:
    File(string nome, int tamanho, int cluster[]);
    ~File();

    string getNome();
    int getTamanho();
    int getCluster(int i);

private:
    string nome;
    int tamanho;
    int *cluster;
};

#endif // FILE_H
