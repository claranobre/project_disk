#include "disco.h"
#include <iostream>
#include <math.h>
#include <QMessageBox>
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
    Setor *novo = new Setor(0, 0, quantSetores);
    pool.Insert(0, novo);

    this->disk = new char[tamDisco];
    InicializarArray(disk, tamDisco);
}

// Falta terminar de consertar
Disco::~Disco()
{
    for(int i = tamanho-1; i >= 0; i--){
        this->cluster.Remove(i);
        this->pool.Remove(i);
    }
    //remover info
    livre = numSetores;
}

int Disco::Salvar(const char *strValue, int tamValue, string strNome, int tamNome)
{
    // Guarda a quantidade de setores necessários para armazenar o dado
    int setoresNecessarios = ceil ((float)tamValue/tamSetores);

    //Guarda o id dos setores onde serão inseridos
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

        int pos;
        int id = 0;
        //cout<<"Tam: "<<tamValue<<endl;
        for(int i = 0; i<tamValue; i++){
            if(((i%tamSetores) == 0) && (i>0)){
                id++;
            }
            pos = ((setores[id])*tamSetores) + (i%tamSetores);
            disk[pos] = strValue[i];
        }

        File *novoArquivo = new File(strNome, tamNome, setores);
        info.Insert(info.Size(), novoArquivo);

        AtualizarPool();
        livre = livre - setoresNecessarios;
        return 1;

    }else{
        QMessageBox msgBox;
        msgBox.setText("Não tem espaço suficiente.");
        msgBox.exec();
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

void Disco::AtualizarPool()
{
    int vazio[numSetores][2];
    int inicio = 0;
    int igual = 0;
    int cont = 0;

    for(int i = 0; i<numSetores; i++){
        if(disk[i*tamSetores] == '0'){
            if(igual == 0){
                igual = 1;
                inicio = i;
            }
        } else{
            if(igual == 1){
                vazio[cont][0] = inicio;
                vazio[cont][1] = (i-1);
                igual = 0;
                cont ++;
            }
        }

        if(i == (numSetores-1)){ // Testando se é o fim do 'for'
            if(igual == 1){
                vazio[cont][0] = inicio;
                vazio[cont][1] = (i);
                igual = 0;
                cont ++;
            }
        }
    }

    pool.RemoveAll();

    for(int i = 0; i<cont; i++){
        //cout<<vazio[i][0]<<"~"<<vazio[i][1]<<endl;
        Setor *novo = new Setor(i, vazio[i][0], vazio[i][1]);
        pool.Insert(i, novo);
    }
}

int Disco::getNumSetores()
{
    return numSetores;
}

int Disco::getTamanho()
{
    return tamanho;
}

int Disco::getTamSetores()
{
    return tamSetores;
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

// erros de compilação e de lógica
void Disco::setPool( Lista<Setor *> &value)
{
 /*   pool = value;
    int count = 0;
    this->value.getTamanho();
        while(value != nullptr){
            ++count;
            value = value->next;
        }
        return count;*/
}


int Disco::Formatar()
{
    for(int i = tamanho; i >= 0; i--){ //For está errado
    this->cluster.Remove(i);
    this->pool.Remove(i);
    }
    // falta atualivar var 'livre'
    // falta limpar 'info'
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
