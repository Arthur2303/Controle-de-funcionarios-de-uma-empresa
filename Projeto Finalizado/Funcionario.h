#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.h"

class Funcionario: public Pessoa
{
	private:
		int departamento;
        string matricula;
        string servico;
        double salario;
        bool status; // 0-INATIVO | 1-ATIVO

	public:
		Funcionario();
		Funcionario(const string&, const string&, const int&, bool , Endereco , Data , int, string, string, double, bool);


		//MÉTODOS SETTERS//
        void setDepartamento(const int&);
        void setMatricula(const string&);
        void setServico(const string&);
        void setSalario(const double&);
        void setStatus(bool);

        //MÉTODOS GETTERS//
        int getDepartamento() const;
        string getMatricula() const;
        string getServico() const;
        double getSalario() const;
        bool getStatus() const;

        void imprimirFuncionarios(); // IMPRIMIR TODOS FUNCIONÁRIOS DA EMPRESA
        void imprimirDadosFuncionario(); // IMPRIME DADOS PESSOAIS DO FUNCIONARIO
        void imprimirFuncionarioDep(); // IMPRIME TODOS FUNCIONÁRIOS DE UM DEPARTAMENTO
        void imprimirFuncDesligados(); // IMPRIME TODOS OS FUNCIONARIOS DELIGADOS DA EMPRESA

        //void imprimePessoa(void) const;
};

#endif // FUNCIONARIO_H
