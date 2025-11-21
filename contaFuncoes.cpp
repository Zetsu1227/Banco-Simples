#include "contaPrototipos.hpp"

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
