#ifndef DISCO_H
#define DISCO_H
#include "file.h"
#include "setor.h"
#include "lista.h"
#include <QMainWindow>

class Disco {

private:
    int numSetores;
    int tamSetores;
    int tamanho;
    int livre; // quantidade de setores livres

    Lista<File*> info;
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
     * @param Nome do arquivo que será excluido
     * @return 1 se exclusão foi correta ou 0 caso não tenha excluido
     */
    int Excluir(string Nome);

    /**
     * Busca um arquivo e retorna os seus dados
     * @param Nome que será procurado
     * @return html que será inserido no widget
     */
    QString Buscar(string nome);

    /**
     *
     * @return html para ser inserido no widget
     */
    QString Listar();

    /**
     * Inicializa um vetor com todos seus indices com valores zero
     * @param array que será inicializado
     * @param tamanho do array
     */
    void InicializarArray(int array[], int tamanho, int valor);

    /**
     * Inicializa um vetor com todos seus indices com valores zero
     * @param array que será inicializado
     * @param tamanho do array
     */
    void InicializarArray(char array[], int tamanho);

    /**
     * Atualiza o pool após alguma modificação no disco (add, delete, format)
     */
    void AtualizarPool();

    /**
     * Formata o disco apagando todo o seu conteúdo como um todo, sem a possibilidade de recuperação de nenhum dado
     * @return 1 se o disco foi formatado corretamente ou 0 caso tenha erro
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
     * Verifica se o disco está fragmentado
     * @return 1 se tiver fragmentado, 0 se não tiver
     */
    int isFragmented(int disco[]);

    /**
    * Função para verificar se o disco tem espaço para receber o dado
    * @param tam
    * @return retorna verdadeiro ou falso
    */
    bool isFree(int tam);

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

    Lista<Setor *> getPool();
};

#endif // DISCO_H
