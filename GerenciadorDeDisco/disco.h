#ifndef DISCO_H
#define DISCO_H


class Disco
{
public:
    Disco();
    ~Disco();
    int getNumSetores() const;
    void setNumSetores(int value);

    int getTamSetores() const;
    void setTamSetores(int value);

    int getTamanho() const;
    void setTamanho(int value);

private:
    int numSetores;
    int tamSetores;
    int tamanho;
};

#endif // DISCO_H
