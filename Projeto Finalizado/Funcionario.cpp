#include "Funcionario.h"

Funcionario::Funcionario():Pessoa(){
	departamento = 0;
    matricula = "";
    servico = "";
    salario = 0.0;
    status = 0;
}
Funcionario::Funcionario(const string& nome, const string& cpf , const int& ida, bool sex, Endereco endereco_auxi, Data data_auxi , int dep, string mat, string ser, double sal, bool sta)
          :Pessoa(nome, cpf, ida, sex, endereco_auxi, data_auxi){

    setDepartamento(dep);
    setMatricula(mat);
    setServico(ser);
    setSalario(sal);
    setStatus(sta);
}

// CONFIGURAR DEPARTAMENTO:
void Funcionario::setDepartamento(const int& dep)
{
    departamento = (dep < 0) ? 0 : dep; // valida departamento
}

//CONFIGURA MATRICULA:
void Funcionario::setMatricula(const string& mat)
{
    matricula = mat;
}

// CONFIGURAR SERVICO:
void Funcionario::setServico(const string& serv)
{
    servico = serv;
}

// CONFIGURAR SAL�RIO:
void Funcionario::setSalario(const double& sal)
{
    salario = (sal < 0.0) ? 0.0 : sal; // valida salario
}

// COFIGURAR STATUS:
void Funcionario::setStatus(bool stat)
{
    status = stat;
}

// RETORNA DEPARTAMENTO:
int Funcionario::getDepartamento() const
{
    return departamento;
}

// RETRONA MATRICULA
string Funcionario::getMatricula() const
{
    return matricula;
}

// RETORNA SERVICO:
string Funcionario::getServico() const
{
    return servico;
}

// RETORNA SAL�RIO:
double Funcionario::getSalario() const
{
    return salario;
}

// RETORNA STATUS:
bool Funcionario::getStatus() const
{
    return status;
}

// FUN��O QUE VAI IMPRIMIR DADOS GERAIS DO FUNCION�RIO:
void Funcionario::imprimirFuncionarios()
{
    // Formato da impress�o dos dados:
    if(getStatus() == true)
        cout << left << setw(40) << getNome() << setw(22) << getCPF() << left << setw(22) << getMatricula() << left << setw(9) << left << setw(22) << getServico() << left << setw(9) << left << setw(2) << getSalario() << endl;
}

// FUN��O QUE VAI IMPRIMIR DADOS ESPEC�FICOS DO FUNCION�RIO:
void Funcionario::imprimirDadosFuncionario()
{
    // FORMATO DO CABECALHO NO PROMPT:
    cout <<endl;
    cout << left << setw(40) << "NOME FUNCION�RIO" << setw(26) << "CPF" << setw(16) << " SEXO" << setw(16) << "IDADE" << "STATUS" << endl;
    cout << setfill('-');
    cout << setw(110) << "-" << endl;
    cout << setfill(' ');

    // Formato da impress�o dos dados:
    cout << left << setw(40) << getNome() << setw(26) << getCPF() << setw(17);
    (getSexo() == 1) ? cout << "FEMININO" : cout << "MASCULINO";
    cout << getIdade() << right << setw(18);
    (getStatus() == 1) ? cout << "ATIVO" : cout << "INATIVO";

    cout << endl << endl;
    cout << "ENDERE�O DO FUNCION�RIO." << endl;
    cout << "Rua: " << getEndereco().rua << endl
         << "N�mero: " << getEndereco().numero << endl
         << "Bairro: " << getEndereco().bairro << endl
         << "CEP: " << getEndereco().CEP << endl
         << "Cidade: " << getEndereco().cidade << endl;

    cout << endl;
    cout << "DATA DE INCLUS�O DO FUNCION�RIO." << endl;
    cout << "Data: " << getData().dia<<"/"<<getData().mes<<"/"<<getData().ano << endl;
}

// FUNC��O QUE VAI IMPRIMIR DADOS DO FUNCION�RIO PELO DEPARTAMENTO:
void Funcionario::imprimirFuncionarioDep()
{
    // Formato da impress�o dos dados:
    if(getStatus() == true)
        cout << left << setw(40) << getNome() << setw(26) << getCPF() << setw(18) << getMatricula() << setw(18) << getServico() << getSalario() << endl;
}

void Funcionario::imprimirFuncDesligados()
{
	if(getStatus() == false)
        cout << left << setw(40) << getNome() << setw(26) << getCPF() << left << setw(22) << getDepartamento() << setw(9) << getServico() << setw(16) << setprecision(2) << right << fixed << showpoint << getSalario() << endl;
}
