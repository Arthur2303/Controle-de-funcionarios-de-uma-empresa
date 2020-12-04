#ifndef GERENCIA_H
#define GERENCIA_H

//#include "Usuario.h"
#include "Pessoa.h"


class Gerencia : public Pessoa{
private:
    string user;
    string senha;

public:

	void contratarFunc();
	void demitirFunc();
	void salvarLista();
	void listaFunc();
	void imprimirFunc();
	void imprimirDesa();
	void funcNome();
	void funcCPF();
	void funcMatricula();
	void showFunc();
	void showFuncDep();
	void showFuncSer();
	void showFuncAlf();
	void aumentoSalarial();
	void aumentoFunc();
	void aumentoDep();
	void aumentoSer();

	// FUNÇÕES PARA INSERIR DADOS PESSOAIS DO GERENTE:
	void setUser(string);
	void setSenha(string);

	string getUser() const;
	string getSenha() const;

};

#endif