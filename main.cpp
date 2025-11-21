#pragma once
#include "organizePrototipos.hpp"

int main()
{

	Banco banco;
	Conta* c{};

	//Nome do arquivo que contem os dados
	std::string backupBanco = "backup.txt";

	//Carrega os dados
	banco.carregarDados(backupBanco);

	//Primeira chamada para o login
	loginInicio(banco, c);

	//Salva os dados	-> É PRECISO usar "Sair" para poder salvar os dados
	banco.salvarDados(backupBanco);


	return 0;
}