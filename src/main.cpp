#include <iostream>
#include "../include/iemanja.h"
#include <fstream> /**< Inclusão da lib fstream*/
#include <string>

using namespace std;
using std::fstream;
using std::ofstream;
using std::ifstream;

int main(){
	//define variável de leitura da linha do arquivo
	string expressao;

	int linha = 1;

	//declara input de abertura de arquivo
	fstream arquivo_expressoes;

	//abre o arquivo - PERGUNTAR AO PROFESSOR SOBRE COMO ELE IRÁ PEGAR O ARQUIVO
	arquivo_expressoes.open("arquivo_expressoes.dat");

	//verifica se o arquivo foi aberto com sucesso
	if (arquivo_expressoes.is_open()){
		//verifica se ainda há linhas para leituras
		//e recupera a linha e adiciona na variavel de expressão
		while (getline(arquivo_expressoes, expressao)) {
		 Iemanja * verificador_expressao = new Iemanja(expressao, linha);
		 if(verificador_expressao->validacoes()){
		 	verificador_expressao->extrair_componentes();
			verificador_expressao->converter_pos_fixa();
			verificador_expressao->avaliar_pos_fixa();
			std::cout << "Sucesso linha: "<< linha << " | Resultado: " << verificador_expressao->get_resultado() << endl;
		 }else{
		 	cout <<"Erro linha: " << linha << " | expressão: " << verificador_expressao->get_expressao()
		 	<< " | código de erro " << verificador_expressao->get_codido_erro() 
		 	<< " | " << verificador_expressao->get_erro_descricao() << endl;
		 }

		 //cout << verificador_expressao->get_linha() << endl;

		 linha++;	
		}	
	}
	else
		cout << "Erro ao abrir arquivo" << endl;
	
	return 0;
}

