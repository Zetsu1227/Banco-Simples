#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

//Conta -> informações essenciais da conta do aplicativo/banco
//      -> funções principais de organização e gestão desses dados

class Conta
{

private: 

	int numero; //numero da conta
	std::string titular; //nome do usuario
	double saldo; // seu saldo
	std::vector<std::string> historico; //contem todas as acoes de deposito e de saque

public:

    //construtor da conta
    Conta(int numeroConta, std::string titularConta, double saldoConta);

    void depositar(double valor);  //depositar determinado valor
    bool sacar(double valor);   // sacar determinado valor


    double getSaldo() const; //retorna o saldo atual
    int getNumero() const; //retorna o numero da conta
    std::string getTitular() const; //retorna o nome do usuário
    void mostrarExtrato() const; //mostra o extrato do histórico
    
    //Para evitar dúvidas -> const(s) usados apenas para evitar erros lógicos acidentais ao mexer com os códigos
    
    std::string serializar() const;  // transforma todos os dados de conta em uma string
    static Conta desserializar(const std::string& linha); // transforma uma string que contem os dados da conta em uma Conta

};

