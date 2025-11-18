#include <iostream>
#include "bancoPrototipos.hpp"

int main()
{

	Banco banco;
	int numAux;
	std::string titAux;
	double salAux;

	Conta* c;

	int opcao = 0, sair = -1;

	//Login/SignUp caso o usuario tenha ou nao uma conta
	do
	{
		std::cout << "\n =====  Banco Simples  =====\n";
		std::cout << " ----->  Login/Sign Up  \n\n";
		std::cout << "1. Criar conta\n";
		std::cout << "2. Acessar conta\n";
		std::cout << "3. Sair\n";
		std::cout << "Escolha: ";
		std::cin >> opcao;

		switch (opcao)
		{
		case 1:
			std::cout << "\nNumero da nova conta: ";
			std::cin >> numAux;

			std::cout << "\nTitular da nova conta: ";
			std::cin >> titAux;

			banco.criarConta(numAux, titAux);
			c = banco.buscarConta(numAux);

			//Caso nao seja null
			if (c)
				sair = 0;

			break;

		case 2:
			std::cout << "\nNumero da conta: ";
			std::cin >> numAux;

			c = banco.buscarConta(numAux);

			//Caso nao seja null
			if (c)
				sair = 0;

			break;

		default:
			return 0;	//caso queira sair
		}
	} while (sair == -1);


	//Ao acessar sua conta
	do
	{
		std::cout << "\n =====  Banco Simples  =====\n";
		std::cout << " ----->  Sua Conta  \n\n";
		std::cout << "1. Depositar\n";
		std::cout << "2. Sacar\n";
		std::cout << "3. Ver saldo\n";
		std::cout << "4. Mostrar extrato\n";
		std::cout << "5. Listar contas do Banco\n";
		std::cout << "6. Sair\n";
		std::cout << "Escolha: ";
		std::cin >> opcao;

		switch (opcao)
		{
		case 1:
			std::cout << "\nValor do deposito: ";
			std::cin >> salAux;

			c->depositar(salAux);

			break;

		case 2:
			std::cout << "\nValor do saque: ";
			std::cin >> salAux;

			c->sacar(salAux);

			break;

		case 3:
			std::cout << "\nSeu saldo eh de " << c->getSaldo() << std::endl;

			break;

		case 4:
			c->mostrarExtrato();

			break;

		case 5:
			banco.listarContas();

			break;

		default:
			std::cout << "Escolha uma opcao entre os numeros da tela" << std::endl;

		}
	
	} while (opcao != 6);



	return 0;
}