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

    // Inicializando o pool no intervalo [0, quantSetores]
    Setor *novo = new Setor(0, 0, quantSetores);
    pool.Insert(0, novo);

    this->disk = new char[tamDisco];
    InicializarArray(disk, tamDisco);
}

// Falta terminar de consertar
Disco::~Disco()
{
    info.~Lista();
    pool.~Lista();
    delete disk;
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
        for(int i = 0; i<tamValue; i++){
            if(((i%tamSetores) == 0) && (i>0)){
                id++;
            }
            pos = ((setores[id])*tamSetores) + (i%tamSetores);
            disk[pos] = strValue[i];
        }

        File *novoArquivo = new File(strNome, tamValue, setores);
        info.Insert(info.Size(), novoArquivo);

        AtualizarPool();
        livre = livre - setoresNecessarios;
        return 1;

    } else{ // envia uma msg se não tiver espaço suficiente
        QMessageBox msgBox;
        msgBox.setText("Não tem espaço suficiente.");
        msgBox.exec();
        return 0;
    }
}

int Disco::Excluir(string nome)
{
    File *temp;
    for(int i = 0; i< info.Size(); i++){
        info.GetElem(i,temp);
        if(temp->getNome() == nome){

            int tamanho = temp->getTamanho();

            int setoresNecessarios = ceil ((float)tamanho/tamSetores);

            for(int j = 0; j < setoresNecessarios; j++){
                for(int k = 0; k < tamSetores; k++){
                    int pos = (temp->getCluster(j)*tamSetores)+k;
                    disk[pos] = '0';
                }
            }
            info.Remove(i);
            livre += setoresNecessarios;
            AtualizarPool();
            return 1;
        }
    }
    return 0;
}

QString Disco::Buscar(string nome)
{
    File *temp;
    QString html;
    for(int i = 0; i< info.Size(); i++){
        info.GetElem(i,temp);
        if(temp->getNome() == nome){
            char tam[10];
            html = "<table border=1><tr><th>Nome</th><th>Tamanho</th><th>Cluster</th></tr>";

            html.push_back("<tr> <td align = 'center'>");
            html.push_back(temp->getNome().c_str());
            html.push_back("</td>");

            html.push_back("<td align = 'center'>");
            itoa(temp->getTamanho(),tam,10); // pega o tamanho e jogar em 'tam'
            html.push_back( tam);
            html.push_back("</td>");

            html.push_back("<td align = 'center'>");
            int tamanho = temp->getTamanho();
            int setoresNecessarios = ceil ((float)tamanho/tamSetores);
            for(int j = 0; j<setoresNecessarios; j++){
               itoa(temp->getCluster(j), tam, 10);
               if(j == 0)
                   html.push_back(tam);
               else{
                   html.push_back(", ");
                   html.push_back(tam);
               }
            }
            html.push_back("</td></tr>");

            html.push_back("<tr><td colspan='3' align='center'><b>Valor</b></td></tr>");

            html.push_back("<tr><td colspan='3' align='center'>");

            for(int j = 0; j < setoresNecessarios; j++){
                for(int k = 0; k < tamSetores; k++){
                    int pos = (temp->getCluster(j)*tamSetores)+k;
                    html.push_back(disk[pos]);
                }
            }

            html.push_back("</td></tr>");
            html.push_back("<table>");
            return html;
        }
    }
    return html;
}

QString Disco::Listar()
{
   QString html = "<table border=1><tr><th>Nome</th><th>Tamanho</th><th>Cluster</th></tr>";
   File *aux;
   for(int i=0; i<info.Size(); i++){
       char tam[10];
       info.GetElem(i, aux);

       html.push_back("<tr> <td align = 'center'>");
       html.push_back(aux->getNome().c_str());
       html.push_back("</td>");

       html.push_back("<td align = 'center'>");
       itoa(aux->getTamanho(),tam,10); // pega o tamanho e jogar em 'tam'
       html.push_back( tam);
       html.push_back("</td>");

       html.push_back("<td align = 'center'>");
       int tamanho = aux->getTamanho();
       int setoresNecessarios = ceil ((float)tamanho/tamSetores);
       for(int j = 0; j<setoresNecessarios; j++){
           itoa(aux->getCluster(j), tam, 10);
           if(j == 0)
               html.push_back(tam);
           else{
               html.push_back(", ");
               html.push_back(tam);
           }
       }
       html.push_back("</td></tr>");
   }
   html.push_back("<table>");
   return html;
}

//Inicializa um array com o valor 0
void Disco::InicializarArray(int array[], int tamanho)
{
    for(int i=0; i<tamanho; i++){
        array[i] = 0;
    }
}

//Inicializa um array com o valor 0
void Disco::InicializarArray(char array[], int tamanho)
{
    for(int i=0; i<tamanho; i++){
        array[i] = '0';
    }
}

// Atualiza o pool com os novos valores
void Disco::AtualizarPool()
{
    int vazio[numSetores][2];// [0] tem o inicio, [1] tem o final
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

    cout<<endl;
    for(int i = 0; i<cont; i++){
        Setor *novo = new Setor(i, vazio[i][0], vazio[i][1]);
        cout<<"["<<vazio[i][0]<<", "<<vazio[i][1]<<"] -> ";
        pool.Insert(i, novo);
    }
    cout<<endl;

}

int Disco::Formatar(){
    pool.RemoveAll();
    info.RemoveAll();
    livre = numSetores;
    InicializarArray(disk, tamanho);

    // Inicializando o pool no intervalo [0, quantSetores]
    Setor *novo = new Setor(0, 0, numSetores);
    pool.Insert(0, novo);

    return 1;
}

int Disco::Desfragmentar(){
    if(isFree(1)){
        // vetor que vai informar qual arquivo está em qual setor
        // ex: auxDisk[0] = 1; Setor 0 tá com uma parte do arquivo 1
        // ex: auxDisk[9] = 5; Setor 9 tá com uma parte do arquivo 5
        int auxDisk[numSetores];
        InicializarArray(auxDisk, numSetores);
        File *aux;
        for(int i = 0; i < info.Size(); i++){
            info.GetElem(i, aux);
            int tamanho = aux->getTamanho();
            int setoresNecessarios = ceil ((float)tamanho/tamSetores);
            for(int j = 0; j<setoresNecessarios; j++){
                auxDisk[aux->getCluster(j)] = (i+1);
            }
        }
        cout<<" ------ "<<endl;
        // só para mostrar o array, depois apagar isto.
        for(int i = 0; i<numSetores; i++){
            cout<<"Setor: "<<i<<" Arquivo: "<<auxDisk[i]<<endl;
        }

        int temp = 0; // para ajudar na troca do auxDisk
        char tempChar;
        for(int i = 0; i<numSetores; i++){
            for(int j = 0; j<numSetores; j++){
                if(auxDisk[i] < auxDisk[j]) {
                    temp = auxDisk[j];
                    auxDisk[j] = auxDisk[i];
                    auxDisk[i] = temp;
                    for(int k = 0; k<tamSetores; k++){
                        int pos1 = (tamSetores*i)+k;
                        int pos2 = (tamSetores*j)+k;

                        // troca os valores do disco
                        tempChar = disk[pos2];
                        disk[pos2] = disk[pos1];
                        disk[pos1] = tempChar;
                    }
                }
            }
        }
        // atualizar file
        // atualizar pool
        cout<<" ------ "<<endl;
        // só para mostrar o array, depois apagar isto.
        for(int i = 0; i<numSetores; i++){
            cout<<"Setor: "<<i<<" Arquivo: "<<auxDisk[i]<<endl;
        }
        return 1;

    } else{
        QMessageBox msgBox;
        msgBox.setText("Não tem espaço suficiente.");
        msgBox.exec();
        return 0;
    }
}

// retorna se tem espaço suficiente para colocar o dado
bool Disco::isFree(int tam){
    return livre>=tam;
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


Lista<Setor *> Disco::getPool()
{
    return pool;
}
