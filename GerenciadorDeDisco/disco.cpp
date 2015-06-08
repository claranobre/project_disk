#include "disco.h"
#include <iostream>
#include <math.h>

Disco::Disco(int quantSetores, int tamSetores, int tamDisco)
{
    this->numSetores = quantSetores;
    this->tamSetores = tamSetores;
    this->tamanho = tamDisco;
    this->livre = quantSetores;

    // Inicializando o cluster
    for(int i = 0; i<tamanho; i++){
        Setor *novo = new Setor(i);
        this->cluster.Insert(i, novo);
    }

    // Inicializando o pool no intervalo [1, quantSetores]
    Setor *novo = new Setor(0, 1, quantSetores);
    pool.Insert(0, novo);

    this->disk = new char[tamDisco];
    InicializarArray(disk, tamDisco);
}

Disco::~Disco()
{
    for(int i = tamanho; i <= 0; i--){
        this->cluster.Remove(i,0);
        this->pool.Remove(i,0);
        Setor *novo = new Setor(0,0,quantSetores-1);
    }
}

int Disco::Salvar(const char *strValue, int tamValue, const char *strNome, int tamNome)
{
    // Guarda a quantidade de setores necessários para armazenar o dado
    int setoresNecessarios = ceil ((float)tamValue/tamSetores);

    int setores[setoresNecessarios];
    InicializarArray(setores, setoresNecessarios);

    //Testa para saber se existe setores livres
    if(isFree(setoresNecessarios)){
        int achados = 0;
        int contPool = 0;
        int contSetores = 0;
        while(setoresNecessarios > achados){
            Setor *aux;
            pool.GetElem(contPool, aux);

            if((aux->getFim() - aux->getInicio()) == 0){
                setores[contSetores] = aux->getFim();
                achados++;
            } else{
                for(int i = aux->getInicio(); i<= aux->getFim(); i++){
                    setores[contSetores] = i;
                    achados++;
                    contSetores++;
                    if(setoresNecessarios <= achados)
                        break;
                }
            }
            contPool++;
        }
        int contStr = 0;
        for(int i = 0; i< setoresNecessarios; i++){// percorre os setores
            for(int j = 0; j<tamSetores; j++){ // percorre as celulas dos setores
                int pos = ((setores[i]-1)*tamSetores) + j;
                disk[pos] = strValue[contStr];
                contStr++;
            }
        }
        std::cout<<contStr;

        //falta atualizar o pool e o file
        return 1;

    }else{
        // depois colocar um alert aqui para o usuario ver
        std::cout<<"Não tem espaço";
        return 0;
    }
}

//Inicializa um array com o valor 0
void Disco::InicializarArray(int array[], int tamanho)
{
    for(int i=0; i<tamanho; i++){
        array[i] = 0;
    }

}

void Disco::InicializarArray(char array[], int tamanho)
{
    for(int i=0; i<tamanho; i++){
        array[i] = '0';
    }

}

int Disco::getNumSetores()
{
    return numSetores;
}

void Disco::setNumSetores(int value)
{
    numSetores = value;
}

int Disco::getTamanho()
{
    return tamanho;
}

void Disco::setTamanho(int value)
{
    tamanho = value;
}

int Disco::getTamSetores()
{
    return tamSetores;
}

void Disco::setTamSetores(int value)
{
    tamSetores = value;
}

Lista<File *> Disco::getInfo()
{
    return info;
}

void Disco::setInfo( Lista<File *> &value)
{
    info = value;
}

Lista<Setor *> Disco::getCluster()
{
    return cluster;
}

void Disco::setCluster( Lista<Setor *> &value)
{
    cluster = value;
}

Lista<Setor *> Disco::getPool()
{
    return pool;
}

void Disco::setPool( Lista<Setor *> &value)
{
    pool = value;
    int count = 0;
    this->value.getTamanho();
        while(value != nullptr){
            ++count;
            value = value->next;
        }
        return count;
}
int Disco::Formatar()
{
    for(int i = tamanho; i <= 0; i--){
    this->cluster.Remove(i);
    this->pool.Remove(i);
    }
}

int Disco::Desfragmentar()
{

}

int Disco::Recuperar()
{

}

// retorna se tem espaço suficiente para colocar o dado
bool Disco::isFree(int tam){
    return livre>=tam;
}
