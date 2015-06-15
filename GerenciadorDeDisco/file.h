#ifndef FILE_H
#define FILE_H

#include "lista.h"
using namespace std;
class File
{
public:
    File(string nome, int tamanho, int cluster[]);
    ~File();

    string getNome();
    int getTamanho();
    int getCluster(int id);
    void setCluster(int value, int id);

private:
    string nome;
    int tamanho;
    int *cluster;
};

#endif // FILE_H
