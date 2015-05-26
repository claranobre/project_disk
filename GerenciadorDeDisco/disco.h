#ifndef DISCO_H
#define DISCO_H
#include "file.h"
#include "setor.h"
#include "lista.h"

class Disco {

private:
    int numSetores;
    int tamSetores;
    int tamanho;
    /*Lista<File*> info;
    Lista<Setor*> cluster;
    Lista<Setor*> pool;
    Lista<char*> disk;*/

public:
    Disco();
    ~Disco();
    int Formatar();
    /**
     * Fragmenta o Disco, pegando espaços vazios e preenchendo com dados mais próximos
     * @param value Dado a ser inserido
     * @param posição do dado a ser inserido
     * @return    Disco vazio
     */
    int Desfragmentar();
    /**
     * Recuperar um elemento já apagado
     * @param elm Elemento a ser recuperado
     * @return Elemento apagado
     */

    int Recuperar();

    int getNumSetores();
    void setNumSetores(int value);
    int getTamanho();
    void setTamanho(int value);
    int getTamSetores();
    void setTamSetores(int value);
};

#endif // DISCO_H
