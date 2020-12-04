#include "Empresa.h"
#include "Sobrecarga.h"

// Construtor
Empresa::Empresa()
{
    Funcionario func;
	ifstream arquivo; // Criando um arquivo apenas para leitura.
	arquivo.open("Lista_de_pessoas.txt"); // Abrindo o arquivo de leitura.

	if(arquivo.is_open()) // Verificando se o arquivo foi aberto.
	{
		while(!arquivo.eof()) // Enquanto for diferente de eof(end of file) continue se repetindo.
		{
			arquivo.sync(); // Ignorando o caractere de quebra de linha que está no início de cada objeto.
			arquivo >> func; // Utilizando a sobrecarga do operador >> para inicializar o objeto.
			lista_funcionario.push_back(func); // Adicionando o objeto a lista.
		}
	}
	arquivo.close(); // Fechando o arquivo de leitura.
}

// Construtor default
Empresa::Empresa(const string &nome)
{
    nomeEmpresa = nome;
}

// CONFIGURA NOME DA EMPRESA
void Empresa::setEmpresaNome(const string &nome)
{
    nomeEmpresa = nome;
}

// CONFIGURA CNPJ DA EMPRESA
void Empresa::setCNPJ(const string &cnpj)
{
    CNPJ = cnpj;
}

// RETORNA NOME DA EMPRESA
string Empresa::getEmpresaNome() const
{
    return nomeEmpresa;
}

// RETORNA CNPJ DA EMPRESA
string Empresa::getCNPJ() const
{
    return CNPJ;
}

// FUNCAO PARA VERIFICAR SE JÁ EXISTE UM FUNCIONÁRIO COM O MESMO CPF JÁ CADASTRADO
bool Empresa::inserirFuncionario(Funcionario f)
{
	for(unsigned i(0); i < lista_funcionario.size(); i++)
	{
		// Verificando se já não existe uma pessoa na lista com o mesmo CPF.
		if(lista_funcionario[i].getCPF() == f.getCPF())
			return false;
	}

	lista_funcionario.push_back(f);
	return true;
}

// FUNCAO PARA GRAVAR A LISTA DE FUNCIONARIOS NO DOCUMENTO TEXTO
bool Empresa::salvarLista()
{
	ofstream arquivo; // Criando um arquivo para salvar a lista de objetos.

	/* Utilizando o modo de abertura trunc, que abre e apaga os dados anteriores armazenados nele. Como toda a lista
	foi carregada no vector se utilizassemos o modo de abertura app o arquivo iria ficar com objetos repetidos.*/
	arquivo.open("Lista_de_pessoas.txt", std::ios::trunc);

	if(arquivo.is_open())
	{
		for(unsigned i(0); i < lista_funcionario.size(); i++)
		{
			// Utilizando a sobrecarga do operador << para gravar o objeto no arquivo.
			arquivo << lista_funcionario[i];
		}
		return true;
	}
	else
		return false;

	arquivo.close(); // fecha o arquivo
}

// FUNCÃO PARA PESQUISAR FUNCIONÁRIO PELO NOME//
bool Empresa::pesquisarFuncionario(const string &nome)
{
    unsigned count(0);
    for (unsigned i(0); i < lista_funcionario.size(); i++)
    {
        if(lista_funcionario[i].getNome() == nome)
        {
            lista_funcionario[i].imprimirDadosFuncionario();
            cout << endl;
            return true;
        }
        else
            count++; // Atualiza contador;
    }
    // Caso não encontre o nome do funcionário:
    if(count == lista_funcionario.size())
        return false;
}

// FUNÇÃO PARA PESQUISAR FUNCIONÁRIO POR CPF:
bool Empresa::pesquisarFuncionarioCPF(const string &cpf)
{
    unsigned count(0);
    for (unsigned i(0); i < lista_funcionario.size(); i++)
    {
        if(lista_funcionario[i].getCPF() == cpf)
        {
            lista_funcionario[i].imprimirDadosFuncionario();
            cout << endl;
            return true;
        }
        else
            count++; // Atualiza contador
    }
    if(count == lista_funcionario.size())
        return false;
}

// FUNCAO PARA PESQUISAR FUNCIONARIO POR MATRICULA:
bool Empresa::pesquisarFuncionarioMat(const string &matri)
{
    unsigned count(0);
    for (unsigned i(0); i < lista_funcionario.size(); i++)
    {
        // Verifica se a matricula existe
        if(lista_funcionario[i].getMatricula() == matri)
        {
            lista_funcionario[i].imprimirDadosFuncionario();
            cout << endl;
            return true;
        }
        else
            count++; // Atualiza contador
    }
    return false;
}

// FUNCAO QUE ORDENA FUNCIONARIO POR NOME
void Empresa::imprimirListaOrdenadaNome()
{
    // formato do cabecalho
    cout << left << setw(40) << "NOME FUNCIONÁRIO" << setw(22) << "CPF" << setw(22) << "MATRÍCULA" << setw(20) << "SERVICO" << "SALÁRIO R$"<< endl;
    cout << setfill('-');
    cout << setw(115) << "-" << endl;
    cout << setfill(' ');

    // criar um vector auxiliar para armazenar o nome de todos os funcionarios
    vector<string> aux(lista_funcionario.size());

    for(unsigned i(0); i < lista_funcionario.size(); i++)
    {
        aux[i] = lista_funcionario[i].getNome();
    }

    sort(aux.begin(), aux.end()); // Ordenado a lista auxiliar de nomes em ordem alfabética.

	// Forçando a impressão dos objetos na mesma ordem dos nomes do vector auxiliar.
	unsigned count(1);
	for (unsigned k(0); k < aux.size(); k++)
    {
        for(unsigned i(0); i < lista_funcionario.size(); i++)
        {
            if(aux[k] == lista_funcionario[i].getNome())
            {
                lista_funcionario[i].imprimirFuncionarios(); // objeto chama funcçao de imprimirFuncionarios de funcionário.cpp
                cout << endl;
                count++;
            }
        }
    }
}

// FUNÇÃO QUE IMPRIME LISTA BÁSICA DE TODOS FUNCIONÁRIOS
void Empresa::imprimirLista()
{
    cout << left << setw(40) << "NOME FUNCIONÁRIO" << setw(22) << "CPF" << setw(22) << "MATRÍCULA" << setw(20) << "SERVICO" << "SALÁRIO R$"<< endl;
    cout << setfill('-');
    cout << setw(115) << "-" << endl;
    cout << setfill(' ');

    // Pecorre o vector de objetos para imprimir os valores
    for(unsigned i(0); i < lista_funcionario.size(); i++)
	{
		lista_funcionario[i].imprimirFuncionarios(); // objeto chama funcçao de imprimirFuncionarios de funcionário.cpp
        cout << endl;
	}
	cout << endl;
}

// FUNÇÃO QUE IMPRIME LISTA DE FUNCIONÁRIOS POR DEPARTAMENTO
void Empresa::imprimirFuncDep(const int& dep)
{
    cout << endl << setw(38) << " " << "IMPRIMIR FUNCIONARIOS POR DEPARTAMENTO." << endl << endl;
    cout << left << setw(40) << "NOME FUNCIONÁRIO" << setw(24) << "CPF" << setw(19) << "MATRÍCULA" << setw(18) << "SERVICO" << "SALÁRIO R$"<< endl;
    cout << setfill('-');
    cout << setw(115) << "-" << endl;
    cout << setfill(' ');

    unsigned count(0); // contador
    // Pecorre o vector de objetos para imprimir os valores
    for(unsigned i(0); i < lista_funcionario.size(); i++)
    {
        if(lista_funcionario[i].getDepartamento() == dep)
        {
            lista_funcionario[i].imprimirFuncionarioDep();
            cout << endl;
            count++;
        }
    }
    // Verificar e imprimir quantos funcionários existem no departamento escolhido:
    if (count == 0)
        cout << endl << "Nenhum funcionário nesse departamento!" << endl << endl;
    else
        cout << endl << "Total de funcionários: " << count << endl << endl;
}

// FUNCAO QUE IMPRIME FUNCIONARIOS POR SERVICO
void Empresa::imprimirFuncServ(const string& serv)
{
    // formato do cabecalho
    cout << left << setw(40) << "NOME FUNCIONÁRIO" << setw(22) << "CPF" << setw(22) << "MATRÍCULA" << setw(20) << "SERVICO" << "SALÁRIO R$"<< endl;
    cout << setfill('-');
    cout << setw(115) << "-" << endl;
    cout << setfill(' ');

    unsigned count(0); // contador
    // Pecorre o vecto de objetos para imprimir os valores
    for (unsigned i(0); i < lista_funcionario.size(); i++)
    {
        if(lista_funcionario[i].getServico() == serv)
        {
            lista_funcionario[i].imprimirFuncionarios();
            cout << endl;
            count++;
        }
    }
    // Verificar e imprimir quantos funcionários existem com o servico escolhido:
    if (count == 0)
        cout << endl << "Nenhum funcionário com esse servico!" << endl << endl;
    else
        cout << endl << "Total de funcionários: " << count << endl << endl;
}

// FUNCAO DE IMPRESSAO POR CPF
bool Empresa::imprimirFuncCPF(const string& cpf)
{
    int somador = 0, tamanhoLista = lista_funcionario.size();
    // PROCURA O FUNCIONARIO PELO CPF DIGITADO E IMPRIME SEUS DADOS
    for (int i = 0; i < tamanhoLista; i++)
    {
        if(lista_funcionario[i].getCPF() == cpf)
        {
            cout << left << setw(40) << "NOME FUNCIONÁRIO" << setw(22) << "CPF" << setw(22) << "MATRÍCULA" << setw(20) << "SERVICO" << "SALÁRIO R$"<< endl;
            cout << setfill('-');
            cout << setw(115) << "-" << endl;
            cout << setfill(' ');

            lista_funcionario[i].imprimirFuncionarios();
            lista_funcionario[i].imprimirFuncDesligados();
            cout << endl << "1 - Para confirmar demissão." << endl
                         << "2 - Para retornar ao Menu principal." << endl
                         << "Opcao: ";
            return true;
        }
        else
        {
            somador++; // Atualiza contador
        }
    }

    // CASO NAO EXISTA FUNCIONARIO COM O CPF DIGITADO
    if(somador == tamanhoLista)
        return false;

}

// FUNCAO QUE GERA AUMENTO SALARIAL PELO NOME DO FUNCIONARIO //
bool Empresa::aumentoFuncionarioNome(const string &nome, const double &percentual)
{
    // Rotina para pesquisar o nome na lista
    for (unsigned i(0); i < lista_funcionario.size(); i++)
    {
        if(lista_funcionario[i].getNome() == nome  && lista_funcionario[i].getStatus() == true)
        {
            lista_funcionario[i].setSalario(lista_funcionario[i].getSalario()*(1+(percentual/100))); // calculo do aumento

            // formato do cabecalho
            cout << endl;
            cout << left << setw(40) << "NOME FUNCIONÁRIO" << setw(22) << "CPF" << setw(22) << "MATRÍCULA" << setw(20) << "SERVICO" << "SALÁRIO R$"<< endl;
            cout << setfill('-');
            cout << setw(115) << "-" << endl;
            cout << setfill(' ');

            lista_funcionario[i].imprimirFuncionarios();
            cout << endl;
            return true;
        }
    }
    return false;
}

// FUNCAO QUE GERA AUMENTO SALARIAL PELO CPF DO FUNCIONARIO //
bool Empresa::aumentoFuncionarioCPF(const string &cpf, const double &percentual)
{
    for (unsigned i(0); i < lista_funcionario.size(); i++)
    {
        if(lista_funcionario[i].getCPF() == cpf  && lista_funcionario[i].getStatus() == true) // verifica cpf e status
        {
            lista_funcionario[i].setSalario(lista_funcionario[i].getSalario()*(1+(percentual/100))); // calculo do aumento

            // formato do cabecalho
            cout << endl;
            cout << left << setw(40) << "NOME FUNCIONÁRIO" << setw(22) << "CPF" << setw(22) << "MATRÍCULA" << setw(20) << "SERVICO" << "SALÁRIO R$"<< endl;
            cout << setfill('-');
            cout << setw(115) << "-" << endl;
            cout << setfill(' ');

            lista_funcionario[i].imprimirFuncionarios(); // imprime tabela com os dados basicos do funcionário
            cout << endl;
            return true;
        }
    }
    return false;
}

// FUNCAO QUE GERA AUMENTO SALARIAL PELO DEPARTAMENTO //
void Empresa::aumentoDepartamento(const int &departamento, const double &percentual)
{
    cout << endl << setw(38) << " " << "AUMENTO SALÁRIA POR DEPARTAMENTO." << endl << endl << endl;
    cout << left << setw(40) << "NOME FUNCIONÁRIO" << setw(24) << "CPF" << setw(19) << "MATRÍCULA" << setw(18) << "SERVICO" << "SALÁRIO R$"<< endl;
    cout << setfill('-');
    cout << setw(115) << "-" << endl;
    cout << setfill(' ');

    for (unsigned i(0); i < lista_funcionario.size(); i++)
    {
        if (lista_funcionario[i].getDepartamento() == departamento && lista_funcionario[i].getStatus() == true) // verifica departamento
        {
            lista_funcionario[i].setSalario(lista_funcionario[i].getSalario()*(1+(percentual/100))); // calculo do aumento

            lista_funcionario[i].imprimirFuncionarioDep(); // imprime tabela com os dados funcionário por departamento
            cout << endl;
        }
    }
}

// FUNCAO QUE GERA AUMENTO SALARIAL PELO SERVICO //
void Empresa::aumentoServico(const string &servico, const double &percentual)
{
    // formato do cabecalho
    cout << endl << setw(40) << " " << "AUMENTO SALÁRIA POR SERVIÇO." << endl << endl << endl;
    cout << left << setw(40) << "NOME FUNCIONÁRIO" << setw(22) << "CPF" << setw(22) << "MATRÍCULA" << setw(20) << "SERVICO" << "SALÁRIO R$"<< endl;
    cout << setfill('-');
    cout << setw(115) << "-" << endl;
    cout << setfill(' ');

    unsigned count(0);
    for (unsigned i(0); i < lista_funcionario.size(); i++)
    {
        if (lista_funcionario[i].getServico() == servico)
        {
            lista_funcionario[i].setSalario(lista_funcionario[i].getSalario()*(1+(percentual/100))); // calculo do aumento

            lista_funcionario[i].imprimirFuncionarios(); // imprime tabela com os dados basicos do funcionário
            cout << endl;
        }
        else
            count++;
    }
    if (count == lista_funcionario.size())
        cout << "Esse serviço não existe na lista!" << endl;
}

// FUNCAO DEMITE FUNCIONARIO POR CPF
void Empresa::demitirFuncionarioCPF(const string& cpf)
{
    int somador = 0, tamanhoLista = lista_funcionario.size();
        // METODO PARA DESCOBRIR SE O FUNCIONARIO JA ESTA DESLIGADO
    for (int i = 0; i < tamanhoLista; i++)
    {
        if(lista_funcionario[i].getCPF() == cpf)
        {
            if(lista_funcionario[i].getStatus() == 0)
                cout << endl << "Funcionario informado ja foi desativado da empresa." << endl;
        }
    }

    // METODO PARA DESLIGAR FUNCIONARIO
    for (int i = 0; i < tamanhoLista; i++)
    {
        if(lista_funcionario[i].getCPF() == cpf)
        {
            lista_funcionario[i].setStatus(0);
            cout << endl;
        }
    }
}

void Empresa::imprimirDeligados()
{
	// Pecorre o vector de objetos para imprimir os valores
	for(unsigned i(0); i < lista_funcionario.size(); i++)
	{
		lista_funcionario[i].imprimirFuncDesligados(); // objeto chama funcao de imprimirFuncDesligados de funcioario.cpp
		cout << endl;
	}
}

Empresa::~Empresa()
{
	//salvarLista(); // Salvando lista caso o usuário não se lembre de salvar.
	lista_funcionario.clear(); // limpa o vector de objetos
}
