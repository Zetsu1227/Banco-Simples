#include "bancoPrototipos.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//Cria uma conta e coloca no banco de dados
void Banco::criarConta(int numero, std::string titular)
{
	//Inicializa a conta com suas informacoes
	Conta c(numero, titular, 0);

	//Adiciona na lista das contas
	contas.push_back(c);
	
}

//Busca uma conta no banco de dados por meio de seu numero
Conta* Banco::buscarConta(int numero)
{
	for (Conta& ci : contas)
	{
		if (ci.getNumero() == numero)
			return &ci;	//retorna o endereço da conta
	}

	//se não achar
	std::cout << "\nConta nao encontrada!" << std::endl;
	return nullptr;
}

//Lista todas as contas do banco de dados
void Banco::listarContas() const
{
	int i = 1;

	std::cout << "Lista das Contas\n\n" << std::endl;

	for (const Conta& ci : contas)
	{
		std::cout << i << ". Titular: " << ci.getTitular() << std::endl;
		i++;
	}
}

//Salva o banco de dados em arquivo .txt dado pelo caminho
void Banco::salvarDados(const std::string& caminho)
{
	//Cria/sobrescrever o arquivo
	std::ofstream arq(caminho);

	if (!arq)
		std::cout << "Erro ao abrir o arquivo em salvarDados" << std::endl;
	else
	{
	
		//Fiz separando por ; para facilitar a identificacao dos dados
		for (const Conta& ci : contas)
			arq << ci.getNumero() << ";" << ci.getTitular() << ";" << ci.getSaldo() << "\n";
	}

	arq.close();
	std::cout << "Dados salvos!" << std::endl;

}

//Carrega dados de um .txt por meio de seu caminho; assim, coloca as contas dadas no banco de dados
void Banco::carregarDados(const std::string& caminho)
{
	//ler arquivo
	std::ifstream arq(caminho);

	int num;
	std::string tit;
	double sal;


	if (!arq)
		std::cout << "Erro ao abrir o arquivo em carregarDados" << std::endl;
	else
	{
		
		std::string linha;

		while (std::getline(arq, linha))
		{
			std::stringstream ss(linha);
			std::string parte;


			// le int ate o primeiro ';'
			std::getline(ss, parte, ';');
			num = std::stoi(parte);

			// le string ate o proximo ';'
			std::getline(ss, tit, ';');

			// le double ate o fim da linha
			std::getline(ss, parte, ';');
			sal = std::stod(parte);


			//Inicializa a conta
			Conta c1(num, tit, sal);

			//Coloca no banco de dados
			contas.push_back(c1);
		}
	}
	
	arq.close();
	std::cout << "Dados carregados!" << std::endl;

}

