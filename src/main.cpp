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
		while (!arquivo_expressoes.eof())
		{
		 //recupera a linha e adiciona na variavel de expressão 	
		 getline (arquivo_expressoes, expressao);

		 Iemanja * verificador_expressao = new Iemanja(expressao, linha);
		 verificador_expressao->validacoes();

		 //cout << verificador_expressao->get_linha() << endl;

		 linha++;	
		}	
	}
	else
		cout << "Erro ao abrir arquivo" << endl;
	
	return 0;
}

