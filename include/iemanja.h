#ifndef IEMANJA_H_  /**< Verifica se a variável QUESTAO_3_INCLUDE_FILA_H_ foi definida*/
#define IEMANJA_H_	 /**< Define a variável QUESTAO_3_INCLUDE_FILA_H_*/

#include <string>
#include "pilha.h"

class Iemanja
{
private:
	//variavel principal para guardar a expressão
	std::string expressao;
	//guarda a linha que expressão ocupa no arquivo lido
	int linha;
	//necessário para verificaçã dos erros - codigo de erro
	int codido_erro;
	//necessário para verificaçã dos erros - informa a descrição do erro
	std::string erro_descricao;

public:
	//construtor parametrizado
	Iemanja(std::string expressao_recebida, int linha);
	~Iemanja();

	//getters e setters
	std::string get_expressao();
	int get_linha();

	// 4 - verificações
	bool validacoes(); // 4
	bool validacao_caracteres_invalidos(); //4.1
	bool validacao_formacao_numeros(); //4.2
	bool validacao_balanceamento_parenteses(); //4.3
	

	//6 - extração das componentes internos
	void retirar_espacamento();
	
};

#endif /* QUESTAO_3_INCLUDE_FILA_H_ */