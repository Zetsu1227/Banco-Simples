#include "bancoPrototipos.hpp"


void loginInicio(Banco& banco, Conta*& c);	// Menu inicial -> Fazer login numa conta já existente ou criar uma nova

int contaAcessada(Banco& banco, Conta*& c); //Acessa sua conta -> manipula ela, -> volta pro menu inicial

void paiAcesso(Banco& banco, Conta*& c); //Funcao auxiliar para fazer a troca do acesso da conta para o menu inicial
