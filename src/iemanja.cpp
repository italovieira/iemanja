
#include <string>
#include <cctype> /**< Inclusão da biblioteca cctype*/
#include <algorithm> /**< Inclusão da biblioteca algorithm*/
#include "../include/iemanja.h"

using namespace std;

Iemanja::Iemanja(std::string expressao_recebida, int linha):expressao(expressao_recebida), linha(linha){}
Iemanja::~Iemanja(){}

std::string Iemanja::get_expressao(){
	return this->expressao;
}

int Iemanja::get_linha(){
	return this->linha;
}

//funções 4 - validações
//4
bool Iemanja::validacoes(){
	//variavel de validação
	bool validado = false;

	//execução das validações
	if(validacao_caracteres_invalidos()){
		if(validacao_formacao_numeros()){
			if(validacao_balanceamento_parenteses()){
				if(validacao_expressao_infixa()){
					validado = true;
					cout << this->expressao << endl;
				}
			}
		}
	}
	
	//verfica se a expressão está validada
	if(validado)
		return true;
	else{
		cout << "código de erro " << this->codido_erro << " " << this->erro_descricao << endl;	
		return false;
	}
}

//4.1
bool Iemanja::validacao_caracteres_invalidos(){
	//tamanho da expresão
	int tamanho_expressao = this->expressao.size();
	//string com as caracteres validos para comparação
	string caracteres_validos = "0123456789+-*/^()' '.";
	//booleano para verificar se a expressão só tem caracteres validos
	bool caracter_valido = false;
	//for para a expressão
	for(int i = 0; i < tamanho_expressao; i++){
		caracter_valido = false;
		//for para a os caracteres validos
		for(int j = 0; j < (int)caracteres_validos.size(); j++){
			if(this->expressao[i] == caracteres_validos[j])
				caracter_valido = true;
		}

		//caso em que o caractere não seja nenhum dos caracteres validos
		if(!caracter_valido){
			codigo_erro_1(i);
			return false;
		}
	}
	return true;
}

//4.2 
bool Iemanja::validacao_formacao_numeros(){
	//verifica o tamanho da expressão
	int tamanho_expressao = this->expressao.size();
	
	//string com os caracteres numericos
	string caracteres_numericos = "0123456789.";
	
	//string contendo o numero encontrado em meio a expressão
	string numero_encontrado = "";
 	
 	//inteiro que demarca a posição inicial dos numeros encontrados
	int indice_incial_numero = 0;

	//tamanho do numero encontrado
	int tamanho_numero_encontrado;

	//quantidade de pontos no numero encontrado
	int quantidade_pontos;

	//booleano verificando se o numero encontrado contem um dos erros
	bool contem_erros = false;

	//booleano para verificar se o caractere encontrado é numerico
	bool caractere_numerico = false;

	for(int i = 0; i < tamanho_expressao; i++){
		//cout << this->expressao[i] << endl;
		caractere_numerico = false;
		for(int j = 0; j < (int)caracteres_numericos.size(); j++){
			if(this->expressao[i] == caracteres_numericos[j])
				caractere_numerico = true;
			
		}
			//concatena na variavel de numeros encontrados enquanto foram caracteres numericos
			if(caractere_numerico){
				//cout << "numerico" << this->expressao[i] << endl;
				if(numero_encontrado == ""){
					indice_incial_numero = i;
				}
				numero_encontrado += this->expressao[i];
			}
			else{
				//cout << "não numerico" << this->expressao[i] << endl;
				//se existe um numero encontrado
				if(numero_encontrado != ""){
					tamanho_numero_encontrado = numero_encontrado.size();

					//verificar se há pontuação inicial
					if(numero_encontrado[0] == '.')
						contem_erros = true;

					//verificar se há pontuação no fim
					if(numero_encontrado[tamanho_numero_encontrado-1] == '.')
						contem_erros = true;
					
					//verificar se há mais de um ponto
					quantidade_pontos = 0;

					for(int k = 0; k < tamanho_numero_encontrado; k++){
						if(numero_encontrado[k] == '.')
							quantidade_pontos++;
					}

					if(quantidade_pontos > 1)
						contem_erros = true;

					//retorna para a seção de validações com erro caso contenha erros
					if(contem_erros){
						codigo_erro_2(indice_incial_numero);
						return false;
							
					}

					numero_encontrado = "";	
				}
			}
	}

	return true;

}

//4.3 
bool Iemanja::validacao_balanceamento_parenteses(){
	//pilha para verificar o balanceamento de parênteses
	Pilha<char> *pilha_balanceamento_parentese = new Pilha<char>;
	//tamanho da expressao
	int tamanho_expressao = this->expressao.size();

	for(int i = 0; i < tamanho_expressao; i++){
		//adiciona o parêntese na pilha caso seja encontrado
		if(this->expressao[i] == '(')
			pilha_balanceamento_parentese->push('(');
		//retira o parênte da pilha
		if(this->expressao[i] == ')')
			pilha_balanceamento_parentese->pop();	
	}

	if(!pilha_balanceamento_parentese->is_empty()){
		codigo_erro_3();
		return false;
	}

	return true;
	
}

//4.3 
bool Iemanja::validacao_expressao_infixa() {
	string binarios = "*/^";
        string unarios = "+-";
	size_t found = 0;
        this->retirar_espacamento();
        size_t tamanho_expressao = this->expressao.length();

        char last = this->expressao.back();
        if (last == '+' || last == '-') {
            codigo_erro_4();
            return false;
        }

        while (found != string::npos) {
            found = this->expressao.find_first_of(unarios, found + 1);
            char previous = this->expressao[found - 1];
            if (previous == '+' || previous == '-') {
                codigo_erro_4();
                return false;
            }
        }

	size_t i = 0;
        found = -1;
        while (i != found) {
            i = found + 1;

		while (this->expressao[i] == ' '
			   || this->expressao[i] == '('
			   || this->expressao[i] == ')') {
			i++;
			found++;
		}

		found = this->expressao.find_first_of(binarios, i);
		if (found == string::npos) {
                    if (i < tamanho_expressao) {
                        return true;
                    }

                    break;
		}
	}

        codigo_erro_4();
	return false;
}

//fim validações

//5 - codigos de erro
void Iemanja::codigo_erro_1(int posicao){
	this->codido_erro = 1;
	this->erro_descricao = "Erro na expressão da linha " + 
							to_string(this->linha) + " Caractere inválido (" 
							+ this->expressao[posicao] + ") encontrado na posição " + to_string(posicao);
}

void Iemanja::codigo_erro_2(int indice_incial_numero){
	this->codido_erro = 2;
	this->erro_descricao = "Erro na expressão da linha " + to_string(this->linha) 
							+ " Número inválido encontrado a partir da posição "
							+ to_string(indice_incial_numero);	
}

void Iemanja::codigo_erro_3(){
	this->codido_erro = 3;
	this->erro_descricao = "Erro na expressão da linha " + to_string(this->linha) 
							+ " os parênteses estão desbalanceados ";	
}

void Iemanja::codigo_erro_4(){
	this->codido_erro = 4;
	this->erro_descricao = "Erro na expressão da linha " + to_string(this->linha)
							+ " Expressão infixa malformada ";
}
//fim codigos de erro

void Iemanja::retirar_espacamento(){
	//remove o espaçamento da expressao
	this->expressao.erase(remove(this->expressao.begin(), this->expressao.end(), ' '), this->expressao.end());
}
