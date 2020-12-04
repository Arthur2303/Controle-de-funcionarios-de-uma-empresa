#include "Pessoa.h"

Pessoa::Pessoa()
{
    nomePessoa = "";
    CPF = "";
    idade = 0;
    sexo = 0;

    endereco.rua = "";
    endereco.numero = 0;
	endereco.bairro = "";
	endereco.CEP=0;
	endereco.cidade="";

	data.dia = 0;
	data.mes = 0;
	data.ano = 0;
}

Pessoa::Pessoa(const string &nome, const string &cpf, const int &idadeValor, bool sexoValor, Endereco endereco_auxi, Data data_auxi){
    setNome(nome); // deve validar
    setCPF(cpf); // deve validar
    setIdade(idadeValor); // deve validar
    setSexo(sexoValor); // deve validar

    endereco = endereco_auxi;
    data = data_auxi;
}

// configurar o nome da pessoa:
void Pessoa::setNome(const string &nome)
{
    nomePessoa = nome; // falta validar
}

// configurar o cpf da pessoa:
void Pessoa::setCPF(const string &cpf)
{
    CPF = cpf; // falta validar
}

// configura a idade da pessoa:
void Pessoa::setIdade(const int &idadeValor)
{
    idade = idadeValor;
}

// configurar o idade da pessoa:
void Pessoa::setSexo(bool sexoValor)
{
    sexo = sexoValor;
}

// retornar o nome da Pessoa:
string Pessoa::getNome(void) const
{
    return nomePessoa;
}

// retornar o cpf da pessoa:
string Pessoa::getCPF(void) const
{
    return CPF;
}

// retornar o idade da Pessoa:
int Pessoa::getIdade(void) const
{
    return idade;
}

// retornar o sexo da Pessoa:
bool Pessoa::getSexo(void) const
{
    return sexo;
}

void Pessoa::setRua(string ruaAux)
{
    endereco.rua = ruaAux;
}

void Pessoa::setNumero(int numerAux)
{
    endereco.numero = numerAux;
}

void Pessoa::setBairro(string bairroAux)
{
    endereco.bairro = bairroAux;
}

void Pessoa::setCEP(int cepAux)
{
    endereco.CEP = cepAux;
}

void Pessoa::setCidade(string cidadeAux)
{
    endereco.cidade = cidadeAux;
}

void Pessoa::setDia(int diaAux)
{
    data.dia = diaAux;
}

void Pessoa::setMes(int mesAux)
{
    data.mes = mesAux;
}

void Pessoa::setAno(int anoAux)
{
    data.ano = anoAux;
}

Endereco Pessoa::getEndereco(void) const
{
    return endereco;
}

Data Pessoa::getData(void) const
{
    return data;
}
