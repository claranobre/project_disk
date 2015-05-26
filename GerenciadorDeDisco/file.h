#ifndef FILE_H
#define FILE_H
#include "lista.h"
#include "setor.h"

using namespace std;

class File
{
private:
    string nome;
    int tamanho;
    /*Lista<File*> prox;
    Lista<Setor*> cluster;*/


public:
    File();
    ~File();
};

#endif // FILE_H
