#include "Gerencia.h"
#include "Empresa.h"
#include "Funcionario.h"
#include "Pessoa.h"
#include <algorithm>

using namespace std;

Empresa empresa;
Funcionario funcionario;


void Gerencia::contratarFunc() {
	string nome, cpf, servico, matricula, rua, bairro, cidade;
	int idade, departamento, dia, mes, ano, numero, cep;
	bool sexo, condicao;
	double salario;

// INSERIR DADOS DOS FUNCIONARIOS:
	cout << "Digite o nome do funcion�rio: ";
	cin.sync();
	getline(cin, nome);
	funcionario.setNome(nome);
    system("cls");

	cout << "Digite o cpf de " << funcionario.getNome() << ": ";
	cin.sync();
	getline(cin, cpf);
	funcionario.setCPF(cpf);
    system("cls");

	cout << "Digite a matr�cula de " << funcionario.getNome() << ": ";
	cin.sync();
	getline(cin, matricula);
	funcionario.setMatricula(matricula);
    system("cls");

	cout << "Digite a idade de " << funcionario.getNome() << ": ";
	cin >> idade;
	funcionario.setIdade(idade);
    system("cls");

	cout << "Digite o sexo de MASCULINO(0) ou FEMININO(1) " << funcionario.getNome() << ": ";
	cin >> sexo;
	funcionario.setSexo(sexo);

    condicao == false; //INICIALIZA CONDICAO
    while(condicao == false)
    {
        system("cls");
        cout << "DEPARTAMENTOS" << endl << endl;
        cout << "1 - Departamento de Mec�nica." << endl
             << "2 - Departamento de Administracao." << endl
             << "3 - Departamento de Servi�os Gerais." << endl
             << "4 - Departamento de Vendas." << endl;
        cout << endl << "Digite o n�mero do departamento do funcion�rio " << funcionario.getNome() << ": ";
        cin >> departamento;

        // VERIFICA SE O VALOR INSERIDO � UM INTEIRO
        if(cin.fail())
        {
            cout << "O valor inserido inv�lido!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            system("pause");
        }

        // VERIFICA SE USU�RIO DIGITOU DENTRO DO INTERVALO INTEIROS
        else if (departamento < 1 || departamento > 4)
        {
            cout << "Valores devem ser entre 1 e 4." << endl;
            system("pause");
        }

        // VERIFICA SE USU�RIO DIGITOU SOMENTE INTEIROS
        else if (departamento >= 1 &&  departamento <= 4)
        {
            funcionario.setDepartamento(departamento);
            condicao = true;
        }
    }

    system("cls");

	cout << endl << "Digite o servico de " << funcionario.getNome() << ": ";
	cin.sync();
	getline(cin, servico);
	funcionario.setServico(servico);
    system("cls");

	cout << "Digite o sal�rio de " << funcionario.getNome() << ": ";
	cin >> salario;
	funcionario.setSalario(salario);
    system("cls");

	// INSERIR ENDERE�O DO FUNCION�RIO
	system("cls");
	cout << endl << "Endere�o do funcion�rio" << endl;
	cout << "Digite o nome da rua: ";
	cin.sync();
	getline(cin, rua);
	funcionario.setRua(rua);

	cout << "Digite o n�mero da resid�ncia: ";
	cin >> numero;
	funcionario.setNumero(numero);

	cout << "Digite bairro: ";
	cin.sync();
	getline(cin, bairro);
	funcionario.setBairro(bairro);

	cout << "Digite o CEP: ";
	cin >> cep;
	funcionario.setCEP(cep);

	cout << "Digite a cidade: ";
	cin.sync();
	getline(cin, cidade);
	funcionario.setCidade(cidade);

	// INSERIR DATA DO FUNCION�RIO
	condicao = false; // incializa condicao
	while(condicao == false) { // validar a data - verifica se o valores s�o corretos
		cout << endl << "Data de admiss�o do funcion�rio" << endl;
		cout << "Dia: ";
		cin >> dia;
		cout << "M�s: ";
		cin >> mes;
		cout << "Ano: ";
		cin >> ano;

		// se os valores estiverem corretos, o programa sai do while
		if((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1990 && ano <= 2020)) {
			condicao = true;
			funcionario.setDia(dia);
			funcionario.setMes(mes);
			funcionario.setAno(ano);
			break;
		}
		cout << "Os valores da datas est�o incorretos." << endl
			 << "Digite novamente." << endl;
	}

	funcionario.setStatus(true); // muda status para ativo

	if(empresa.inserirFuncionario(funcionario)) // IR� ADCIONAR OBJETO NO ARRAY DE FUNCINARIOS NA CLASSE EMPRESA
		cout << "Pessoa cadastrada com sucesso!" << endl;
	else
		cout << "O cadastro n�o pode ser realizado!" << endl;
}

// Demitir funcionario por CPF.
void Gerencia::demitirFunc()
{
    string cpf, opc = "2";

    cout << "Informe o CPF do funcionario que deseja demitir: ";
        cin.ignore();
    getline(cin, cpf);
    system("cls");

    if(empresa.imprimirFuncCPF(cpf) == true)
    cin >> opc;
    else
    {
        cout << "Nenhum funcionario com este CPF." << endl << endl;
    }

    if(opc == "1")
        empresa.demitirFuncionarioCPF(cpf);
    if(opc == "2")
        cout << endl;
    if(opc != "1" && opc != "2")
        cout << "Opcao invalida!" << endl;
}

void Gerencia::salvarLista() {
	if(empresa.salvarLista())
		cout << "A lista est� salva." << endl;
	else
		cout << "N�o foi poss�vel salvar a lista." << endl;
}

void Gerencia::listaFunc() {
	if(funcionario.getStatus() == 1)
	cout << endl << setw(90) << "LISTA DE FUNCION�RIOS NA ORDEM QUE FORAM INSERIDAS NO ARQUIVO." << endl << endl << endl;
	empresa.imprimirLista(); // IMPRIMIR DADOS DOS FUNCION�RIOS
}

// IMPRIMIR FUNCIONARIOS DESATIVADOS
void Gerencia::imprimirDesa()
{
    cout << left << setw(40) << "NOME FUNCION�RIO" << setw(22) << "CPF" << setw(22) << "MATR�CULA" << setw(20) << "SERVICO" << "SAL�RIO R$"<< endl;
    cout << setfill('-');
    cout << setw(115) << "-" << endl;
    cout << setfill(' ');

    empresa.imprimirDeligados();
}

void Gerencia::funcNome() {
	string nome;
	cout << setw(70) << "PROCURAR FUNCION�RIO POR NOME." << endl << endl;
	cout << "Digite o nome do funcion�rio para pesquisa: ";
	cin.ignore();
	getline(cin, nome);

	if(!empresa.pesquisarFuncionario(nome))
		cout << "O nome pesquisado n�o exite na lista." << endl << endl;
}

void Gerencia::funcCPF() {
	string cpf;
	cout << endl << setw(75) << "PROCURAR FUNCION�RIO POR CPF." << endl << endl << endl;
	cout << "Digite o cpf do funcion�rio para pesquisa: ";
	cin.ignore();
	getline(cin, cpf);

	if(!empresa.pesquisarFuncionarioCPF(cpf)) // Se o cpf n�o for encontrado
		cout << "O cpf pesquisado n�o existe na lista." << endl << endl;
}

void Gerencia::funcMatricula() {

	string matricula;
	cout << endl << setw(75) << "PROCURAR FUNCION?RIO POR MATR�CULA." << endl << endl << endl;
	cout << "Digite o n�mero da matr�cula: ";
	cin >> matricula;

	if(!empresa.pesquisarFuncionarioMat(matricula))
		cout << "A matr?cula pesquisada n?o existe: " << endl << endl;
}

void Gerencia::imprimirFunc() {
	int opc;
	cout << "1 - Pesquisar funcion�rio por Nome." << endl
         << "2 - Pesquisar funcion�rio por CPF." << endl
         << "3 - Pesquisar funcion�rio por Matr�cula." << endl
         << "4 - Retornar para o menu principal." << endl;
	// OBTER OP�AO SELECIONADA:
	cout << endl << "Digite a op��o: ";
	cin >> opc;
	switch(opc) {

	case 1:
		funcNome();
		break;

	case 2:
		funcCPF();
		break;

	case 3:
		funcMatricula();
		break;
	case 4:
		cout << "Voltando..." << endl;
		break;

	default:
		cout << "Op��o inv�lida!!!" << endl;
		break;
	}
}

void Gerencia::showFuncDep() {
	int opcaoDep;
	cout << endl << setw(75) << "IMPRIMIR FUNCIONARIOS POR DEPARTAMENTO." << endl << endl;
	cout << "Digite o n�mero do departamento." << endl;
	cout << "1 - Departamento de Mec�nica." << endl
	<< "2 - Departamento de Administra��o." << endl
	<< "3 - Departamento de Servi�os Gerais." << endl
	<< "4 - Departamento de Vendas." << endl
	<< "Digite sua op��o: ";
	cin >> opcaoDep;

	if(opcaoDep >= 1 && opcaoDep <= 4) {
		system("cls");
		empresa.imprimirFuncDep(opcaoDep);
	} else {
		cout << "Op��o de departamento inv�lida!" << endl;
	}
}

void Gerencia::showFuncSer() {
	string servico;
	cout << endl << setw(80) << "LISTA DE FUNCION�RIOS POR SERVICO." << endl << endl << endl;
	cout << "Digite o servico: ";
	cin.sync();
	getline(cin, servico);
	cout << endl;

	empresa.imprimirFuncServ(servico);
}

void Gerencia::showFuncAlf() {
	cout << endl << setw(82) << "LISTA DE FUNCION�RIOS NA ORDEM ALFAB�TICA." << endl << endl << endl;
	empresa.imprimirListaOrdenadaNome(); // IMPRIMIR DADOS DOS FUNCION?RIOS
}

void Gerencia::showFunc() {
	int opc;
	cout << "1 - Imprimir funcion�rio por Departamento." << endl
         << "2 - Imprimir funcion�rios em ordem de servico." << endl
         << "3 - Imprimir funcion�rios em ordem alfab�tica." << endl
         << "4 - Retornar para o menu principal" << endl;

	cout << endl << "Digite a op��o: ";
	cin >> opc;
	switch(opc) {

	case 1:
		showFuncDep();
		break;

	case 2:
		showFuncSer();
		break;

	case 3:
		showFuncAlf();
		break;
	case 4:
		cout << "Voltando..." << endl;
		break;
	default:
		cout << "Op��o inv�lida!!!" << endl;
		break;
	}
}

void Gerencia::aumentoFunc() {
	string nome, cpf;
	int percentual;
	short opcaoAumento;
	cout << setw(40) << " " << "AUMENTO SAL�RIAL DO FUNCION�RIO." << endl << endl << endl;
	cout << "Selecionar funcion�rio pelo NOME (1)" << endl
         << "Selecionar funcion�rio pelo CPF  (2)" << endl;
	cin >> opcaoAumento;

	if (opcaoAumento == 1)
	{
		cout << endl << "Digite o nome do funcion�rio: ";
		cin.sync();
		getline(cin, nome);

		cout << endl << "Digite o percentual de aumento: ";
		cin >> percentual;

		system("cls");
		if(!empresa.aumentoFuncionarioNome(nome, percentual))
			cout << endl << "Esse nome n�o existe na lista ou funcion�rio est� inativo!" << endl << endl;
	}
	else if (opcaoAumento == 2) {
		cout << endl << "Digite o CPF do funcion�rio: ";
		cin.sync();
		getline(cin, cpf);

		cout << endl << "Digite o percentual de aumento: ";
		cin >> percentual;

		system("cls");
		if(!empresa.aumentoFuncionarioCPF(cpf, percentual))
			cout << endl << "Esse cpf n�o existe na lista ou funcion�rio est� inativo!" << endl << endl;
	} else
		cout << endl << "Op��o inv�lida!" << endl << endl;
}

void Gerencia::aumentoDep() {
	int percentual;
	short opcaoDepartamento;
	cout << endl << setw(38) << " " << "AUMENTO SAL?RIA POR DEPARTAMENTO." << endl << endl << endl;
	cout << "Digite o n?mero do departamento." << endl;
	cout << "1 - Departamento de Mec�nica." << endl
	<< "2 - Departamento de Administra��o." << endl
	<< "3 - Departamento de Servi�os Gerais." << endl
	<< "4 - Departamento de Vendas." << endl
	<< "Digite sua op��o: ";
	cin >> opcaoDepartamento;

	cout << endl << "Digite o percentual de aumento: ";
	cin >> percentual;

	if (opcaoDepartamento >= 1 && opcaoDepartamento <= 4) {
		system("cls");
		empresa.aumentoDepartamento(opcaoDepartamento, percentual);
	} else
		cout << endl << "Op��o de departamento inv�lido!" << endl << endl;
}

void Gerencia::aumentoSer() {
	string servico;
	int percentual;
	cout << endl << setw(40) << " " << "AUMENTO SAL�RIO POR SERVI�O." << endl << endl << endl;

	cout << "Digite o servico para o aumento: ";
	cin.sync();
	getline(cin, servico);

	cout << endl << "Digite o percentual de aumento: ";
	cin >> percentual;

	empresa.aumentoServico(servico, percentual);
}

void Gerencia::aumentoSalarial() {
	int opc;
	cout << "1 - Aumento sal�rial para o funcion�rio." << endl
         << "2 - Aumento sal�rial para departamento." << endl
         << "3 - Aumento sal�rial por servi�o." << endl
         << "4 - Retornar para o menu principal" << endl;
	cout << endl << "Digite a op��o: ";
	cin >> opc;
	switch(opc) {

	case 1:
		aumentoFunc();
		break;

	case 2:
		aumentoDep();
		break;

	case 3:
		aumentoSer();
		break;
	case 4:
		cout << "Voltando..." << endl;
		break;
	default:
		cout << "Op��o inv�lida!!!" << endl;
		break;
	}
}

// FUNCAO QUE CONFIGURA USER PARA O Gerencia
void Gerencia::setUser(string usuarioId)
{
    user = usuarioId;
}

// FUNCAO QUE CONFIGURA SENHA PARA GERENTE
void Gerencia::setSenha(string senhaAux)
{
    senha = senhaAux;
}

// FUN��O QUE RETORNA USER DO GERENTE
string Gerencia::getUser() const
{
    return user;
}

// FUNCAO QUE RETORNA SENHA DO Gerencia
string Gerencia::getSenha() const
{
    return senha;
}
