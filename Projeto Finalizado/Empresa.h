#ifndef EMPRESA_H
#define EMPRESA_H

#include "Funcionario.h"

class Empresa
{
    private:
    string nomeEmpresa;
    string CNPJ;
    vector<Funcionario> lista_funcionario;

    public:
        Empresa();
        Empresa(const string&);
        ~Empresa();

        // SETTERS
        void setEmpresaNome(const string&);
        void setCNPJ(const string&);

        // GETTERS
        string getEmpresaNome() const;
        string getCNPJ() const;

        bool inserirFuncionario(Funcionario);
        bool salvarLista();

        // FUNÇÕES DE BUSCAS //
        bool pesquisarFuncionario(const string&);
        bool pesquisarFuncionarioCPF(const string&);
        bool pesquisarFuncionarioMat(const string&);

        // FUNCOES DE ORDENACAO //
        void imprimirListaOrdenadaNome();

        // FUNCOES DE IMPRIMIR //
        void imprimirLista();
        void imprimirFuncDep(const int&);
        void imprimirFuncServ(const string&);
        bool imprimirFuncCPF(const string&);

        // FUNCOES PARA REAJUSTE SALARIAL //
        bool aumentoFuncionarioNome(const string&, const double&);
        bool aumentoFuncionarioCPF(const string&, const double&);
        void aumentoDepartamento(const int&, const double&);
        void aumentoServico(const string&, const double&);

        // FUNCOES DE DEMISSAO DE FUNCIONARIO E IMPRESSAO
        void demitirFuncionarioCPF(const string &);
        void imprimirDeligados();
};

#endif // EMPRESA_H

