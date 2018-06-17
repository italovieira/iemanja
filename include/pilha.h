/**
* @file   Fila.h
* @brief  Classe responsável por criar uma fila com lista encadeada do mesmo diretório 
* @author Claudio da Cruz Silva Junior
* @since  20/05/2018
* @date   20/05/2018
*/

#ifndef PILHA_H_  /**< Verifica se a variável QUESTAO_3_INCLUDE_FILA_H_ foi definida*/
#define PILHA_H_	 /**< Define a variável QUESTAO_3_INCLUDE_FILA_H_*/

#include <iostream> /**< Inclusão da biblioteca iostream*/
#include "lista_duplamente_encadeada.h" /**< Inclusão da classe lista circular encadeada*/

using namespace std;

template <typename T>
class Pilha {
private:
	LinkedList<T> *lista_duplamente_encadeada; 
public:
	Pilha(); /**< Construtor padrão da Classe*/
	~Pilha(); /**< Destrutor da Classe*/
	/**
	* @brief Método que retorna o valor do topo da pilha
	* @return valor do topo da pilha
	*/
	T top();
	/**
	* @brief Método que retira o valor do topo da pilha
	* @return 
	*/
	void pop();
	/**
	* @brief Método que adiciona um novo valor no top da pilha
	* @return 
	*/
	void push(T caractere);

	bool is_empty();
};

/**
* @brief Construtor padrão do objeto
*/
template<typename T>
inline Pilha<T>::Pilha() {
	this->lista_duplamente_encadeada = new LinkedList<T>;
}
/**
* @brief Destrutor do objeto
*/
template<typename T>
inline Pilha<T>::~Pilha() {
}

/**
* @brief Método que insere na fila
* @param[in] valor a ser adicionado
* @return booleano
*/
template<typename T>
inline void	 Pilha<T>::push(T caractere) {
	this->lista_duplamente_encadeada->push_front(caractere);
}

/**
* @brief Método que remove da fila
* @return booleano
*/
template<typename T>
inline void Pilha<T>::pop() {
	this->lista_duplamente_encadeada->remove(0);
}

/**
* @brief Método que imprime o primeiro elemento da fila
* @return 
*/
template<typename T>
T Pilha<T>::top() {
	return this->lista_duplamente_encadeada->get_element(0);
}

/**
* @brief Método que imprime o primeiro elemento da fila
* @return 
*/
template<typename T>
inline bool Pilha<T>::is_empty() {
	return this->lista_duplamente_encadeada->is_empty();
}

#endif /* QUESTAO_3_INCLUDE_FILA_H_ */
