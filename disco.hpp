#ifndef __Disco__
#define __Disco__

template <typename TYPE>
class Disco {

	struct Node {
		TYPE data;
		Node *next, *prev;
		Node() { next = prev = nullptr; }
	};
public:
	/** Verifica se o Disco está vazio */
	bool isEmpty();

	/** Retorna o número de elementos no Disco */
	int  getSize();
	
	/**
	 * Adiciona um elemento em uma posição específica do Disco. Se a posição dada for
	 * negativa, insere no ínicio. Se a posição for maior que o tamanho da Disco, insere
	 * no final.
	 * @param value Elemento a ser inserido
	 * @param pos   Posição do elemento a ser inserido
	 * @return      Verdadeiro se o elemento foi adicionado ou falso caso contrário (memória cheia, por exemplo)
	 */
	bool add(const TYPE &value, int pos = 0);
	
	/**
	 * Remove o elemento de uma posição específica. Se a posição dada for negativa, remove
	 * o primeiro elemento. Se for maior que o tamanho, remove o último.
	 * @param  pos Posição do elemento a ser removido
	 * @return     Uma cópia do elemento removido
	 */
	TYPE remove(int pos = 0);
	
	/**
	 * Consulta a posição de um elemento no Disco
	 * @param  elm Elemento a ser consultado
	 * @return     Posição em que ele se encontra ou -1 se ele não existir no Disco
	 */
	int search(const TYPE &elm);
	/**
	 * Formata todo o Disco
	 * @return    Disco vazio
	 */
	int formatar();
	/**
	 * Fragmenta o Disco, pegando espaços vazios e preenchendo com dados mais próximos
	 * @param value Dado a ser inserido
	 * @param posição do dado a ser inserido
	 * @return    Disco vazio
	 */
	int fragmentar(const TYPE &value, int pos = 0);
	/**
	 * Recuperar um elemento já apagado
	 * @param elm Elemento a ser recuperado
	 * @return Elemento apagado
	 */
	int recuperar(const TYPE &elm);
}	