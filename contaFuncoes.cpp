#include "contaPrototipos.hpp"
#include <iostream>
#include <sstream>

//Construtor -> ao ser chamado é realizado as ações:
Conta::Conta(int numeroConta, std::string titularConta, double saldoConta)
{
	//inicializa a conta
	numero = numeroConta;
	titular = titularConta;

	saldo = saldoConta;
	historico = {};
}

//deposita determinado valor no saldo da conta
void Conta::depositar(double valor)
{
	saldo += valor;
	historico.push_back("Deposito de " + std::to_string(valor));
}


// verifica se é possível sacar, se sim diminui do saldo esse valor
bool Conta::sacar(double valor)
{
	//foi possivel realizar o saque
	if (saldo >= valor)
	{
		saldo -= valor;
		historico.push_back("Saque de " + std::to_string(valor));	//transforma de double para string e depois coloca no vetor

		return true;
	}


	//else -> não há saldo suficiente para sacar o valor escolhido
	
	std::cout << "\nSaldo Insuficiente!\n";
	return false;
}

//retorna o saldo atual da conta
double Conta::getSaldo() const
{
	return saldo;
}

//retorna o numero do banco do usuário
int Conta::getNumero() const
{
	return numero;
}

//retorna o nome do titular
std::string Conta::getTitular() const
{
	return titular;
}

// mostra o extrato da conta --> isso é, todos os depósitos e saques feitos
void Conta::mostrarExtrato() const
{
	std::cout << "Extrato da Conta:" << std::endl;
	std::cout << "// ";

	for (const std::string& i : historico) //"const var&" acaba sendo mais eficiente por não criar uma cópia para cada
		std::cout << i << " // ";

	std::cout << "" << std::endl;
}

//transforma os dados da conta em uma string e retorna uma linha contendo todas as informacoes
std::string Conta::serializar() const
{
	std::string linha = std::to_string(numero) + ";" + titular + std::to_string(saldo);

	for (const std::string& h : historico)
		linha += ";" + h;

	return linha;
}

//converte de texto para objeto Conta a partir de uma linha de texto contendo essa conta
Conta Conta::desserializar(const std::string& linha)
{

	std::stringstream ss(linha); //pra ler linha

	std::string pega; //pega partes da linha
	std::vector<std::string> partes; //armazena as partes salvas

	//separa cada parte por meio do ';' -> armazena num vetor
	while (std::getline(ss, pega, ';'))
		partes.push_back(pega);

	int numConta = std::stoi(partes[0]); //transforma de string para int a primeira parte que contem o numero da conta
	std::string titConta = partes[1]; //copia a string que contem o titular da conta
	double salConta = std::stod(partes[2]); //transforma de string para double a terceira parte que contem o saldo da conta

	//inicializa os valores pegos da linha no construtor
	Conta contaLinha(numConta, titConta, salConta);

	//Coloca o extrato da linha na conta desserializada
	//é a partir do 3 por causa da ordem
	for (int i = 3; i < (int)partes.size(); i++)
		contaLinha.historico.push_back(partes[i]);


	return contaLinha;
}


