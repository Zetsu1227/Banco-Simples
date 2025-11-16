#pragma once
#include <vector>
#include "contaPrototipos.hpp"

class Banco 
{
private:

    std::vector<Conta> contas;

public:

    //cria uma conta do zero, inicializando apenas com o numero do conta e o nome do usuário
    void criarConta(int numero, std::string titular);

    //Busca uma conta a partir do seu numero
    Conta* buscarConta(int numero);

    //Lista todas as contas existentes
    void listarContas() const;


    // salva e/ou carrega dados de um arquivo .txt acessado com o seu nome(caminho)
    void salvarDados(const std::string& caminho);
    void carregarDados(const std::string& caminho);
};
