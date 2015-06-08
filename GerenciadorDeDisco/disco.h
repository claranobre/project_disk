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
    int livre; // quantidade de setores livres

    Lista<File*> info;
    Lista<Setor*> cluster;
    Lista<Setor*> pool;

public:
    char *disk; // vai ficar público por enquanto, mas ele é privado
    /**
     * Construtor do disco
     * @param quantSetores Quantidade de setores
     * @param tamSetores Tamanho dos setores
     * @param tamDisco Tamanho total do disco
     */
    Disco(int quantSetores, int tamSetores, int tamDisco);

    /**
     * Destrutor padrão
     */
    ~Disco();

    /**
    * Função para salvar as informações do arquivo
    * @param strValue, tamValue, strNome, tamNome
    * return tamanho do arquivo, nome
    */
    int Salvar(const char *strValue, int tamValue, string strNome, int tamNome);

    /**
     * Inicializa um vetor com todos seus indices com valores zero
     * @param array que será inicializado
     * @param tamanho do array
     */
    void InicializarArray(int array[], int tamanho);

    /**
     * Inicializa um vetor com todos seus indices com valores zero
     * @param array que será inicializado
     * @param tamanho do array
     */
    void InicializarArray(char array[], int tamanho);

    void AtualizarPool(Lista<Setor*> pool);

    /**
      *Formata o disco apagando todo o seu conteúdo como um todo, sem a possibilidade de recuperação de nenhum dado
      @param tamDisco tamanho do disco total
      @return Disco vazio
    */
    int Formatar();

    /**
     * Desfragmenta o Disco, pegando espaços vazios e preenchendo com dados mais próximos
     * @param value Dado a ser inserido
     * @param posição do dado a ser inserido
     * @return Disco vazio
     */
    int Desfragmentar();

    /**
     * Recuperar um elemento já apagado
     * @param elm Elemento a ser recuperado
     * @return Elemento apagado
     */
    int Recuperar();

    /**
      *Função get para captar a quantidade de setores indicada pelo usuário
      *@param quantSetores
      *@return quantidade de setores existentes no disco
    */
    int getNumSetores();

    /**
     * Função para captar o tamanho do disco
     * @param tamDisco
     * @return Tamanho total do disco (quantidade de setor * tamanho do setor)
    */
    int getTamanho();

    /**
    * Função para captar o tamanho de cada setor
    * @param tamSetores
    * return Tamanho total dos setores
    */
    int getTamSetores();

    Lista<File *> getInfo();

    /**
    * Função para adicionar informação do arquivo em seus setores de destino
    * @param value
    */
    void setInfo(Lista<File *> &value);

    Lista<Setor *> getCluster();

    /**
    * Função para indicar quais setores contem informações
    * @param value
    */
    void setCluster(Lista<Setor *> &value);

    Lista<Setor *> getPool();

    /**
    * Função para indicar quais setores estão vazios
    * @param value
    */
    void setPool(Lista<Setor *> &value);

    /**
    * Função para verificar se o disco tem espaço para receber o dado
    * @param tam
    * @return retorna verdadeiro ou falso
    */
    bool isFree(int tam);
};

#endif // DISCO_H
